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
    constexpr static const int NB_LAYER { 2 };

    GamingArea(int width, int height, std::string name);
    ~GamingArea();

    void initMap();
    void fill(Object::Type const map[NB_TILE_H][NB_TILE_W]);
    void addObject(Object* obj, Object::Orientation ori, int i, int j);
    void addObject(Object* obj, int i, int j);
    void clear();
    void drawGame();

private :
    Object**** game;

    void deleteObject(int i, int j, Object::Layer l);
    void drawMap(Object**** game, int width, int height);
    void drawObject(Object* obj, int i, int j);

};

#endif // GAMINGAREA_H
