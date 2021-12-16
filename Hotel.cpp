//
// Created by Daniil Zavalinskii on 16.12.2021.
//

#include "Hotel.h"
#include <iostream>
#include <chrono>
#include <thread>

Hotel::Hotel() {
    for (int i = 0; i < 10; ++i) {      // Initialization of rooms in hotel.
        hotel[i] = Room(1);
    }
    for (int i = 10; i < 25; ++i) {
        hotel[i] = Room(2);
    }
    numberOfFreePlaces = 40;
    isOpened = true;
}

void Hotel::workProcess() {
    while (isOpened) {
        if(numberOfFreePlaces == 0) {
            std::cout << "There is no more free places, hotel is closed for new guests";
            isOpened = false;
        }
        std::chrono::seconds sleepDuration(1);
        std::this_thread::sleep_for(sleepDuration);
    }
}
bool Hotel::tryCheckIntoTheHotel(int genderOfGuest) {
    if (!isOpened){
        return false;
    }
    for (int i = 0; i < 25; ++i) {
        if (hotel[i].tryCheckIntoTheRoom(genderOfGuest)) {
            --numberOfFreePlaces;
            return true;
        }
    }
    return false;
};
