//
// Created by keanu on 07.03.2024.
//

#ifndef RAYLIBSTARTER_CARHANDLER_H
#define RAYLIBSTARTER_CARHANDLER_H


#include "Bases/BaseCar.h"

namespace console::car
{
    class CarHandler
    {
    public:
        CarHandler();
        int handleUser();
    private:
        base::BaseCar *carFrame_;
        std::shared_ptr<base::components::BaseEngine> engine_;
        std::shared_ptr<base::components::BaseBrakes> brakes_;
        std::shared_ptr<base::components::BaseWheels> wheels_;
        std::shared_ptr<base::components::BaseFrame> frame_;
        std::shared_ptr<base::components::BaseGears> gears_;
        std::shared_ptr<base::components::BaseSuspension> suspension_;
    };

}
#endif //RAYLIBSTARTER_CARHANDLER_H
