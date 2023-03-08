//
// Created by Raphaelle Verdiere on 14/02/2023.
//

#ifndef CHALLENGETSP_FILE_H
#define CHALLENGETSP_FILE_H
#include <iostream>
#include <vector>
#include "City.h"


class File {
    protected:
        int cityNb;
        std::vector<City> cities;
public:
    int getCityNb() const;

    void setCityNb(int cityNb);

    std::vector<City> &getCities();

    void setCities(const std::vector<City> &cities);

    void registerTSPFile(const std::string &fileName);
};


#endif //CHALLENGETSP_FILE_H
