//
// Created by keanu on 07.03.2024.
//

#include "MercedesCar.h"



namespace console::car::mercedes
{
    MercedesCar::MercedesCar(std::shared_ptr<base::components::BaseEngine> engine,
                             std::shared_ptr<base::components::BaseSuspension> suspension,
                             std::shared_ptr<base::components::BaseFrame> frame,
                             std::shared_ptr<base::components::BaseWheels> wheels,
                             std::shared_ptr<base::components::BaseBrakes> brakes,
                             std::shared_ptr<base::components::BaseGears> gears):
                             BaseCar(engine, suspension, frame, wheels, brakes, gears) {}
}