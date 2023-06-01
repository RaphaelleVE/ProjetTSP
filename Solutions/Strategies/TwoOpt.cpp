//
// Created by mpore on 15/05/2023.
//

#include "TwoOpt.h"
#include <algorithm>
#include <math.h>

//TODO: à tester
/**
 * Reverse vector's values between two indexes
 * @param initSolution
 * @param v1Index
 * @param v2Index
 * @return
 */
std::vector<City> TwoOpt::twoOpt(std::vector<City> initSolution, int v1Index, int v2Index) {
    std::vector<City> newSolution = initSolution;

    std::reverse(newSolution.begin() + v1Index, newSolution.begin() + v2Index + 1);
    return newSolution;
}

//TODO: à tester
/**
 * Reverse vector's values for a given index
 * @param initSolution
 * @param index
 * @return
 */
std::vector<City> TwoOpt::twoOptByIndex(std::vector<City> initSolution, int index) {
    std::vector<City> newSolution = initSolution;

    double n = (1 + sqrt(1 + 8 * index)) / 2;
    int v1Index = index - (n * (n - 1)) / 2;
    int v2Index = newSolution.size() - n + v1Index;

    return twoOpt(newSolution, v1Index, v2Index);
}

std::vector<City> TwoOpt::generateSolution(const std::vector<City> &solution, int index) {
    return twoOptByIndex(solution, index);
}
int TwoOpt::numberOfSolution(int solutionSize) {
    return solutionSize * (solutionSize - 1) / 2;
}
