//
// Created by keanu on 03.03.2024.
//

#include "PlayerSprite.h"


#include <cmath>

game::asteroids::PlayerSprite::PlayerSprite(Vector2 position, const std::shared_ptr<asteroids::CollisionTexture> &texture, Vector2 move_direction)
        : RaylibSprite(position, texture, move_direction, 1)
{
    speedState_ = resting;
    rotationDegrees_ = 0.0f;
}

game::asteroids::PlayerSprite::~PlayerSprite()
{

}

void game::asteroids::PlayerSprite::draw()
{
    float rotationRad = rotationDegrees_;
    DrawTexturePro(texture_->texture,
                   {0, 0, static_cast<float>( texture_->texture.width),static_cast<float>( texture_->texture.height)},
                   {position_.x, position_.y,static_cast<float> (texture_->texture.width),static_cast<float> (texture_->texture.height)},
                   {static_cast<float>(texture_->texture.width)/2.0f, static_cast<float>(texture_->texture.height)/2.0f},
                   rotationRad, WHITE);
}

void game::asteroids::PlayerSprite::update(bool isAccelerating, asteroids::Rotates rotationDirection)
{
    switch (rotationDirection)
    {
        case neutral:
            break;
        case right:
            if (rotationDegrees_ == 355)
            {
                rotationDegrees_ = 0;
                break;
            }
            rotationDegrees_ += 5;
            break;
        case left:
            if (rotationDegrees_ == 0)
            {
                rotationDegrees_ = 355;
                break;
            }
            rotationDegrees_ -= 5;
            break;
    }

    updateSpeed(isAccelerating);
    position_.x += moveSpeed_.x;
    position_.y += moveSpeed_.y;
    if (position_.x + hitbox_.width < 0)
    {
        position_.x = GetScreenWidth();
    }
    if (position_.x > GetScreenWidth())
    {
        position_.x = 0 - hitbox_.width;
    }
    if (position_.y + hitbox_.height < 0)
    {
        position_.y = GetScreenHeight();
    }
    if (position_.y > GetScreenHeight())
    {
        position_.y = 0 - hitbox_.height;
    }
    hitbox_.x = position_.x;
    hitbox_.y = position_.y;
}

int game::asteroids::PlayerSprite::getRotation()
{
    return rotationDegrees_;
}

void game::asteroids::PlayerSprite::updateSpeed(bool isAccelerating)
{
    switch (speedState_)
    {
        case resting:
            if (isAccelerating)
            {
                speedState_ = accelerating;
            }
            break;
        case accelerating:
            if (!isAccelerating)
            {
                speedState_ = decelerating;
                break;
            }
            if (accelerate())
            {
                speedState_ = full_speed;
            }
            break;
        case decelerating:
            if (isAccelerating)
            {
                speedState_ = accelerating;
                break;
            }
            if (decelerate())
            {
                speedState_ = resting;
            }
            break;
        case full_speed:
            if (!isAccelerating)
            {
                speedState_ = decelerating;
            }
            break;


    }
}

