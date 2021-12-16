//
// Created by Daniil Zavalinskii on 16.12.2021.
//

#ifndef AVSHOMETASK5_HOTEL_H
#define AVSHOMETASK5_HOTEL_H

#include "Room.h"

class Hotel {
public:
    bool isOpened;
    Hotel();
    void workProcess();
    bool tryCheckIntoTheHotel(int genderOfGuest);
private:
    Room hotel[25];
    int numberOfFreePlaces;
};


#endif //AVSHOMETASK5_GUESTS_H
