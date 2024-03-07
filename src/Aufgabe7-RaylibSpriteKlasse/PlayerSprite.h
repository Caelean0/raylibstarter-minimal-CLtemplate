//
// Created by keanu on 03.03.2024.
//

#ifndef RAYLIBSTARTER_PLAYERSPRITE_H
#define RAYLIBSTARTER_PLAYERSPRITE_H


#include "RaylibSprite.h"
#include "AsteroidsSupport.h"


namespace game::asteroids
{
    class PlayerSprite : public RaylibSprite
    {
    public:
        PlayerSprite(Vector2 position, const std::shared_ptr<CollisionTexture> &texture, Vector2 move_direction);
        ~PlayerSprite();
        void draw() override;
        void update(bool isAccelerating, Rotates rotationDirection);
        int getRotation();
    private:
        float rotationDegrees_;
        SpeedState speedState_;

        void updateSpeed(bool isAccelerating);
        bool accelerate();
        bool decelerate();
    };
}


#endif //RAYLIBSTARTER_PLAYERSPRITE_H
