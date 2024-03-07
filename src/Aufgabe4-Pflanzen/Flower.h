//
// Created by keanu on 06.03.2024.
//

#ifndef RAYLIBSTARTER_FLOWER_H
#define RAYLIBSTARTER_FLOWER_H


#include "Plant.h"

namespace console::plant
{

    class Flower : public Plant
    {
    public:
        Flower();
    private:
        void calculateHeight(int time) override;
        void calculateRootLength(int time) override;
    };

}

#endif //RAYLIBSTARTER_FLOWER_H
