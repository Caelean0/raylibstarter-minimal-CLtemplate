//
// Created by keanu on 03.03.2024.
//

#ifndef RAYLIBSTARTER_LEVEL_H
#define RAYLIBSTARTER_LEVEL_H

#include <vector>
#include <memory>
#include "../Aufgabe7-RaylibSpriteKlasse/RaylibSprite.h"
#include "../Aufgabe5-CustomDynamicArray/CustomDynamicArray.h"
#include "../Aufgabe5-CustomDynamicArray/CustomDynamicArray.hpp"
#include "../Aufgabe7-RaylibSpriteKlasse/PlayerSprite.h"



namespace game::asteroids
{
    class Level
    {
    public:
        Level(const std::vector<std::shared_ptr<CollisionTexture>> &textures);
        ~Level();
        void draw();
        void update();
        bool getAlive();

    private:
        Level() = delete;
        const std::vector<std::shared_ptr<CollisionTexture>> textures_;
        memory::CustomVector<std::shared_ptr<RaylibSprite>> asteroids_;
        const std::shared_ptr<PlayerSprite> player_;
        int lifeCounter_;
        int invincibilityCounter_;
        int spawnTimer_;
        bool isAlive;
//        std::vector<std::shared_ptr<game::CollisionTexture>> textures_;
        bool playerCollides();
        void spawnAsteroids();


    };
}


#endif //RAYLIBSTARTER_LEVEL_H
