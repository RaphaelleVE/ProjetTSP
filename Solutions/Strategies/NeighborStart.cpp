//
// Created by mpore on 16/05/2023.
//

#include "NeighborStart.h"
#include <algorithm>

//TODO: voir si on la garde ou pas
/**
 * Get index of a value in a vector
 * @param vector
 * @param value
 * @return
 */
int NeighborStart::getIndex(const std::vector<City>& solution, const int value) {
    auto it = std::find_if(solution.begin(), solution.end(), [&value](const City& city ){
        return city.getId() == value;
    });

    if (it != solution.end()) {
        return std::distance(solution.begin(), it);
    }

    return false;
}

