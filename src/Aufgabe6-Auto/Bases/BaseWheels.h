//
// Created by keanu on 06.03.2024.
//

#ifndef RAYLIBSTARTER_BASEWHEELS_H
#define RAYLIBSTARTER_BASEWHEELS_H


namespace console::car::base::components
{

    class BaseWheels
    {
    public:
        BaseWheels(float frictionMultiplier);
        virtual float getFrictionMultiplier();

    protected:
        float frictionMultiplier_;
    private:
        BaseWheels() = delete;
    };

}

#endif //RAYLIBSTARTER_BASEWHEELS_H
