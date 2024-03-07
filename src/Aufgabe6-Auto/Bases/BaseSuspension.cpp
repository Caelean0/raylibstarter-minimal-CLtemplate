//
// Created by keanu on 06.03.2024.
//

#include "BaseSuspension.h"

namespace console::car::base::components
{
    BaseSuspension::BaseSuspension(float brainDamageDamping): brainDamageDamping_(brainDamageDamping) {}

    float BaseSuspension::getBrainDamageDamping()
    {
        return brainDamageDamping_;
    }
}