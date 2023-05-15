//
// Created by mpore on 10/05/2023.
//

#ifndef CHALLENGETSP_GREEDY_H
#define CHALLENGETSP_GREEDY_H


#include "Solution.h"

class Greedy : public Solution {
public:
    Greedy(std::vector <City> cities);
    std::vector<int> resolve() override;
protected:
    std::vector <City> m_cities;
};


#endif //CHALLENGETSP_GREEDY_H
