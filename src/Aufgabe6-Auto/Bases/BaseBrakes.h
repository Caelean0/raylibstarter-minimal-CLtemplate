//
// Created by keanu on 06.03.2024.
//

#ifndef RAYLIBSTARTER_BASEBRAKES_H
#define RAYLIBSTARTER_BASEBRAKES_H


namespace console::car::base::components
{

    class BaseBrakes
    {
    public:
        BaseBrakes(float brakeingDistanceMultiplier);
        virtual float getBrakeingDistanceMultiplier();

    protected:
        float brakeingDistanceMultiplier_;
    private:
        BaseBrakes() = delete;
    };

}
#endif //RAYLIBSTARTER_BASEBRAKES_H
