//
// Created by keanu on 02.03.2024.
//

#ifndef RAYLIBSTARTER_RAYLIBSPRITE_H
#define RAYLIBSTARTER_RAYLIBSPRITE_H

#include <string>
#include <vector>
#include <memory>
#include "raylib.h"
#include "AsteroidsSupport.h"


namespace game::asteroids
{
    class RaylibSprite
    {
    public:
        RaylibSprite(Vector2 position, const std::shared_ptr<CollisionTexture> &texture, Vector2 move_direction, float scale);

        ~RaylibSprite();

        void update();
        Vector2 getPosition();

        Rectangle getHitbox();
        std::vector<std::vector<bool>> get_collision_map();

        virtual void draw();

        bool isAlive();
        float getScale();


    protected:
        RaylibSprite() = delete;
        Vector2 position_;
        Rectangle hitbox_;
        const std::shared_ptr<CollisionTexture> texture_;
        Vector2 moveSpeed_;

    private:
        int aliveCounter_;
        const float scale_;
        bool alive_;
    };
}


#endif //RAYLIBSTARTER_RAYLIBSPRITE_H
