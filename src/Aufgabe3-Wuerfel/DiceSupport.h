//
// Created by keanu on 05.03.2024.
//

#ifndef RAYLIBSTARTER_DICESUPPORT_H
#define RAYLIBSTARTER_DICESUPPORT_H

#include <string>
#include <map>
#include "raylib.h"

namespace game::dice
{
    enum Faces
    {
        d4 = 4,
        d6 = 6,
        d8 = 8,
        d10 = 10,
        d12 = 12,
        d20 = 20
    };

    static std::map<Faces, std::string> facesToText = {
            {d4, "d4"},
            {d6, "d6"},
            {d8, "d8"},
            {d10, "d10"},
            {d12, "d12"},
            {d20, "d20"}
    };
}

#endif //RAYLIBSTARTER_DICESUPPORT_H
