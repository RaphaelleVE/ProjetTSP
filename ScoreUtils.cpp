//
// Created by Raphaelle Verdiere on 14/02/2023.
//

#include "ScoreUtils.h"
#include <math.h>
#include <algorithm>
#include <random>

/**
 * Get the total distance for the solution
 * @param file
 * @param sType
 * @return
 */
int ScoreUtils::totDist(File file, SolutionType sType) {
    std::vector <int> solTab ;
    switch (sType) {
        case RANDOM :
            solTab = generateRandomSolTab(file.getCityNb());
            break;
        case GLOUTON :
            solTab = generateGloutonSolTab(file);
            break;
    }
    int tot = 0;
    for(int i = 0; i < file.getCityNb() +1; i++){
        if(i != file.getCityNb()){
            tot += dist2Cities(file.getCities()[solTab[i]],file.getCities()[solTab[i+1]]);
            //std::cout << "tot1 " << tot << ' ';
        }
        else {
            std::cout << "here" << ' ';
            tot += dist2Cities(file.getCities()[solTab[i]],file.getCities()[solTab[0]]);
            //std::cout << "totot " << tot << ' ';
        }
    }
    return tot;
}

/**
 * Convert a degree value into a radian value
 * @param nb
 * @return
 */
float ScoreUtils::radConv(float nb) {
    return getPi() * nb / 180;
}

/**
 * Calculate the distance between 2 cities
 * @param c1
 * @param c2
 * @return
 */
float ScoreUtils::dist2Cities(const City& c1, const City& c2) {
    float city1Lat = radConv(c1.getLatitude());
    float city2Lat = radConv(c2.getLatitude());
    float city1Long = radConv(c1.getLongitude());
    float city2Long = radConv(c2.getLongitude());
    return getREarth() * acos(sin(city1Lat) * sin(city2Lat) + cos(city1Lat) * cos(city2Lat) * cos(city2Long - city1Long));
}

const std::vector<int> &ScoreUtils::getSolutionTab() const {
    return solutionTab;
}

void ScoreUtils::setSolutionTab(const std::vector<int> &solutionTab) {
    ScoreUtils::solutionTab = solutionTab;
}

const float ScoreUtils::getPi() {
    return PI;
}

const float ScoreUtils::getREarth()  {
    return rEarth;
}

std::vector<int> ScoreUtils::generateGloutonSolTab(File file) {
    std::vector<int> solution;
    float tot;
    float keep;
    float tempo;

    solution.push_back(0);

    //TODO: faire en sorte que l'on parte de la ville 0 puis de la ville 9 etc ...
    for (int i = 0; i < file.getCityNb(); i++) {
        keep = 1000000;
        for(int j = 0; j < file.getCityNb(); j++){
            if (i != j) {
                tempo = dist2Cities(file.getCities()[i], file.getCities()[j]);
                if (tempo < keep) {
                    keep = tempo;
                    solution[i + 1] = j;
                }
            }
        }
    }

    for (int i = 0; i < file.getCityNb(); i++) {
        std::cout << solution[i] << ' ';
    }

    return solution;
}

std::vector<int> ScoreUtils::generateRandomSolTab(const int nbCities) {
    std::vector<int> solution;

    for (int i = 0; i < nbCities; i++) {
        solution.push_back(i);
    }
    std::shuffle(std::begin(solution), std::end(solution), std::mt19937{std::random_device{}()});

    return solution;
}

