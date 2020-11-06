#ifndef GAMINGAREA_H
#define GAMINGAREA_H

#include <SFML/Graphics.hpp>
#include "object.h"
#include <vector>

class GamingArea : public sf::RenderWindow
{
public:
    constexpr static const int TILE_H { 35 }; // in pixel
    constexpr static const int TILE_W { 35 }; // in pixel
    constexpr static const int NB_TILE_W { 22 };
    constexpr static const int NB_TILE_H { 22 };

    GamingArea(int width, int height, std::string name);
    ~GamingArea();

    void update();
    void drawObject(Object* obj, int i, int j);
    void fill(Object *map[NB_TILE_H][NB_TILE_W]);

private :
    Object ***game;

    void drawMap(Object ***game, int width, int height);
};

#endif // GAMINGAREA_H
