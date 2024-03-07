//
// Created by keanu on 06.03.2024.
//

#include "Grass.h"


namespace console::plant
{
    Grass::Grass(): Plant("green", 1.2f, 60.96f, 15.24f) {}

    void Grass::calculateHeight(int time)
    {
        height_ = static_cast<float>(time) * 50.8f;
    }

    void Grass::calculateRootLength(int time)
    {
        rootlength_ = static_cast<float>(time) * 15.24f;
    }
}