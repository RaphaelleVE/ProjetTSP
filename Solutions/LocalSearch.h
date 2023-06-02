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
    LocalSearch(Solution *solution,std::unique_ptr<NeighborStart> &&neighborStart = {});
    std::vector<City> localSearchIterate();


private:
    std::vector<City> localSearchAll(std::vector<City> solution);
    std::vector<City> algoDescent(std::vector<City> solution);
    std::vector<City> firstImproving(std::vector<City> solution);
    std::vector<City> firstRandomImproving(std::vector<City> solution);
    std::vector<City> bestImproving(std::vector<City> solution);
    std::vector<City> originalSolution;
    std::unique_ptr<NeighborStart> neighborStart;
    Solution *solutionType;
    void writeAnswerFile(std::vector<City> result);
    std::vector<std::unique_ptr<NeighborStart>> listNighborStrat;
    std::vector<City> solutionAgitator(std::vector<City> solution, const int force);

};


#endif //CHALLENGETSP_LOCALSEARCH_H
