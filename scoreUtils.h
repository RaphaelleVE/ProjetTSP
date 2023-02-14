//
// Created by Raphaelle Verdiere on 14/02/2023.
//

#ifndef CHALLENGETSP_SCOREUTILS_H
#define CHALLENGETSP_SCOREUTILS_H


#include "File.h"

class scoreUtils {

protected :
    void dist2Cities(City c1, City c2);
    int radConv(int nb);
    int const PI = 3;
    int const rEarth = 3;
public :
    int totDist (File file, std::vector<int> solution);



};


#endif //CHALLENGETSP_SCOREUTILS_H
