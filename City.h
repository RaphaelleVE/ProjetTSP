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
        int latitude;
        int longitude;

    public:
        int getId() const;

        void setId(int id);

        const std::string &getName() const;

        void setName(const std::string &name);

        int getLatitude() const;

        void setLatitude(int latitude);

        int getLongitude() const;

        void setLongitude(int longitude);
};


#endif //CHALLENGETSP_CITY_H
