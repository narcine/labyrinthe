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
    enum class Type {
        EMPTY = -1,
        GROUND,
        WALL,
        KNIGHT
    };

    enum class Layer  {
        LAYER_0 = 0,
        LAYER_1
    };

    Object(Type type, Layer layer);

    void setLayer(Layer layer);
    Layer getLayer();
    virtual void setOrientation(Orientation ori) = 0;

protected:
    Layer layer;
    Type type;
    sf::Texture texture;
};

class Wall: public Object
{
public:
    Wall();
    Wall(Layer layer);
    void setOrientation(Orientation ori);
};

class Ground: public Object
{
public:
    Ground();
    Ground(Layer layer);
    void setOrientation(Orientation ori);
};

class Perso: public Object
{
    // A compléter
};

#endif // OBJECT_H
