//
// Created by keanu on 06.03.2024.
//

#ifndef RAYLIBSTARTER_BASEFRAME_H
#define RAYLIBSTARTER_BASEFRAME_H

namespace console::car::base::components
{

    class BaseFrame
    {
    public:
        BaseFrame(float weight);
        virtual float getWeight();
    protected:
        float weight_;
    private:
        BaseFrame() = delete;
    };

}

#endif //RAYLIBSTARTER_BASEFRAME_H
