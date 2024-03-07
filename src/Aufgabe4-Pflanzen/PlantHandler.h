//
// Created by keanu on 06.03.2024.
//

#ifndef RAYLIBSTARTER_PLANTHANDLER_H
#define RAYLIBSTARTER_PLANTHANDLER_H


#include "PlantSupport.h"
#include "Plant.h"

namespace console::plant
{

    class PlantHandler
    {
    public:
        PlantHandler();
        int handleUser();
    private:
        Plant *plantFrame_;
    };

}

#endif //RAYLIBSTARTER_PLANTHANDLER_H
