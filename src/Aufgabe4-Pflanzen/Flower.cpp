//
// Created by keanu on 06.03.2024.
//

#include "Flower.h"


namespace console::plant
{

    Flower::Flower(): Plant("violet", 0.5f, 76.2f, 26.3f) {}

    void Flower::calculateHeight(int time)
    {
        height_ = static_cast<float>(time) * 15.24f;
    }

    void Flower::calculateRootLength(int time)
    {
        rootlength_ = static_cast<float>(time) * 5.26f;
    }
}
