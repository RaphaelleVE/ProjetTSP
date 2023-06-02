//
// Created by mpore on 16/05/2023.
//

#include "LocalSearch.h"
#include "Strategies/Reinsertion.h"
#include "Strategies/Exchange.h"
#include "Strategies/TwoOpt.h"
#include <limits>
#include <random>
#include <algorithm>
#include <fstream>
/**
 * LocalSearch's constructor
 * @param neighborStart
 * @param solution
 */
LocalSearch::LocalSearch(Solution *solution,std::unique_ptr<NeighborStart> &&neighborStart) : neighborStart(std::move(neighborStart)), solutionType(solution){
    originalSolution = solutionType->resolve();
    listNighborStrat.push_back(std::make_unique<Reinsertion>());
    listNighborStrat.push_back(std::make_unique<Exchange>());
    listNighborStrat.push_back(std::make_unique<TwoOpt>());
}

/**
 * Get a better solution than the given one
 * @param solutionTab
 * @param start
 * @return
 */
std::vector<City> LocalSearch::bestImproving(std::vector<City> solutionTab) {

    std::vector<City> bestSolution = solutionTab;
    float bestDist = solutionType->totDist(bestSolution);
    std::cout<< "best : "<< neighborStart.get()->numberOfSolution(solutionTab.size()) ;
    for(int i = 0; i<neighborStart->numberOfSolution(solutionTab.size())-1;i++){

        std::cout<< "best : "<< bestDist ;
        std::vector<City> tryNeighborStrat = neighborStart->generateSolution(bestSolution,i);
        float distNeigbor = solutionType->totDist(tryNeighborStrat);
        if(distNeigbor < bestDist) {
            bestSolution = tryNeighborStrat;
            bestDist = distNeigbor;
        }
    }
    std::cout<< " best solu write : ";
    for(City city : bestSolution){
        std::cout<< city.getId();
    }
    std::cout<< "\n";
    return bestSolution;
}

/**
 * Get a better solution thanks to the local search
 * @param solutionTab
 * @param start
 * @return
 */
std::vector<City> LocalSearch::algoDescent(std::vector<City> solution) {
    std::vector<City> firstSolution = solution;

    float distanceSolution = solutionType->totDist(firstSolution);

    std::vector<City> bestSolution = {};
    float bestDistance = std::numeric_limits<float>::max();

    while (bestDistance > distanceSolution) {
        std::cout<<"\n" <<"\n" << "alog : "<< distanceSolution ;

        bestSolution = firstSolution;
        bestDistance = distanceSolution;

        firstSolution = bestImproving(firstSolution);
        std::cout<< "tit";

        distanceSolution = solutionType->totDist(firstSolution);

        std::cout<<"endwhile";
    }

    return bestSolution;
}

/**
 * Get the first better solution
 * @param solutionTab
 * @return
 */
std::vector<City> LocalSearch::firstImproving(std::vector<City> solutionTab) {
    std::vector<City> bestSolution = solutionTab;
    float bestDist = solutionType->totDist(bestSolution);
    for(int i = 0; i<neighborStart->numberOfSolution(solutionTab.size())-1;i++){
        std::vector<City> tryNeighborStrat = neighborStart->generateSolution(bestSolution,i);
        float distNeigbor = solutionType->totDist(tryNeighborStrat);
        if(distNeigbor < bestDist) {
           return tryNeighborStrat;
        }
    }
    return bestSolution;
}

/**
 * Get the first better and random solution
 * @param solutionTab
 * @return
 */
std::vector<City> LocalSearch::firstRandomImproving(std::vector<City> solutionTab) {
    std::vector<City> bestSolution = solutionTab;
    std::vector<int> randomIndex = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::shuffle(randomIndex.begin(), randomIndex.end(), std::mt19937{std::random_device{}()});
    float bestDist = solutionType->totDist(bestSolution);
    for(int i = 0; i<neighborStart->numberOfSolution(solutionTab.size())-1;i++){
        std::vector<City> tryNeighborStrat = neighborStart->generateSolution(bestSolution,randomIndex[i]);
        float distNeigbor = solutionType->totDist(tryNeighborStrat);
        if(distNeigbor < bestDist) {
            return tryNeighborStrat;
        }
    }
    return bestSolution;
}

std::vector<City> LocalSearch::solutionAgitator(std::vector<City> solution, const int force) {
    std::vector<City> perturbedSolution = solution;

    for (int i = 0; i < force; ++i) {
        std::cout<< "startfor";

        int neighborIndex = rand() % listNighborStrat.size();
        originalSolution = perturbedSolution;
        neighborStart.reset(listNighborStrat[neighborIndex].get());
       //neighborStart.reset(strat.get());
        perturbedSolution = algoDescent(perturbedSolution);

    }

    return perturbedSolution;
}

/**
 * Write the given result in a given file
 * @param result
 */
void LocalSearch::writeAnswerFile( std::vector<City> result) {
    std::ofstream outFile("../test2.txt");

    //pour vider (voir si utile & crée pas de beug si existe pas)
    //std::ofstream.open("result.txt", std::ofstream::out | std::ofstream::trunc);
    //std::ofstream.close();
    std::cout <<  " second write : ";
    for(City city : result){
        std::cout<<city.getId();
        outFile << city.getId() << " ";
    }
    outFile.close();
}


std::vector<City> LocalSearch::localSearchAll(std::vector<City> solution){
    std::vector<City> bestSolution = solution;
    float bestDistance = solutionType->totDist(solution);
    for(std::unique_ptr<NeighborStart>& strat : listNighborStrat){
        neighborStart.reset(strat.get());
        std::vector<City> solution = algoDescent(bestSolution);
        float distSolution = solutionType->totDist(solution);
        if(distSolution<bestDistance){
            bestSolution = solution;
            bestDistance = distSolution;

        }
    }
    return bestSolution;
}

std::vector<City> LocalSearch::localSearchIterate(){
    int i=0;
    std::vector<City> bestSolution = originalSolution;
    while(i<20){

        std::cout<< "\n"<< "\n" << i << "\n";
        bestSolution = localSearchAll(bestSolution);
        std::cout<< "\n"<< "\n" << "agitaotr" << "\n";
        bestSolution = solutionAgitator(bestSolution,5);
        i++;


    }
    writeAnswerFile(bestSolution);
    return bestSolution;
}

