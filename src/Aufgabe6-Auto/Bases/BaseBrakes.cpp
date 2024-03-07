//
// Created by keanu on 06.03.2024.
//

#include "BaseBrakes.h"

namespace console::car::base::components
{
    BaseBrakes::BaseBrakes(float brakeingDistanceMultiplier): brakeingDistanceMultiplier_(brakeingDistanceMultiplier) {}

    float BaseBrakes::getBrakeingDistanceMultiplier()
    {
        return brakeingDistanceMultiplier_;
    }
}