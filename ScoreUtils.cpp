//
// Created by Raphaelle Verdiere on 14/02/2023.
//

#include "ScoreUtils.h"
#include <math.h>
#include <algorithm>
#include <random>




std::vector<int> ScoreUtils::generateGloutonSolTab(File file, const int numCity) {
    std::vector<int> solution;

    //TODO: faire en sorte que l'on parte de la ville 0 puis de la ville 9 etc ...
    /*for (int i = 0; i < nbTotCities; i++) {
        keep = 1000000;
        for(int j = 0; j < nbTotCities; j++){
            if (i != j) {
                tempo = dist2Cities(file.getCities()[i], file.getCities()[j]);
                if (tempo < keep) {
                    keep = tempo;
                    solution[i + 1] = j;
                }
            }
        }
    }*/

    //return findSmallestDist(std::move(file), numCity, solution);
    return solution;
}

std::vector<int> ScoreUtils::findSmallestDist(File file, const int city, std::vector<int> solution) {
    float keep = 1000000;
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
            std::cout << i << ' ';
        }

        return findSmallestDist(file, solution[solution.size() - 1], solution);
    }
}

std::vector<int> ScoreUtils::generateRandomSolTab(const int nbCities) {
    std::vector<int> solution;

    for (int i = 0; i < nbCities; i++) {
        solution.push_back(i);
    }
    std::shuffle(std::begin(solution), std::end(solution), std::mt19937{std::random_device{}()});

    return solution;
}

