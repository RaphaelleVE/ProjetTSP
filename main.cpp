#include <iostream>
#include "File.h"
#include "Solutions/Greedy.h"

int main() {
    File file ;
    file.registerTSPFile("../france_10.tsp");
    /*ScoreUtils scoreUtils;
    std::cout << '\n'<< "total: "<< scoreUtils.totDist(file, ScoreUtils::GLOUTON) << '\n';*/
    Greedy greedy(file.getCities());
    greedy.resolve();
    return 0;
}