//
// Created by Raphaelle Verdiere on 14/02/2023.
//

#include "File.h"
#include <fstream>

/**
 * Get the number of cities in a file
 * @return
 */
int File::getCityNb() const {
    return cityNb;
}

/**
 * Set the number of cities
 * @param cityNb
 */
void File::setCityNb(int cityNb) {
    File::cityNb = cityNb;
}

/**
 * Get the cities from a file
 * @return
 */
std::vector<City> &File::getCities(){
    return cities;
}

/**
 * Set cities' information
 * @param cities
 */
void File::setCities(const std::vector<City> &cities) {
    File::cities = cities;
}

/**
 * Save the cities that are inside the file
 * @param fileName
 */
void File::registerTSPFile(const std::string &fileName) {
    std::ifstream file(fileName);
    if (file.is_open()){
        int nbCities = 0 ;
        file >> nbCities;
        std::cout << nbCities << '\n';
        setCityNb(nbCities);
        std::string save;
        float saveInt;
        for (int j = 0 ; j < nbCities ; j++){
                City c ;
                c.setId(j);
                file >> save;
                c.setName(save);
                file >> saveInt;
                c.setLongitude(saveInt);
                file >> saveInt;
                c.setLatitude(saveInt);
                getCities().push_back(c);
                /*std::cout << c.getId()<< '\n' ;
                std::cout << c.getName()<< '\n' ;
                std::cout << c.getLatitude()<< '\n' ;
                std::cout << c.getLongitude()<< '\n' ;**/
        }
    }else{
        std::cout << "error opening file" ;
    }
}
