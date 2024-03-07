//
// Created by keanu on 06.03.2024.
//

#ifndef RAYLIBSTARTER_GRASS_H
#define RAYLIBSTARTER_GRASS_H


#include "Plant.h"

namespace console::plant
{

    class Grass : public Plant
    {
    public:
        Grass();
    private:
        void calculateHeight(int time) override;
        void calculateRootLength(int time) override;
    };

}

#endif //RAYLIBSTARTER_GRASS_H
