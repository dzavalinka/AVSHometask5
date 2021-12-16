//
// Created by Daniil Zavalinskii on 16.12.2021.
//

#ifndef AVSHOMETASK5_ROOM_H
#define AVSHOMETASK5_ROOM_H


class Room {
private:
    bool isOccupied;    // True if there aren't free places in room anymore.
    int genderOfTenant; // 0 if room is free, 2 or 4 if in room lives >=1 male, 3 or 6 if in room lives >=1 female.
    bool places[2];     // True если соответствующее место занято, false иначе.
public:
    Room();

    explicit Room(int numberOfPlaces);

    ~Room();

    bool tryCheckIntoTheRoom(int marker);

};


#endif //AVSHOMETASK5_GUESTS_H
