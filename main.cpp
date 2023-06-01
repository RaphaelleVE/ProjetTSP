#include <iostream>
#include "File.h"
#include "Solutions/Greedy.h"
#include "Solutions/Random.h"
#include "Solutions/Strategies/Reinsertion.h"
#include "Solutions/LocalSearch.h"
#include "Solutions/Strategies/Exchange.h"

int main() {
    File file ;
    file.registerTSPFile("../france_10.tsp");

    /*Greedy greedy(file.getCities());
    greedy.resolve();*/

    /*Random randomFun(file.getCities());
    randomFun.resolve();*/

    //Exchange::exchange({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, 2, 5);

    //Reinsertion::reinsertion({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, 2, 5);

    LocalSearch localSearch(std::make_unique<Exchange>(),Random(file.getCities()).resolve());
    localSearch.algoDescent(file.getCities());

    return 0;
}