//
// Created by keanu on 06.03.2024.
//

#include "Tree.h"


namespace console::plant
{
    Tree::Tree(): Plant("green", 4.5f, 762.0f, 518.16f) {}

    void Tree::calculateHeight(int time)
    {
        height_ = static_cast<float>(time) * 76.2f;
    }

    void Tree::calculateRootLength(int time)
    {
        rootlength_ = static_cast<float>(time) * 51.16f;
    }
}