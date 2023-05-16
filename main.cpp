#include <iostream>
#include "File.h"
#include "Solutions/Greedy.h"
#include "Solutions/Random.h"

int main() {
    File file ;
    file.registerTSPFile("../france_10.tsp");

    /*Greedy greedy(file.getCities());
    greedy.resolve();*/

    Random randomFun(file.getCities());
    randomFun.resolve();
    return 0;
}