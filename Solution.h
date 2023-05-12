//
// Created by mpore on 10/05/2023.
//

#ifndef CHALLENGETSP_SOLUTION_H
#define CHALLENGETSP_SOLUTION_H


#include "City.h"
#include "File.h"

class Solution {
protected :
    float const PI = 3.141592;
    float const rEarth = 6378.137;
    float getPi() const;
    float getREarth() const;

    virtual std::vector<int> resolve();
    float radConv(float nb);

    float dist2Cities(const City& c1, const City& c2);
    std::vector<int> findSmallestDist(File file, const int city, std::vector<int> solution);

    int totDist(File file);
};


#endif //CHALLENGETSP_SOLUTION_H