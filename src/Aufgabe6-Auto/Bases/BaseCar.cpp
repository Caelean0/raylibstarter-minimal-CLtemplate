//
// Created by keanu on 06.03.2024.
//

#include <valarray>
#include "BaseCar.h"



namespace console::car::base
{

    BaseCar::BaseCar(std::shared_ptr<components::BaseEngine> engine,
                     std::shared_ptr<components::BaseSuspension> suspension,
                     std::shared_ptr<components::BaseFrame> frame, std::shared_ptr<components::BaseWheels> wheels,
                     std::shared_ptr<components::BaseBrakes> brakes, std::shared_ptr<components::BaseGears> gears):
            engine_(engine), suspension_(suspension), frame_(frame), wheels_(wheels), brakes_(brakes), gears_(gears),
            driveDirection_(forward), turn_(straight), movementState_(resting), speed_(0.0f){}

    void BaseCar::startStopEngine()
    {
        engine_->switchOnOff();
    }
    bool BaseCar::getEngineOn()
    {
        return engine_->getEngineOn();
    }

    void BaseCar::setTurnDirection(Turn turn)
    {
        turn_ = turn;
    }
    Turn BaseCar::getTurnDirection()
    {
        return turn_;
    }

    void BaseCar::setDriveDirection(Direction driveDirection)
    {
        driveDirection_ = driveDirection;
    }
    Direction BaseCar::getDriveDirection()
    {
        return driveDirection_;
    }

    long double BaseCar::accelerate(int accelerationTime)
    {
        long double acceleration;
        long double mass = frame_->getWeight();
        long double horsePower = engine_->getHorsePower();
        long double turnMultiplier = 1;
        long double directionMultiplier = 1;
        if (turn_ != straight)
        {
            turnMultiplier = 0.7f;
        }
        if (driveDirection_ != forward)
        {
            directionMultiplier = 0.5f;
        }
        acceleration = static_cast<long double>(std::sqrt( horsePower * 745.6992 / (2 * mass)) );
        acceleration *= wheels_->getFrictionMultiplier() * turnMultiplier * directionMultiplier;
        speed_ = speed_ + acceleration * static_cast<long double>(accelerationTime);
        return acceleration;
    }
    long double BaseCar::brake()
    {
        long double brakeingDistance;
        brakeingDistance = (speed_ * speed_) / (250 * wheels_->getFrictionMultiplier() *
                                                brakes_->getBrakeingDistanceMultiplier());
        speed_ = 0;
        return brakeingDistance;
    }

    MovementState BaseCar::getMovementState()
    {
        return movementState_;
    }
    void BaseCar::setMovementState(MovementState movementState)
    {
        movementState_ = movementState;
    }

    long double BaseCar::getSpeed()
    {
        return speed_;
    }

    GearShift BaseCar::getCurrentGear()
    {
        return gears_->getCurrentGear(speed_);
    }

    long double BaseCar::getBrainDamagePercent(long double brakeingDistance)
    {
        return brakeingDistance * suspension_->getBrainDamageDamping();
    }
}