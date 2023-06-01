//
// Created by mpore on 16/05/2023.
//

#ifndef CHALLENGETSP_LOCALSEARCH_H
#define CHALLENGETSP_LOCALSEARCH_H

#include <vector>
#include <memory>
#include "Strategies/NeighborStart.h"
#include "Solution.h"


class LocalSearch {
public :
    explicit LocalSearch(std::unique_ptr<NeighborStart> &&neighborStart = {}, Solution solution = {});
    std::vector<City> bestImproving(std::vector<City> solution);
    std::vector<City> firstImproving(std::vector<City> solution);
    std::vector<City> algoDescent(std::vector<City> solutionTab);
    std::vector<City> firstRandomImproving(std::vector<City> solution);

private:
    std::unique_ptr<NeighborStart> neighborStart;
    Solution solutionType;
};


#endif //CHALLENGETSP_LOCALSEARCH_H
