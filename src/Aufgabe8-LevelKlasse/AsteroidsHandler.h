//
// Created by keanu on 04.03.2024.
//

#ifndef RAYLIBSTARTER_ASTEROIDSHANDLER_H
#define RAYLIBSTARTER_ASTEROIDSHANDLER_H


#include <memory>
#include <vector>
#include "../Aufgabe7-RaylibSpriteKlasse/RaylibSprite.h"
#include "Level.h"


namespace game::asteroids
{
    class AsteroidsHandler
    {
    public:
        AsteroidsHandler();
        ~AsteroidsHandler();
        void draw();
        void update();

    private:
        std::vector<std::shared_ptr<CollisionTexture>> textures_;
        Level *level_;
    };
}



#endif //RAYLIBSTARTER_ASTEROIDSHANDLER_H
