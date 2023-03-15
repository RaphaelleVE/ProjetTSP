//
// Created by Raphaelle Verdiere on 14/02/2023.
//

#ifndef CHALLENGETSP_SCOREUTILS_H
#define CHALLENGETSP_SCOREUTILS_H


#include "File.h"

class ScoreUtils {

protected :
    float const PI = 3.141592;
    float const rEarth = 6378.137;
    const std::vector<int> &getSolutionTab() const;
    void setSolutionTab(const std::vector<int> &solutionTab);
    std::vector<int> findSmallestDist(File file, const int city, std::vector<int> solution);
    const float getPi();
    const float getREarth();

protected:
     std::vector<int> solutionTab;
     float dist2Cities(const City& c1, const City& c2);
     float radConv(float nb) ;
public :
    enum SolutionType {RANDOM,GLOUTON};
    std::vector<int> generateRandomSolTab(const int nbCities);
    std::vector<int> generateGloutonSolTab(File file, const int numCity);
    int totDist (File file, SolutionType sType);
};


#endif //CHALLENGETSP_SCOREUTILS_H
