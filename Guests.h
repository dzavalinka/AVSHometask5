//
// Created by Daniil Zavalinskii on 16.12.2021.
//

#ifndef AVSHOMETASK5_GUESTS_H
#define AVSHOMETASK5_GUESTS_H

#include "Hotel.h"


class Guests {
public:
    Guests(Hotel *hotel, int numberOfGuests);
    void checkIn();
private:
    Hotel *hotel_;
    int numberOfGuests;
};


#endif //AVSHOMETASK5_GUESTS_H
