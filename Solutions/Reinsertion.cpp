//
// Created by mpore on 15/05/2023.
//

#include "Reinsertion.h"
#include "Exchange.h"
#include <algorithm>

std::vector<int> Reinsertion::reinsertion(std::vector<int>& vector, int v1, int v2) {
    int v1Index = Exchange::getIndex(vector, v1);
    int v2Index = Exchange::getIndex(vector, v2) + 1;

    if (v1Index < v2Index) { // si v1Index = 1 et v2Index = 2
        vector.insert(vector.begin() + v1Index, v1); // on ajoute la valeur après v2Index;
        vector.erase(std::remove(vector.begin(), vector.end(), v2Index), vector.end()); // on supprime la valeur à l'index v1Index
    } else {
        vector.erase(std::remove(vector.begin(), vector.end(), v1Index), vector.end());
        vector.insert(vector.begin() + v1Index, v1);
    }

    //vector.at(v1Index) = v2Index //TODO : à tester

    return vector;
}