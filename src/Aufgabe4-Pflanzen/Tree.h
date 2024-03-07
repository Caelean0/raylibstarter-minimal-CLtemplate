//
// Created by keanu on 06.03.2024.
//

#ifndef RAYLIBSTARTER_TREE_H
#define RAYLIBSTARTER_TREE_H


#include "Plant.h"

namespace console::plant
{

    class Tree : public Plant
    {
    public:
        Tree();
    private:
        void calculateHeight(int time) override;
        void calculateRootLength(int time) override;
    };

}

#endif //RAYLIBSTARTER_TREE_H
