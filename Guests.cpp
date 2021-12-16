//
// Created by Daniil Zavalinskii on 16.12.2021.
//

#include "Guests.h"
#include <iostream>
#include <thread>
#include <chrono>

Guests::Guests(Hotel *hotel, int numberOfGuests) {
    this->hotel_ = hotel;
    this->numberOfGuests = numberOfGuests;
}

void Guests::checkIn() {
    while (numberOfGuests > 0) {
        int genderOfGuest = 2 + rand() % 2;
        if (hotel_->isOpened) {
            if (hotel_->tryCheckIntoTheHotel(genderOfGuest)) {
                std::cout << ((genderOfGuest == 2) ? "Male" : "Female") << " guest"
                          << " checked in successfully\n";
            } else {
                std::cout << ((genderOfGuest == 2) ? "Male" : "Female") << " guest"
                          << " left to find another place to sleep\n";
            }
        }
        std::chrono::seconds sleepDuration(1);
        std::this_thread::sleep_for(sleepDuration);
        --numberOfGuests;
    }
    hotel_->isOpened = false;
}