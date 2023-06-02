//
// Created by mpore on 16/05/2023.
//

#ifndef CHALLENGETSP_NEIGHBORSTART_H
#define CHALLENGETSP_NEIGHBORSTART_H

#include <iostream>
#include <vector>
#include "../../City.h"

class NeighborStart {
public:
    virtual std::vector<City> generateSolution(const std::vector<City>& solution, int index) = 0;
    virtual int numberOfSolution(int solutionSize) = 0;
    virtual ~NeighborStart() {}
};



#endif //CHALLENGETSP_NEIGHBORSTART_H
