//
// Created by Raphaelle Verdiere on 14/02/2023.
//

#include "City.h"

int City::getId() const {
    return id;
}

void City::setId(int id) {
    City::id = id;
}

const std::string City::getName() const {
    return name;
}

void City::setName(const std::string &name) {
    City::name = name;
}

float City::getLatitude() const {
    return latitude;
}

void City::setLatitude(float latitude) {
    City::latitude = latitude;
}

float City::getLongitude() const {
    return longitude;
}

void City::setLongitude(float longitude) {
    City::longitude = longitude;
}
