//
// Created by keanu on 06.03.2024.
//

#ifndef RAYLIBSTARTER_BASEGEARS_H
#define RAYLIBSTARTER_BASEGEARS_H


#include <map>
#include "../CarSupport.h"

namespace console::car::base::components
{

    class BaseGears
    {
    public:
        BaseGears(std::map<GearShift, float> gearShiftSpeeds);
        virtual GearShift getCurrentGear(float speed);
    protected:
        std::map<GearShift, float> gearShiftSpeeds_;
    private:
        BaseGears() = delete;
    };

}




#endif //RAYLIBSTARTER_BASEGEARS_H