bool game::asteroids::PlayerSprite::accelerate()
{
    float multiplierXMax = 0.4f;
    float multiplierYMax = 0.4f;

    bool fullX = false;
    bool fullY = false;

    float rotationRad = rotationDegrees_ * DEG2RAD;
    float multiplierXAbsolute = multiplierXMax * std::cos(rotationRad);
    float multiplierYAbsolute = multiplierYMax * std::sin(rotationRad);

    if (moveSpeed_.x + multiplierXAbsolute >= 5.0f || moveSpeed_.x + multiplierXAbsolute <= -5.0f)
    {
        multiplierXAbsolute = 0;
        fullX = true;
    }
    if (moveSpeed_.y + multiplierYAbsolute >= 5.0f || moveSpeed_.y + multiplierYAbsolute <= -5.0f)
    {
        multiplierYAbsolute = 0;
        fullY = true;
    }

    moveSpeed_.x += multiplierXAbsolute;
    moveSpeed_.y += multiplierYAbsolute;
    if (fullX && fullY)
    {
        return true;
    }
    return false;

    /*if (rotationDegrees_ > 0 && rotationDegrees_ < 90)
    {
        multiplierXMax *= (rotationDegrees_ / 90);
        multiplierYMax *= (1 - multiplierXMax);

        if (moveSpeed_.x >= 5.0f)
        {
            multiplierXMax = 0;
            fullX = true;
        }
        if (moveSpeed_.y >= 5.0f)
        {
            multiplierYMax = 0;
            fullY = true;
        }

    } else if (rotationDegrees_ > 90 && rotationDegrees_ < 180)
    {
        multiplierXMax *= (1 - ((rotationDegrees_ - 90) / 90));
        multiplierYMax *= (1 - multiplierXMax);
        multiplierYMax *= (-1);

        if (moveSpeed_.x >= 5.0f)
        {
            multiplierXMax = 0;
            fullX = true;
        }
        if (moveSpeed_.y <= -5.0f)
        {
            multiplierYMax = 0;
            fullY = true;
        }

    } else if (rotationDegrees_ > 180 && rotationDegrees_ < 270) {
        multiplierXMax *= ((rotationDegrees_ - 180) / 90);
        multiplierYMax *= (1 - multiplierXMax);
        multiplierXMax *= (-1);
        multiplierYMax *= (-1);

        if (moveSpeed_.x <= -5.0f)
        {
            multiplierXMax = 0;
            fullX = true;
        }
        if (moveSpeed_.y <= -5.0f)
        {
            multiplierYMax = 0;
            fullY = true;
        }

    } else if (rotationDegrees_ > 270 && rotationDegrees_ < 360) {
        multiplierXMax *= (1 - ((rotationDegrees_ - 270) / 90));
        multiplierYMax *= (1 - multiplierXMax);
        multiplierXMax *= (-1);

        if (moveSpeed_.x <= -5.0f)
        {
            multiplierXMax = 0;
            fullX = true;
        }
        if (moveSpeed_.y >= 5.0f)
        {
            multiplierYMax = 0;
            fullY = true;
        }

    } else if (rotationDegrees_ == 0) {
        multiplierXMax = 0;
        if (moveSpeed_.y >= 5.0f)
        {
            multiplierYMax = 0;
            fullY = true;
        }

    } else if (rotationDegrees_ == 90) {
        multiplierYMax = 0;
        if (moveSpeed_.x >= 5.0f)
        {
            multiplierXMax = 0;
            fullX = true;
        }

    } else if (rotationDegrees_ == 180) {
        multiplierXMax = 0;
        multiplierYMax *= (-1);
        if (moveSpeed_.y <= -5.0f)
        {
            multiplierYMax = 0;
            fullY = true;
        }

    } else if (rotationDegrees_ == 270) {
        multiplierYMax = 0;
        multiplierXMax *= (-1);
        if (moveSpeed_.x <= -5.0f)
        {
            multiplierXMax = 0;
            fullX = true;
        }

    }


    moveSpeed_.x += multiplierXMax;
    moveSpeed_.y += multiplierYMax;
    if (fullX && fullY)
    {
        return true;
    }
    return false;*/

}

bool game::asteroids::PlayerSprite::decelerate()
{
    float multiplierX = 0.1f;
    float multiplierY = 0.1f;

    bool stopX = false;
    bool stopY = false;

    if (moveSpeed_.x == 0)
    {
        stopX = true;
        multiplierX = 0;
    }
    if (moveSpeed_.y == 0)
    {
        stopY = true;
        multiplierY = 0;
    }

    if (moveSpeed_.x < 0)
    {
        moveSpeed_.x += multiplierX;
        if (moveSpeed_.x >= 0)
        {
            stopX = true;
            moveSpeed_.x = 0;
        }
    } else if (moveSpeed_.x > 0)
    {
        moveSpeed_.x -= multiplierX;
        if (moveSpeed_.x <= 0)
        {
            stopX = true;
            moveSpeed_.x = 0;
        }
    }
    if (moveSpeed_.y < 0)
    {
        moveSpeed_.y += multiplierY;
        if (moveSpeed_.y >= 0)
        {
            stopY = true;
            moveSpeed_.y = 0;
        }
    } else if (moveSpeed_.y > 0)
    {
        moveSpeed_.y -= multiplierY;
        if (moveSpeed_.y <= 0)
        {
            stopY = true;
            moveSpeed_.y = 0;
        }
    }
    if (stopX && stopY)
    {
        return true;
    }
    return false;
}
