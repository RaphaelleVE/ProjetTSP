//
// Created by Raphaelle Verdiere on 14/02/2023.
//

#include "City.h"

/**
 * Get id value
 * @return
 */
int City::getId() const {
    return id;
}

/**
 * Set id value
 * @param id
 */
void City::setId(int id) {
    City::id = id;
}

/**
 * Get the city's name
 * @return
 */
const std::string City::getName() const {
    return name;
}

/**
 * Set the city's name
 * @param name
 */
void City::setName(const std::string &name) {
    City::name = name;
}

/**
 * Get the city's latitude
 * @return
 */
float City::getLatitude() const {
    return latitude;
}

/**
 * Set the city's latitude
 * @param latitude
 */
void City::setLatitude(float latitude) {
    City::latitude = latitude;
}

/**
 * Get the city's longitude
 * @return
 */
float City::getLongitude() const {
    return longitude;
}

/**
 * Set the city's longitude
 * @param longitude
 */
void City::setLongitude(float longitude) {
    City::longitude = longitude;
}
