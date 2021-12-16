//
// Created by Daniil Zavalinskii on 16.12.2021.
//

#include "Room.h"

Room::Room() = default;

Room::Room(int numberOfPlaces) {
    int i = 0;
    while (i < numberOfPlaces) {
        places[i] = false;
        ++i;
    }
    while (i < 2) {         // Если в комнате только одно место, "займем" второе при инициализации.
        places[i] = true;
        ++i;
    }
    genderOfTenant = 0;
    isOccupied = false;
}

Room::~Room() = default;

bool Room::tryCheckIntoTheRoom(int marker) {      // Метод, пытающийся заселить гостя в комнату.
    // Проверяет наличие свободного места и соответствие пола.
    // Возвращает true если заселение прошло успешно и false иначе.
    if (!isOccupied && genderOfTenant % marker == 0) {
        genderOfTenant += marker;
        for (int i = 0; i < 2; ++i) {
            if (!places[i]) {
                places[i] = true;
                break;
            }
        }
        if (places[1] && places[0]) {
            isOccupied = true;
        }
        return true;
    }
    return false;

}
