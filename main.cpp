#include <iostream>
#include "File.h"
#include "ScoreUtils.h"

int main() {
    File file ;
    file.registerTSPFile("../france_10.tsp");
    ScoreUtils scoreUtils;
    std::cout << '\n'<< "total: "<< scoreUtils.totDist(file, ScoreUtils::RANDOM) << '\n';
    return 0;
}