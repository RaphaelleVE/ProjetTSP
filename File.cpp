//
// Created by Raphaelle Verdiere on 14/02/2023.
//

#include "File.h"

int File::getCityNb() const {
    return cityNb;
}

void File::setCityNb(int cityNb) {
    File::cityNb = cityNb;
}

const std::vector<City> &File::getCities() const {
    return cities;
}

void File::setCities(const std::vector<City> &cities) {
    File::cities = cities;
}
