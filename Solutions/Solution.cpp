//
// Created by mpore on 10/05/2023.
//

#include "Solution.h"
#include <math.h>
#include <algorithm>
#include <fstream>
#include <limits>


/**
 * Get the pi value
 * @return
 */
float Solution::getPi() const {
    return PI;
}

/**
 * Get the Earth's radius value
 * @return
 */
float Solution::getREarth() const {
    return rEarth;
}

/**
 * Convert a degree value into a radian value
 * @param nb
 * @return
 */
float Solution::radConv(float nb) {
    return getPi() * nb / 180;
}

/**
 * Calculate the distance between 2 cities
 * @param c1
 * @param c2
 * @return
 */
float Solution::dist2Cities(const City& c1, const City& c2) {
    float city1Lat = radConv(c1.getLatitude());
    float city2Lat = radConv(c2.getLatitude());
    float city1Long = radConv(c1.getLongitude());
    float city2Long = radConv(c2.getLongitude());
    return getREarth() * acos(sin(city1Lat) * sin(city2Lat) + cos(city1Lat) * cos(city2Lat) * cos(city2Long - city1Long));
}

//TODO: est-ce qu'on en a encore besoin ?
/**
 * Find the smallest distance between cities from a file
 * @param file
 * @param city
 * @param solution
 * @return
 */
std::vector<int> Solution::findSmallestDist(File file, const int city, std::vector<int> solution) {
    int keep = std::numeric_limits<int>::max();
    float tempo;
    const int nbTotCities = file.getCityNb();
    solution.push_back(city);

    if (solution.size() <= nbTotCities) {
        for (int i : solution) {
            std::cout << i << ' ';
        }

        return solution;
    } else {
        for (int i = 0; i < nbTotCities; ++i) {
            if (std::find(solution.begin(), solution.end(), i) == solution.end()) {
                tempo = dist2Cities(file.getCities()[city], file.getCities()[i]);

                if (tempo < keep) {
                    keep = tempo;
                    solution.push_back(i);
                }
            }
        }

        for (int i : solution) {
            std::cout << i <<' ';
        }

        return findSmallestDist(file, solution[solution.size() - 1], solution);
    }
}

/**
 * Get the total distance for the solution
 * @param file
 * @param sType
 * @return
 */
int Solution::totDist(File file) {
    std::vector <int> solTab ;

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
 * Resolve function - should be override by children
 * @return
 */
std::vector<int> Solution::resolve() {
    return {};
}

void Solution::writeAnswerFile( std::vector<City> result) {
    std::ofstream outFile("../test.txt");

    //pour vider (voir si utile & crée pas de beug si existe pas)
    //std::ofstream.open("result.txt", std::ofstream::out | std::ofstream::trunc);
    //std::ofstream.close();

    for(int cityNb : result){
        outFile << cityNb;
    }
    outFile.close();
}
