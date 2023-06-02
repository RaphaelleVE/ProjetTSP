//
// Created by mpore on 15/05/2023.
//

#include "Reinsertion.h"
#include "Exchange.h"
#include <algorithm>

//TODO: à tester
std::vector<City> Reinsertion::reinsertion(std::vector<City> solution, int v1Index, int v2Index) {
    std::vector<City> newSolution = solution;

    if (v1Index < v2Index) { // si v1Index = 1 et v2Index = 2
        newSolution.insert(newSolution.begin() + v2Index, solution[v1Index]); // on ajoute la valeur après v2Index;
        newSolution.erase(newSolution.begin() + v1Index);// on supprime la valeur à l'index v1Index
    } else {
        newSolution.erase(newSolution.begin() + v1Index);
        newSolution.insert(newSolution.begin() + v2Index, solution[v1Index]);
    }

    return newSolution;
}

//TODO: à tester
std::vector<City> Reinsertion::reinsertionByIndex(std::vector<City> solution, int index) {
    std::vector<City> newSolution = solution;
    int v1Index;
    int v2Index;

    if (index <= newSolution.size() - 2) {
        v1Index = 0;
        v2Index = index;
    } else {
        v1Index = (index - 1) / (newSolution.size() - 2);
        v2Index = (index - 1) % (newSolution.size() - 2);
        if (v2Index >= v1Index - 1) {
            v2Index += 2;
        }
    }

    return reinsertion(newSolution, v1Index, v2Index);
}

std::vector<City> Reinsertion::generateSolution(const std::vector<City> &solution, int index) {
    return reinsertionByIndex(solution,index);
}

int Reinsertion::numberOfSolution(int solutionSize) {
    return (solutionSize - 1) * (solutionSize - 2) / 2 + solutionSize - 1;
}