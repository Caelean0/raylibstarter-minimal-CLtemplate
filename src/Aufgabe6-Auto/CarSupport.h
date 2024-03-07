//
// Created by keanu on 06.03.2024.
//

#ifndef RAYLIBSTARTER_CARSUPPORT_H
#define RAYLIBSTARTER_CARSUPPORT_H

#include <map>
#include <string>

namespace console::car
{
    enum GearShift {
        Gear1 = 0,
        Gear2 = 1,
        Gear3 = 2,
        Gear4 = 3,
        Gear5 = 4
    };
    static std::map<GearShift, std::string> gearShiftMap = {
            {Gear1, "Gear1"},
            {Gear2, "Gear2"},
            {Gear3, "Gear3"},
            {Gear4, "Gear4"},
            {Gear5, "Gear5"}
    };

    enum MovementState {
        resting = 0,
        driving = 1,
    };
    static std::map<MovementState, std::string> movementStateMap = {
            {resting, "resting"},
            {driving, "driving"}
    };

    enum Direction {
        forward = 0,
        backward = 1
    };
    static std::map<Direction, std::string> directionMap = {
            {forward, "forward"},
            {backward, "backward"}
    };

    enum Turn {
        straight = 0,
        left = 1,
        right = 2
    };
    static std::map<Turn, std::string> turnMap = {
            {straight, "straight"},
            {left, "left"},
            {right, "right"}
    };


    enum CarType {
        Audi = 0,
        Mercedes = 1
    };
    static std::map<CarType, std::string> carTypeMap = {
            {Audi, "Audi"},
            {Mercedes, "Mercedes"}
    };
}

#endif //RAYLIBSTARTER_CARSUPPORT_H
