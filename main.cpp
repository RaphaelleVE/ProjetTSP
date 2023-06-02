#include <iostream>
#include "File.h"
#include "Solutions/Greedy.h"
#include "Solutions/Random.h"
#include "Solutions/Strategies/Reinsertion.h"
#include "Solutions/LocalSearch.h"
#include "Solutions/Strategies/Exchange.h"
#include "Solutions/Strategies/TwoOpt.h"

int main() {
    File file ;
    file.registerTSPFile("../france_10.tsp");

    /*Greedy greedy(file.getCities());
    greedy.resolve();*/

    /*Random randomFun(file.getCities());
    randomFun.resolve();*/

    auto *randomSolution = new Random(file.getCities());
    auto *greedySolution = new Greedy(file.getCities());


    LocalSearch localSearch(greedySolution,std::make_unique<Reinsertion>());
  //  localSearch.algoDescent();
    localSearch.localSearchIterate();
   //localSearch.solutionAgitator()

    return 0;
}