//
// Created by mpore on 10/05/2023.
//

#include "Random.h"
#include <random>
#include <algorithm>



Random::Random(std::vector<City> cities) : m_cities(cities) {}

std::vector<int> Random::resolve() {
    //TODO changer vector en city pour calcul plus simple ? ou garder int et se réferer un tab de base pour retrouver les city ?
    // voir ce qui est le mieux. pense a ce qui peut etre implementer partout & héritage .
    // (fct dans solution qui permet de retrouver city grace a id de city dans tab de solutoin ?
    std::vector<int> copy ;

    for(City city : m_cities){
        copy.push_back(city.getId());
    }

    /*std::linear_congruential_engine<unsigned int, 16807, 0, 2147483647> rd;
    std::default_random_engine gen(rd);
    std::shuffle(m_cities.begin(),m_cities.end(),gen);*/

    std::shuffle(std::begin(copy), std::end(copy), std::mt19937{std::random_device{}()});

    return
}
