//
// Created by mpore on 15/05/2023.
//

#ifndef CHALLENGETSP_TWOOPT_H
#define CHALLENGETSP_TWOOPT_H


#include "NeighborStart.h"

class TwoOpt : public NeighborStart{
public:
    virtual std::vector<City> generateSolution(const std::vector<City> &solution, int index);
    virtual int numberOfSolution(int solutionSize) override;
protected:
    std::vector<City> twoOpt(std::vector<City> initSolution, int v1Index, int v2Index);
    std::vector<City> twoOptByIndex(std::vector<City> initSolution, int index);
};


#endif //CHALLENGETSP_TWOOPT_H
