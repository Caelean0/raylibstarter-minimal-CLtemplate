//
// Created by keanu on 06.03.2024.
//

#include "BaseFrame.h"

namespace console::car::base::components
{
    BaseFrame::BaseFrame(float weight): weight_(weight){}

    float BaseFrame::getWeight()
    {
        return weight_;
    }
}