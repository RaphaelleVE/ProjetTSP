//
// Created by Raphaelle Verdiere on 14/02/2023.
//

#include "scoreUtils.h"
#include <math.h>

int scoreUtils::totDist(File file, std::vector<int> solution) {
    int tot = 0;
    for(int i = 0 ; i < file.getCities().size();i++){
       if(i!=file.getCities().size()){
           tot += dist2Cities(file.getCities()[i],file.getCities()[i+1]);
       }
       else{
           tot += dist2Cities(file.getCities()[i],file.getCities()[0]);
       }
    }
    return tot;
}

int scoreUtils::radConv(int nb) {
    return 0;
}

int scoreUtils::dist2Cities(City c1, City c2) {
    return rEarth *acos(sin(c1.getLatitude()) * sin(c2.getLatitude()));
}


