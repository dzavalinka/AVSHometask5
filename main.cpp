#include <iostream>
#include <thread>
#include <mutex>
#include "Hotel.h"
#include "Guests.h"

int main() {
    std::mutex lock;
    std::cout << "Enter amount of guests\n";
    int numberOfGuests;
    std::cin >> numberOfGuests;
    while (numberOfGuests < 1) {
        std::cout << "Please enter correct amount of guests\n";
        std::cin >> numberOfGuests;
    }
    Hotel hotel = Hotel();
    Guests guests = Guests(&hotel, numberOfGuests);

    std::thread guestsThread(&Guests::checkIn, &guests);
    std::thread hotelThread(&Hotel::workProcess, &hotel);

    hotelThread.join();
    guestsThread.join();
}
