//
// Created by Raphaelle Verdiere on 14/02/2023.
//

#include "File.h"
#include <fstream>

int File::getCityNb() const {
    return cityNb;
}

void File::setCityNb(int cityNb) {
    File::cityNb = cityNb;
}

std::vector<City> &File::getCities(){
    return cities;
}

void File::setCities(const std::vector<City> &cities) {
    File::cities = cities;
}

void File::registerTSPFile(const std::string &fileName) {
    std::cout << fileName ;
    std::ifstream file(fileName);
    if (file.is_open()){
        int nbCities = 0 ;
        file >> nbCities;
        std::cout << nbCities << '\n';
        std::string save;
        float saveInt;
        for (int j = 0 ; j < nbCities ; j++){
                City c ;
                c.setId(j+1);
                file >> save;
                c.setName(save);
                file >> saveInt;
                c.setLongitude(saveInt);
                file >> saveInt;
                c.setLatitude(saveInt);
                getCities().push_back(c);
                std::cout << c.getId()<< '\n' ;
                std::cout << c.getName()<< '\n' ;
                std::cout << c.getLatitude()<< '\n' ;
                std::cout << c.getLongitude()<< '\n' ;
        }
    }else{
        std::cout << "error opening file" ;
    }
}
