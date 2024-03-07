//
// Created by keanu on 06.03.2024.
//

#ifndef RAYLIBSTARTER_BASEENGINE_H
#define RAYLIBSTARTER_BASEENGINE_H

namespace console::car::base::components
{

    class BaseEngine
    {
    public:
        BaseEngine(float horsePower);
        virtual void switchOnOff();
        virtual bool getEngineOn();
        virtual float getHorsePower();

    protected:
        bool isOn_;
        float horsePower_;
    private:
        BaseEngine() = delete;
    };

}

#endif //RAYLIBSTARTER_BASEENGINE_H
