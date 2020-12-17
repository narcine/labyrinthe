#include "object.h"
#include <iostream>

Object::Object(Type type, Layer layer)
{
    this->type = type;
    this->layer = layer;
}

void Object::setLayer(Layer layer)
{
    this->layer = layer;
}

Object::Layer Object::getLayer()
{
    return this->layer;
}

/**************************************** Wall*****************************************************/

Wall::Wall(): Object(Type::WALL, Layer::LAYER_1)
{
    texture.loadFromFile("../resources/labyTile.png");
    setTexture(texture);
    setOrientation(Orientation::CENTER);
}

Wall::Wall(Layer layer): Object(Type::WALL, layer)
{
    texture.loadFromFile("../resources/labyTile.png");
    setTexture(texture);
    setOrientation(Orientation::CENTER);
}

void Wall::setOrientation(Orientation ori)
{
    switch(ori)
    {
        case Orientation::CENTER:
        default:
            setTextureRect(sf::IntRect(35, 0, 35, 35));
        break;
    }

}

/**************************************** Ground *****************************************************/

Ground::Ground(): Object(Type::GROUND, Layer::LAYER_0)
{
    texture.loadFromFile("../resources/labyTile.png");
    setTexture(texture);
    setOrientation(Orientation::CENTER);
}

Ground::Ground(Layer layer): Object(Type::GROUND, layer)
{
    texture.loadFromFile("../resources/labyTile.png");
    setTexture(texture);
    setOrientation(Orientation::CENTER);
}

void Ground::setOrientation(Orientation ori)
{
    switch(ori)
    {
        case Orientation::CENTER:
        default:
            setTextureRect(sf::IntRect(0, 0, 35, 35));
        break;
    }
}
