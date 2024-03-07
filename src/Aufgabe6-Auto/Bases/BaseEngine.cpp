//
// Created by keanu on 06.03.2024.
//

#include "BaseEngine.h"

namespace console::car::base::components
{
    BaseEngine::BaseEngine(float horsePower): isOn_(false), horsePower_(horsePower){}

    void BaseEngine::switchOnOff()
    {
        isOn_ = !isOn_;
    }

    bool BaseEngine::getEngineOn()
    {
        return isOn_;
    }

    float BaseEngine::getHorsePower()
    {
        return horsePower_;
    }
}