//
// Created by keanu on 06.03.2024.
//

#include "Plant.h"

console::plant::Plant::Plant(std::string leafColor, float seedDiameter, float maxSize, float maxRootLength): leafColor_(leafColor), seedDiameter_(seedDiameter), maxSize_(maxSize), maxRootLength_(maxRootLength), height_(0), rootlength_(0){};

float console::plant::Plant::getHeight(int timeYears)
{
    calculateHeight(timeYears);

    if (height_ > maxSize_)
    {
        height_ = maxSize_;
    }

    return height_;
}

float console::plant::Plant::getRootLength(int timeYears)
{
    if (rootlength_ > maxRootLength_)
    {
        rootlength_ = maxRootLength_;
    }

    calculateRootLength(timeYears);
    return rootlength_;
}

std::string console::plant::Plant::getLeafColor() const
{
    return leafColor_;
}

float console::plant::Plant::getSeedDiameter() const
{
    return seedDiameter_;
}

float console::plant::Plant::getMaxSize() const
{
    return maxSize_;
}

float console::plant::Plant::getMaxRootLength() const
{
    return maxRootLength_;
}
