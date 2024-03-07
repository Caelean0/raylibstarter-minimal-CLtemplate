//
// Created by keanu on 03.03.2024.
//

#include "Level.h"

#include <utility>

game::asteroids::Level::Level(const std::vector<std::shared_ptr<CollisionTexture>> &textures) :
        textures_(textures), asteroids_(memory::CustomVector<std::shared_ptr<RaylibSprite>>(48)),
        player_(std::make_shared<PlayerSprite>(
                PlayerSprite({static_cast<float>( GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2)}, textures[0], {0, 0})))
{
    lifeCounter_ = 3;
    isAlive = true;
    invincibilityCounter_ = 180;
    spawnAsteroids();
    spawnTimer_ = 300;

}
game::asteroids::Level::~Level()
{
    for (int i = 0; i < 4; i++)
    {
        textures_[i]->unload();
    }
};

void game::asteroids::Level::draw()
{
    std::string lives = "Lives Remaining: " + std::to_string(lifeCounter_);
    DrawText(lives.c_str(), 10, 10, 20, WHITE);
    player_->draw();
    for (auto &asteroid : asteroids_)
    {
        asteroid->draw();
    }
}



void game::asteroids::Level::update()
{
    bool isAccelerating = (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP));
    Rotates rotationDirection = (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) ? right : (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) ? left : neutral;
    player_->update(isAccelerating, rotationDirection);
    for (int i = 0; i < asteroids_.getWrittenSize(); i++)
    {
        asteroids_[i]->update();
        if (!asteroids_[i]->isAlive())
        {
            if (asteroids_[i] -> getScale() == 1)
            {
                asteroids_.add(std::make_shared<RaylibSprite>(RaylibSprite(asteroids_[i]->getPosition(), textures_[2], {static_cast<float>(GetRandomValue(-5, 5)), static_cast<float>(GetRandomValue(-5, 5))}, asteroids_[i]->getScale() / 2)));
                asteroids_.add(std::make_shared<RaylibSprite>(RaylibSprite(asteroids_[i]->getPosition(), textures_[2], {static_cast<float>(GetRandomValue(-5, 5)), static_cast<float>(GetRandomValue(-5, 5))}, asteroids_[i]->getScale() / 2)));
            } else if (asteroids_[i] -> getScale() == 0.5) {
                asteroids_.add(std::make_shared<RaylibSprite>(RaylibSprite(asteroids_[i]->getPosition(), textures_[3], {static_cast<float>(GetRandomValue(-5, 5)), static_cast<float>(GetRandomValue(-5, 5))}, asteroids_[i]->getScale() / 2)));
                asteroids_.add(std::make_shared<RaylibSprite>(RaylibSprite(asteroids_[i]->getPosition(), textures_[3], {static_cast<float>(GetRandomValue(-5, 5)), static_cast<float>(GetRandomValue(-5, 5))}, asteroids_[i]->getScale() / 2)));
            }
            asteroids_.remove(i);
        }
    }

    if (invincibilityCounter_ > 0)
    {
        invincibilityCounter_--;
    } else if (playerCollides())
    {
        if (--lifeCounter_ <= 0)
        {
            isAlive = false;
        } else {
            invincibilityCounter_ = 180;
        }
    }
    if (spawnTimer_-- <= 0)
    {
        spawnAsteroids();
    }

}

bool game::asteroids::Level::playerCollides()
{
    Rectangle hitboxPlayer = player_->getHitbox();
    for (int f = 0; f < asteroids_.getWrittenSize(); f++)
    {
        Rectangle hitboxAsteroid = asteroids_[f]->getHitbox();
        if (CheckCollisionRecs(hitboxPlayer, hitboxAsteroid))
        {
            Rectangle intersection = GetCollisionRec(hitboxPlayer, hitboxAsteroid);
            std::vector<std::vector<bool>> collisionMapPlayer = player_->get_collision_map();
            std::vector<std::vector<bool>> collisionMapAsteroid = asteroids_[f]->get_collision_map();
            for (int i = 0; i < static_cast<int>(intersection.width); i++)
            {
                for (int j = 0; j < static_cast<int>(intersection.height); j++)
                {
                    bool playerCollision = collisionMapPlayer[static_cast<unsigned int>(intersection.y - hitboxPlayer.y) + j][static_cast<unsigned int>(intersection.x - hitboxPlayer.x) + i];
                    bool asteroidCollision = collisionMapAsteroid[static_cast<unsigned int>(intersection.y - hitboxAsteroid.y) + j][static_cast<unsigned int>(intersection.x - hitboxAsteroid.x) + i];
                    if (playerCollision && asteroidCollision)
                    {
                        return true;
                    }
                }
            }


        }
    }
    return false;
}

bool game::asteroids::Level::getAlive()
{
    return isAlive;
}

void game::asteroids::Level::spawnAsteroids()
{
    for (int amount = 0; amount < GetRandomValue(1,4); amount++)
    {
        asteroids_.add(std::make_shared<RaylibSprite>(RaylibSprite({static_cast<float>( GetRandomValue(0, GetScreenWidth())), static_cast<float>( GetRandomValue(0, GetScreenHeight()))}, textures_[1], {static_cast<float>( GetRandomValue(-5, 5)), static_cast<float>( GetRandomValue(-5, 5))}, 1)));
    }
    spawnTimer_ = 300;

}


