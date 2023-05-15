//
// Created by mpore on 15/05/2023.
//

#ifndef CHALLENGETSP_EXCHANGE_H
#define CHALLENGETSP_EXCHANGE_H


#include "Solution.h"

class Exchange {
public:
    void exchangeByIndex(std::vector<int> vector, int index);
    static int getIndex(const std::vector<int>& vector, int value);
protected:
    std::vector<City> m_cities;

    void exchange(std::vector<int> vector, int v1, int v2);
};


#endif //CHALLENGETSP_EXCHANGE_H
