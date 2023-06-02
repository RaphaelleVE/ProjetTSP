//
// Created by mpore on 10/05/2023.
//

#ifndef CHALLENGETSP_SOLUTION_H
#define CHALLENGETSP_SOLUTION_H


#include "../City.h"
#include "../File.h"

class Solution {
    //todo: revoir ce qui est protected ou non
public:
    float dist2Cities(const City& c1, const City& c2);
    virtual std::vector<City> resolve();
    float totDist(std::vector<City> cityTab);

protected :
    float const PI = 3.141592;
    float const rEarth = 6378.137;
    float getPi() const;
    float getREarth() const;
    float radConv(float nb);
    std::vector<int> findSmallestDist(File file, const int city, std::vector<int> solution);
    void writeAnswerFile(std::vector<City> result);
    static int getIndex(const std::vector<City>& solution, City value);
};


#endif //CHALLENGETSP_SOLUTION_H
