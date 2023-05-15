#include <iostream>
#include "File.h"

int main() {
    File file ;
    file.registerTSPFile("../france_10.tsp");
    /*ScoreUtils scoreUtils;
    std::cout << '\n'<< "total: "<< scoreUtils.totDist(file, ScoreUtils::GLOUTON) << '\n';*/
    return 0;
}