//
// Created by keanu on 02.03.2024.
//

#include "RaylibSprite.h"

game::asteroids::RaylibSprite::RaylibSprite(Vector2 position, const std::shared_ptr<asteroids::CollisionTexture> &texture, Vector2 move_direction, float scale): texture_(texture), scale_(scale)
{
    position_ = position;
    hitbox_ = Rectangle({position.x, position.y, static_cast<float>(texture->texture.width), static_cast<float>(texture->texture.height)});
    moveSpeed_ = move_direction;
    aliveCounter_ = 450;
    alive_ = true;
}

game::asteroids::RaylibSprite::~RaylibSprite()
{
}
void game::asteroids::RaylibSprite::update()
{
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

    if (aliveCounter_-- <= 0)
    {
        alive_ = false;
    }

}

Vector2 game::asteroids::RaylibSprite::getPosition()
{
    return position_;
}

Rectangle game::asteroids::RaylibSprite::getHitbox()
{
    return hitbox_;
}

std::vector<std::vector<bool>> game::asteroids::RaylibSprite::get_collision_map()
{
    return texture_->collision_map;
}

void game::asteroids::RaylibSprite::draw()
{
    DrawTexture(texture_->texture, static_cast<int>(position_.x), static_cast<int>(position_.y), WHITE);
}

bool game::asteroids::RaylibSprite::isAlive()
{
    return alive_;
}

float game::asteroids::RaylibSprite::getScale()
{
    return scale_;
}
