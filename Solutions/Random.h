//
// Created by mpore on 10/05/2023.
//

#ifndef CHALLENGETSP_RANDOM_H
#define CHALLENGETSP_RANDOM_H

#include <vector>
#include "../City.h"
#include "Solution.h"


class Random : public Solution {
public:
    Random(std::vector <City> cities);
    std::vector<City> resolve() override;
protected:
    std::vector <City> m_cities;
};


#endif //CHALLENGETSP_RANDOM_H
