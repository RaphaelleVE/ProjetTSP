//
// Created by mpore on 15/05/2023.
//

#include "Exchange.h"
#include <algorithm>
#include <math.h>

//TODO: à tester
/**
 * Exchange 2 defined values in a vector (4.1)
 * @param vector
 * @param v1Index
 * @param v2Index
 * @return
 */
std::vector<City> Exchange::exchange(std::vector<City> initSolution, int v1Index, int v2Index) {
    std::vector<City> newSolution = initSolution;
    std::swap(newSolution[v1Index], newSolution[v2Index]);
    return newSolution;
}

//TODO: à tester
/**
* Exchange 2 values in a vector thanks to an index (4.2)
* @param vector
* @param index
*/
std::vector<City> Exchange::exchangeByIndex(std::vector<City> initSolution, int index) {
    std::vector<City> newSolution = initSolution;

    double n = (1 + sqrt(1 + 8 * index)) / 2;
    int v1Index = index - (n * (n - 1)) / 2;
    int v2Index = newSolution.size() - n + v1Index;
    return exchange(newSolution, v1Index, v2Index);
}



std::vector<City> Exchange::generateSolution(const std::vector<City> &solution, int index) {
    std::cout<< " exchange write : ";
    for(City city : solution){
        std::cout<< city.getId();
    }
    std::cout<< "\n";
    return exchangeByIndex(solution,index);
}

int Exchange::numberOfSolution(int solutionSize) {
    return solutionSize * (solutionSize - 1) / 2;
}
