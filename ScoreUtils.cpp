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
    switch (sType) {
        case RANDOM :
            generateRandomSolTab(file.getCityNb());
            break;
        case WRITE : std::cout << "not implemented yet";
            return -1;
            break;
    }
    int tot = 0;
    for(int i = 0; i < file.getCityNb(); i++){
        std::cout << file.getCityNb() << '\n';
        if(i != file.getCityNb()){
            tot += dist2Cities(file.getCities()[solutionTab[i]],file.getCities()[solutionTab[i+1]]);
            std::cout << tot << '\n';
        }
        else {
            std::cout << "paopaoeod" << '\n';
            tot += dist2Cities(file.getCities()[solutionTab[i]],file.getCities()[solutionTab[0]]);
        }
    }
    return tot;
}

/**
 * Convert a degree value into a radian value
 * @param nb
 * @return
 */
int ScoreUtils::radConv(float nb) {
    return getPi() * nb /180;
}

/**
 * Calculate the distance between 2 cities
 * @param c1
 * @param c2
 * @return
 */
int ScoreUtils::dist2Cities(const City& c1, const City& c2) {
    float city1Lat = radConv(c1.getLatitude());
    float city2Lat = radConv(c2.getLatitude());
    float city1Long = radConv(c1.getLongitude());
    float city2Long = radConv(c2.getLongitude());
    return rEarth * acos(sin(city1Lat) * sin(city2Lat) + cos(city1Lat) * cos(city2Lat) * cos(city2Long - city1Long));
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


void ScoreUtils::generateRandomSolTab(const int nbCities) {
    std::vector<int> solution;

    for (int i = 0; i < nbCities; i++) {
        solution.push_back(i);
    }

    std::shuffle(std::begin(solution), std::end(solution), std::mt19937{std::random_device{}()});

    for (int i = 0; i < nbCities; i++) {
        std::cout << solution[i] << ' ';
    }
    std::cout << "end random gen"<< '\n' ;

}

