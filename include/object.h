#ifndef OBJECT_H
#define OBJECT_H

#include <map>
#include <SFML/Graphics.hpp>

class Object : public sf::Sprite
{
public:
    enum class Orientation {
        CENTER,
        UP,
        RIGHT,
        LEFT,
        DOWN,
        LEFT_UP,
        RIGHT_UP,
        LEFT_DOWN,
        RIGHT_DOWN
    };
protected :
    virtual void setOrientation(Orientation ori) = 0;
    sf::Texture texture;
};

class Wall : public Object
{
public :
    Wall();
    void setOrientation(Orientation ori) override;
};

class Ground : public Object
{
public :
    Ground();
    void setOrientation(Orientation ori) override;
};

class Perso : public Object
{
};

#endif // OBJECT_H
