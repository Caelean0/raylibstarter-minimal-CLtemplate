//
// Created by keanu on 20.02.2024.
//

#ifndef RAYLIBSTARTER_SPRITE_H
#define RAYLIBSTARTER_SPRITE_H


#include <vector>
#include "raylib.h"
#include "SpriteHelp.h"


namespace game::sprite3D
{
    class Sprite
    {
    public:
        Sprite(int _width, int _height, int _animationFrames, std::vector<Frame> *_frames, Type _type, bool _drawable, Vector3 _coordinates);

        ~Sprite();
        void draw();
        void update(Vector3 _newCoordinates);


    private:
        Sprite();

        Vector3 coordinates;

        const int animationFrames;
        int currentFrame;
        bool drawable;

        const Type type;

        const int width;

        const int height;
        std::vector<Frame> *frames;
    };
}


#endif //RAYLIBSTARTER_SPRITE_H
