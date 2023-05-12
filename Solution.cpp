//
// Created by mpore on 10/05/2023.
//

#include "Solution.h"
#include <math.h>
#include <algorithm>
#include <fstream>


float Solution::getPi() const {
    return PI;
}

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

std::vector<int> Solution::findSmallestDist(File file, const int city, std::vector<int> solution) {
    float keep = 1000000;
    float tempo;
    const int nbTotCities = file.getCityNb();
    solution.push_back(city);

    if (solution.size() <= nbTotCities) {
        for (int i : solution) {
            std::cout << i << ' ';
        }
        std::cout << "debglou";
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

std::vector<int> Solution::resolve() {
    return std::vector<int>();
}

//todo A TESTER
void Solution::writeAnswerFile(std::vector<int> result) {
    std::ofstream outFile("result.txt");
    //pour vider (voir si utile & crée pas de beug si existe pas)
    //std::ofstream.open("result.txt", std::ofstream::out | std::ofstream::trunc);
    //std::ofstream.close();
    for(int cityNb : result){
        outFile << cityNb;
    }
    outFile.close();
}
