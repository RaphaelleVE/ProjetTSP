//
// Created by mpore on 15/05/2023.
//

#ifndef CHALLENGETSP_REINSERTION_H
#define CHALLENGETSP_REINSERTION_H


#include <vector>
#include "NeighborStart.h"

class Reinsertion : public NeighborStart {
protected:
    virtual std::vector<City> generateSolution(const std::vector<City>& solution,int index) override;
public:
    static std::vector<City> reinsertionByIndex(std::vector<City> vector, int index);
    static std::vector<City> reinsertion(std::vector<City> vector, int v1Index, int v2Index);
    virtual int numberOfSolution(int solutionSize) override;
};


#endif //CHALLENGETSP_REINSERTION_H
