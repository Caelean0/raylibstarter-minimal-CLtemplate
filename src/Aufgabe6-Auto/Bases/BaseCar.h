//
// Created by keanu on 06.03.2024.
//

#ifndef RAYLIBSTARTER_BASECAR_H
#define RAYLIBSTARTER_BASECAR_H

#include <memory>
#include "../CarSupport.h"
#include "BaseEngine.h"
#include "BaseSuspension.h"
#include "BaseFrame.h"
#include "BaseWheels.h"
#include "BaseBrakes.h"
#include "BaseGears.h"

namespace console::car::base
{

    class BaseCar
    {
    public:
        BaseCar(std::shared_ptr<components::BaseEngine> engine, std::shared_ptr<components::BaseSuspension> suspension,
                std::shared_ptr<components::BaseFrame> frame, std::shared_ptr<components::BaseWheels> wheels,
                std::shared_ptr<components::BaseBrakes> brakes, std::shared_ptr<components::BaseGears> gears);

        virtual void startStopEngine();
        virtual bool getEngineOn();

        virtual void setTurnDirection(Turn turn);
        virtual Turn getTurnDirection();

        virtual void setDriveDirection(Direction driveDirection);
        virtual Direction getDriveDirection();

        virtual long double accelerate(int accelerationTime);
        virtual long double brake();
        long double getBrainDamagePercent(long double brakeingDistance);

        virtual long double getSpeed();
        GearShift getCurrentGear();

        virtual MovementState getMovementState();
        virtual void setMovementState(MovementState movementState);

    protected:
        std::shared_ptr<components::BaseEngine> engine_;
        std::shared_ptr<components::BaseSuspension> suspension_;
        std::shared_ptr<components::BaseFrame> frame_;
        std::shared_ptr<components::BaseWheels> wheels_;
        std::shared_ptr<components::BaseBrakes> brakes_;
        std::shared_ptr<components::BaseGears> gears_;

        Direction driveDirection_;
        Turn turn_;
        MovementState movementState_;
        long double speed_;
    private:
        BaseCar() = delete;
    };

}

#endif //RAYLIBSTARTER_BASECAR_H
