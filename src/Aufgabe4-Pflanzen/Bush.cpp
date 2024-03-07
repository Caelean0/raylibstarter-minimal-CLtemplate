//
// Created by keanu on 06.03.2024.
//

#include "Bush.h"


namespace console::plant
{
    Bush::Bush(): Plant("green", 1.3f, 213.36f, 17.78f) {}

    void Bush::calculateHeight(int time)
    {
        height_ = static_cast<float>(time) * 76.2f;
    }

    void Bush::calculateRootLength(int time)
    {
        rootlength_ = static_cast<float>(time) * 5.78f;
    }
}