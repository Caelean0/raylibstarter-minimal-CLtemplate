//
// Created by keanu on 07.03.2024.
//

#ifndef RAYLIBSTARTER_AUDICAR_H
#define RAYLIBSTARTER_AUDICAR_H


#include "../../Bases/BaseCar.h"

namespace console::car::audi
{

    class AudiCar : public base::BaseCar
    {
    public:
        AudiCar(std::shared_ptr<base::components::BaseEngine> engine, std::shared_ptr<base::components::BaseSuspension> suspension,
                std::shared_ptr<base::components::BaseFrame> frame, std::shared_ptr<base::components::BaseWheels> wheels,
                std::shared_ptr<base::components::BaseBrakes> brakes, std::shared_ptr<base::components::BaseGears> gears);
    private:
        AudiCar() = delete;
    };

}

#endif //RAYLIBSTARTER_AUDICAR_H
