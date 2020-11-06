#include "object.h"

/****************************************** WALL *************************************************/

Wall::Wall()
{
    texture.loadFromFile("../resources/laby.png");
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

/****************************************** GROUND ***********************************************/

Ground::Ground()
{
    texture.loadFromFile("../resources/laby.png");
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
