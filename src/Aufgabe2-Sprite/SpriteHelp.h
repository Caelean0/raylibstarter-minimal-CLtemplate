//
// Created by keanu on 20.02.2024.
//

#ifndef RAYLIBSTARTER_SPRITEHELP_H
#define RAYLIBSTARTER_SPRITEHELP_H

#include "raylib.h"

namespace game::sprite3D
{
    struct Frame {
        Model model;
        Texture texture;
        void draw(){};
    };

    enum Type {
        animate,
        character,
        object,
        character_animation
    };
}

#endif //RAYLIBSTARTER_SPRITEHELP_H
