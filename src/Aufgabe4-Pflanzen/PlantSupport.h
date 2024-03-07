//
// Created by keanu on 06.03.2024.
//

#ifndef RAYLIBSTARTER_PLANTSUPPORT_H
#define RAYLIBSTARTER_PLANTSUPPORT_H

#include <map>
#include <string>

enum PlantType
{
    TREE = 0,
    GRASS = 1,
    BUSH = 2,
    FLOWER = 3
};

static std::map<PlantType, std::string> plantTypeMap = {
        {TREE, "Tree"},
        {GRASS, "Grass"},
        {BUSH, "Bush"},
        {FLOWER, "Flower"}
};

#endif //RAYLIBSTARTER_PLANTSUPPORT_H
