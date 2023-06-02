//
// Created by mpore on 10/05/2023.
//

#include "Random.h"
#include <random>
#include <algorithm>

/**
 * Constructor
 * @param cities
 */
Random::Random(std::vector<City> cities) : Solution(), m_cities(cities) {
}

/**
 * Give a random solution for a specific vector
 * @return
 */
std::vector<City> Random::resolve() {
    std::vector<City> copy = m_cities ;
    std::shuffle(std::begin(copy), std::end(copy), std::mt19937{std::random_device{}()});
    writeAnswerFile(copy);
    return copy;
}
