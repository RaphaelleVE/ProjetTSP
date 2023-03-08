//
// Created by Raphaelle Verdiere on 14/02/2023.
//

#ifndef CHALLENGETSP_CITY_H
#define CHALLENGETSP_CITY_H
#include <iostream>


class City {
    protected:
        int id;
        std::string name;
        float latitude;
        float longitude;

    public:
        int getId() const;

        void setId(int id);

        const std::string getName() const;

        void setName(const std::string &name);

    float getLatitude() const;

        void setLatitude(float latitude);

    float getLongitude() const;

        void setLongitude(float longitude);
};


#endif //CHALLENGETSP_CITY_H
