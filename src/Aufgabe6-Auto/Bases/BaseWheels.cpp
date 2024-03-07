//
// Created by keanu on 06.03.2024.
//

#include "BaseWheels.h"

namespace console::car::base::components
{
    BaseWheels::BaseWheels(float frictionMultiplier): frictionMultiplier_(frictionMultiplier){}

    float BaseWheels::getFrictionMultiplier()
    {
        return frictionMultiplier_;
    }
}