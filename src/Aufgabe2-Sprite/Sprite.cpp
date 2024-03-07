//
// Created by keanu on 20.02.2024.
//

#include "Sprite.h"
#include "SpriteHelp.h"

game::sprite3D::Sprite::Sprite(int _width, int _height, int _animationFrames, std::vector<game::sprite3D::Frame> *_frames, game::sprite3D::Type _type, bool _drawable, Vector3 _coordinates): animationFrames(_animationFrames), height(_height), width(_width), frames(new std::vector<game::sprite3D::Frame>(*_frames)), type(_type)
{
    this->coordinates = _coordinates;
    this->drawable = _drawable;
    this->currentFrame = 0;
}

game::sprite3D::Sprite::~Sprite()
{
    delete frames;
}

void game::sprite3D::Sprite::draw()
{
    if (drawable)
    {
        frames->at(currentFrame).draw();
        currentFrame++;
    }
}

void game::sprite3D::Sprite::update(Vector3 _newCoordinates)
{
    this->coordinates = _newCoordinates;
}
