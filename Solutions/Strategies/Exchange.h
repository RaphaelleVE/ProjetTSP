//
// Created by mpore on 15/05/2023.
//

#ifndef CHALLENGETSP_EXCHANGE_H
#define CHALLENGETSP_EXCHANGE_H


#include "../Solution.h"
#include "NeighborStart.h"

class Exchange : public NeighborStart{
public:
    virtual std::vector<City> generateSolution(const std::vector<City>& solution,int index) override;
    virtual int numberOfSolution(int solutionSize) override;
protected:
    std::vector<City> exchangeByIndex(std::vector<City> vector, int index);
    std::vector<City> exchange(std::vector<City> vector, int v1Index, int v2Index);
    std::vector<City> m_cities;
};


#endif //CHALLENGETSP_EXCHANGE_H
