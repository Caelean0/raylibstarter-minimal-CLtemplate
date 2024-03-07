//
// Created by keanu on 07.03.2024.
//

#ifndef RAYLIBSTARTER_MERCEDESCAR_H
#define RAYLIBSTARTER_MERCEDESCAR_H


#include "../../Bases/BaseCar.h"

namespace console::car::mercedes
{

    class MercedesCar : public base::BaseCar
    {
    public:
        MercedesCar(std::shared_ptr<base::components::BaseEngine> engine, std::shared_ptr<base::components::BaseSuspension> suspension,
                    std::shared_ptr<base::components::BaseFrame> frame, std::shared_ptr<base::components::BaseWheels> wheels,
                    std::shared_ptr<base::components::BaseBrakes> brakes, std::shared_ptr<base::components::BaseGears> gears);
    private:
        MercedesCar() = delete;
    };

}

#endif //RAYLIBSTARTER_MERCEDESCAR_H
