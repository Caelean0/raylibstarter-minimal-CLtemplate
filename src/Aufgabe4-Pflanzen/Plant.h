//
// Created by keanu on 06.03.2024.
//

#ifndef RAYLIBSTARTER_PLANT_H
#define RAYLIBSTARTER_PLANT_H


#include <stdexcept>
#include "raylib.h"
#include "PlantSupport.h"

namespace console::plant
{
    class Plant
    {
    private:
        Plant() = delete;
    protected:
        float height_; // Wuchshöhe in Zentimetern
        const float maxSize_;
        float rootlength_;
        const float maxRootLength_;
        const std::string leafColor_;
        float seedDiameter_; // in mm
        virtual void calculateHeight(int time) = 0;
        virtual void calculateRootLength(int time) = 0;
    public:
        Plant(std::string leafColor, float seedDiameter, float maxSize, float maxRootLength);
        virtual ~Plant() = default;

        virtual float getHeight(int timeYears);
        virtual float getRootLength(int timeYears);
        virtual std::string getLeafColor() const;
        virtual float getSeedDiameter() const;
        virtual float getMaxSize() const;
        virtual float getMaxRootLength() const;

    };
}


#endif //RAYLIBSTARTER_PLANT_H
