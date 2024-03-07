//
// Created by keanu on 03.03.2024.
//

#ifndef RAYLIBSTARTER_ASTEROIDSSUPPORT_H
#define RAYLIBSTARTER_ASTEROIDSSUPPORT_H

#include <vector>
#include <string>
#include "raylib.h"


namespace game::asteroids
{
    struct CollisionTexture
    {
        const Texture2D texture;
        std::vector<std::vector<bool>> collision_map;
        const std::string texture_path;
        CollisionTexture(std::string textue_path): texture(LoadTexture(textue_path.c_str())), texture_path(textue_path) { collision_map = render_Collision_map(); };
        void unload() { UnloadTexture(texture);};
        private:
        CollisionTexture() = delete;
        std::vector<std::vector<bool>> render_Collision_map()
        {
            std::vector<std::vector<bool>> preMap(texture.width, std::vector<bool>(texture.height, false));
            Image renderImage = LoadImageFromTexture(texture);

            for (int y = 0; y < renderImage.height; y++)
            {
                for (int x = 0; x < renderImage.width; x++)
                {
                    Color pixel = GetImageColor(renderImage, x, y);
                    if (pixel.a > 0)
                    {
                        preMap[y][x] = true;
                    } else {
                        preMap[y][x] = false;
                    }
                }
            }
            return preMap;
        };
    };

    enum SpeedState
    {
        resting,
        accelerating,
        full_speed,
        decelerating
    };
    enum Rotates
    {
        left,
        neutral,
        right
    };
    enum gameState
    {
        running,
        dead
    };

    static gameState gameState_;
}




#endif //RAYLIBSTARTER_ASTEROIDSSUPPORT_H
