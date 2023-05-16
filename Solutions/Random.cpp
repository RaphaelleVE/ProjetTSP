//
// Created by mpore on 10/05/2023.
//

#include "Random.h"
#include <random>
#include <algorithm>



Random::Random(std::vector<City> cities) : m_cities(cities) {}

std::vector<int> Random::resolve() {
    std::vector<int> copy ;

    for(City city : m_cities){
        copy.push_back(city.getId());
    }
    std::shuffle(std::begin(copy), std::end(copy), std::mt19937{std::random_device{}()});

    return copy;
}
