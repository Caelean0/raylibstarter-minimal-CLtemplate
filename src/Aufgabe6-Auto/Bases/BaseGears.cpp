//
// Created by keanu on 06.03.2024.
//

#include <string>
#include <stdexcept>
#include "BaseGears.h"

namespace console::car::base::components
{
    BaseGears::BaseGears(std::map<GearShift, float> gearShiftSpeeds): gearShiftSpeeds_(gearShiftSpeeds){}

    GearShift BaseGears::getCurrentGear(float speed)
    {
        for (auto rit = gearShiftSpeeds_.rbegin(); rit != gearShiftSpeeds_.rend(); rit++)
        {
            if (speed >= rit->second)
            {
                return rit->first;
            }
        }
        throw std::runtime_error("No gear found for speed: " + std::to_string(speed));
    }
}