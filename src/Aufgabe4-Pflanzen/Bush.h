//
// Created by keanu on 06.03.2024.
//

#ifndef RAYLIBSTARTER_BUSH_H
#define RAYLIBSTARTER_BUSH_H


#include "Plant.h"

namespace console::plant
{

    class Bush : public Plant
    {
    public:
        Bush();
    private:
        void calculateHeight(int time) override;
        void calculateRootLength(int time) override;
    };

}

#endif //RAYLIBSTARTER_BUSH_H
