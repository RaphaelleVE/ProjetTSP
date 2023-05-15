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
 * @param v1
 * @param v2
 * @return
 */
void Exchange::exchange(std::vector<int> vector, int v1, int v2) {
    int v1Index = getIndex(vector, v1);
    int v2Index = getIndex(vector, v2);

    return std::swap(vector[v1Index], vector[v2Index]);
}

//TODO: à tester
 /**
  * Exchange 2 values in a vector thanks to an index (4.2)
  * @param vector
  * @param index
  */
void Exchange::exchangeByIndex(std::vector<int> vector, int index) {
    double n = (1 + sqrt(1 + 8 * index)) / 2;
    int v1 = index - (n * (n - 1)) / 2;
    int v2 = vector.size() - n + v1;

    return exchange(vector, v1, v2);
}

//TODO: à placer dans une fonction globale pour qu'elle puisse être aussi utilisée par Reinsertion
/**
 * Get index of a value in a vector
 * @param vector
 * @param value
 * @return
 */
int Exchange::getIndex(const std::vector<int>& vector, const int value) {
    auto it = std::find(vector.begin(), vector.end(), value);

    if (it != vector.end()) {
        return std::distance(vector.begin(), it);
    }

    return false;
}
