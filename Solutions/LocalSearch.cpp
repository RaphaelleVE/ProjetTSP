//
// Created by mpore on 16/05/2023.
//

#include "LocalSearch.h"
#include <limits>
#include <random>
#include <algorithm>

/**
 * LocalSearch's constructor
 * @param neighborStart
 * @param solution
 */
LocalSearch::LocalSearch(std::unique_ptr<NeighborStart> &&neighborStart, Solution solution) : neighborStart(std::move(neighborStart)), solutionType(solution){}

/**
 * Get a better solution than the given one
 * @param solutionTab
 * @param start
 * @return
 */
std::vector<City> LocalSearch::bestImproving(std::vector<City> solutionTab) {
    std::vector<City> bestSolution = solutionTab;
    float bestDist = solutionType.totDist(bestSolution);
    for(int i = 0; i<neighborStart->numberOfSolution(solutionTab.size())-1;i++){
        std::vector<City> tryNeighborStrat = neighborStart->generateSolution(bestSolution,i);
        int distNeigbor = solutionType.totDist(tryNeighborStrat);
        if(distNeigbor < bestDist) {
            bestSolution = tryNeighborStrat;
            bestDist = distNeigbor;
        }
    }
    return bestSolution;
}

/**
 * Get a better solution thanks to the local search
 * @param solutionTab
 * @param start
 * @return
 */
std::vector<City> LocalSearch::algoDescent(std::vector<City> solutionTab) {
    std::vector<City> firstSolution = solutionTab;
    int distanceSolution = solutionType.totDist(firstSolution);
    std::vector<City> bestSolution = {};
    int bestDistance = std::numeric_limits<int>::max();

    while (bestDistance > distanceSolution) {
        bestSolution = firstSolution;
        bestDistance = distanceSolution;
        firstSolution = bestImproving(firstSolution);
        distanceSolution = solutionType.totDist(firstSolution);
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
    float bestDist = solutionType.totDist(bestSolution);
    for(int i = 0; i<neighborStart->numberOfSolution(solutionTab.size())-1;i++){
        std::vector<City> tryNeighborStrat = neighborStart->generateSolution(bestSolution,i);
        int distNeigbor = solutionType.totDist(tryNeighborStrat);
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
    float bestDist = solutionType.totDist(bestSolution);
    for(int i = 0; i<neighborStart->numberOfSolution(solutionTab.size())-1;i++){
        std::vector<City> tryNeighborStrat = neighborStart->generateSolution(bestSolution,randomIndex[i]);
        int distNeigbor = solutionType.totDist(tryNeighborStrat);
        if(distNeigbor < bestDist) {
            return tryNeighborStrat;
        }
    }
    return bestSolution;
}
