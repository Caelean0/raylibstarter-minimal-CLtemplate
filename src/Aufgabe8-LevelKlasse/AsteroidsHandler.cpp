//
// Created by keanu on 04.03.2024.
//

#include "AsteroidsHandler.h"
#include "Level.h"

game::asteroids::AsteroidsHandler::AsteroidsHandler()
{


    CollisionTexture player = CollisionTexture("assets/graphics/asteroids/Player.png");
//    std::vector<std::shared_ptr<game::CollisionTexture>> textures = {std::make_shared<game::CollisionTexture>(player), std::make_shared<game::CollisionTexture>(game::CollisionTexture("assets/graphics/asteroids/AsteroidBig.png")), std::make_shared<game::CollisionTexture>(game::CollisionTexture("assets/graphics/asteroids/AsteroidMiddle.png")), std::make_shared<game::CollisionTexture>(game::CollisionTexture("assets/graphics/asteroids/AsteroidSmall.png"))};
    textures_ = std::vector<std::shared_ptr<CollisionTexture>>(std::vector<std::shared_ptr<CollisionTexture>>{std::make_shared<CollisionTexture>(player), std::make_shared<CollisionTexture>(
            CollisionTexture("assets/graphics/asteroids/AsteroidBig.png")), std::make_shared<CollisionTexture>(
            CollisionTexture("assets/graphics/asteroids/AsteroidMiddle.png")), std::make_shared<CollisionTexture>(
            CollisionTexture("assets/graphics/asteroids/AsteroidSmall.png"))});

//    std::vector<std::shared_ptr<game::RaylibSprite>> sprites = {std::make_shared<game::PlayerSprite>(game::PlayerSprite()), std::make_shared<game::RaylibSprite>(game::RaylibSprite({0, 0}, textures_[0], {0, 0}, 1))};
//    loadedSprites_ = std::make_shared<std::vector<std::shared_ptr<game::RaylibSprite>>>(sprites);

    level_ = new Level(textures_);

    game::asteroids::gameState_ = gameState::running;
}

game::asteroids::AsteroidsHandler::~AsteroidsHandler()
{

}

void game::asteroids::AsteroidsHandler::draw()
{
    if (game::asteroids::gameState_ == gameState::running)
    {
        level_->draw();
    } else {
        DrawText("Game Over", 730, 500, 100, WHITE);
    }
}

void game::asteroids::AsteroidsHandler::update()
{
    if (game::asteroids::gameState_ == gameState::running)
    {
        if (level_->getAlive())
        {
            level_->update();
        } else
        {
            game::asteroids::gameState_ = gameState::dead;
            delete level_;
            level_ = nullptr;
        }
    }
}
