#include "gamingarea.h"

Object *map[GamingArea::NB_TILE_H][GamingArea::NB_TILE_W]{
    {new Wall, new Wall, new Wall, new Wall,new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Ground},
    {new Wall, new Wall, new Wall, new Wall,new Ground, new Ground, new Ground, new Ground, new Ground, new Ground, new Ground, new Ground, new Ground, new Ground, new Ground, new Wall, new Wall, new Wall, new Wall, new Wall, new Ground, new Ground},
    {new Wall, new Wall, new Wall, new Ground,new Ground, new Wall, new Wall, new Ground, new Wall, new Wall, new Wall, new Wall, new Wall, new Ground, new Ground, new Wall, new Wall, new Wall, new Wall, new Wall, new Ground, new Wall},
    {new Wall, new Wall, new Wall, new Wall,new Wall, new Wall, new Wall, new Ground, new Wall, new Ground, new Ground, new Ground, new Wall, new Ground, new Wall, new Ground, new Ground, new Ground, new Wall, new Wall, new Ground, new Wall},
    {new Wall, new Wall, new Ground, new Ground,new Ground, new Wall, new Wall, new Ground, new Wall, new Ground, new Wall, new Ground, new Wall, new Ground, new Wall, new Ground, new Wall, new Ground, new Ground, new Wall, new Ground, new Ground},
    {new Wall, new Wall, new Ground, new Wall,new Ground, new Wall, new Ground, new Ground, new Wall, new Ground, new Wall, new Ground, new Ground, new Ground, new Wall, new Ground, new Wall, new Wall, new Ground, new Wall, new Wall, new Ground},
    {new Wall, new Ground, new Ground, new Wall,new Ground, new Wall, new Ground, new Wall, new Wall, new Ground, new Wall, new Wall, new Wall, new Wall, new Wall, new Ground, new Wall, new Wall, new Ground, new Ground, new Ground, new Ground},
    {new Wall, new Ground, new Wall, new Wall,new Ground, new Wall, new Ground, new Wall, new Wall, new Ground, new Wall, new Wall, new Wall, new Wall, new Wall, new Ground, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall},
    {new Wall, new Ground, new Wall, new Ground,new Ground, new Wall, new Ground, new Wall, new Wall, new Ground, new Wall, new Wall, new Wall, new Wall, new Wall, new Ground, new Ground, new Wall, new Wall, new Wall, new Ground, new Wall},
    {new Wall, new Ground, new Wall, new Ground,new Wall, new Wall, new Ground, new Wall, new Wall, new Ground, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Ground, new Ground, new Wall, new Wall, new Ground, new Wall},
    {new Wall, new Ground, new Wall, new Ground,new Wall, new Ground, new Ground, new Wall, new Wall, new Ground, new Wall, new Wall, new Wall, new Ground, new Ground, new Ground, new Wall, new Ground, new Wall, new Wall, new Ground, new Wall},
    {new Wall, new Ground, new Wall, new Ground,new Wall, new Ground, new Wall, new Ground, new Wall, new Ground, new Ground, new Wall, new Wall, new Ground, new Wall, new Ground, new Wall, new Ground, new Wall, new Wall, new Ground, new Wall},
    {new Wall, new Ground, new Wall, new Ground,new Ground, new Ground, new Wall, new Ground, new Wall, new Wall, new Ground, new Wall, new Wall, new Ground, new Wall, new Ground, new Wall, new Ground, new Ground, new Ground, new Ground, new Wall},
    {new Wall, new Ground, new Wall, new Wall,new Wall, new Ground, new Ground, new Ground, new Wall, new Wall, new Ground, new Wall, new Ground, new Ground, new Ground, new Wall, new Wall, new Wall, new Ground, new Wall, new Wall, new Wall},
    {new Wall, new Ground, new Wall, new Wall,new Wall, new Wall, new Wall, new Ground, new Wall, new Wall, new Ground, new Wall, new Ground, new Wall, new Ground, new Ground, new Ground, new Ground, new Ground, new Wall, new Wall, new Wall},
    {new Wall, new Ground, new Ground, new Ground,new Ground, new Ground, new Ground, new Wall, new Wall, new Wall, new Ground, new Wall, new Ground, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall},
    {new Wall, new Wall, new Wall, new Wall,new Wall, new Ground, new Ground, new Ground, new Ground, new Wall, new Ground, new Wall, new Ground, new Ground, new Ground, new Ground, new Ground, new Ground, new Wall, new Wall, new Wall, new Wall},
    {new Wall, new Wall, new Wall, new Ground,new Ground, new Ground, new Wall, new Wall, new Ground, new Wall, new Ground, new Wall, new Ground, new Ground, new Wall, new Ground, new Wall, new Ground, new Wall, new Wall, new Wall, new Wall},
    {new Wall, new Wall, new Ground, new Ground,new Wall, new Wall, new Wall, new Ground, new Ground, new Wall, new Ground, new Wall, new Ground, new Ground, new Wall, new Ground, new Wall, new Ground, new Ground, new Ground, new Wall, new Wall},
    {new Wall, new Wall, new Ground, new Wall,new Wall, new Wall, new Wall, new Ground, new Wall, new Wall, new Ground, new Ground, new Wall, new Wall, new Wall, new Ground, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall},
    {new Wall, new Wall, new Ground, new Wall,new Wall, new Wall, new Wall, new Ground, new Wall, new Wall, new Wall, new Ground, new Ground, new Ground, new Ground, new Ground, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall},
    {new Wall, new Wall, new Ground, new Wall,new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall, new Wall}
};

GamingArea::GamingArea(int width, int height, std::string name) :
    sf::RenderWindow(sf::VideoMode(width, height), name)
{
    game = new Object**[NB_TILE_H];
    for(int i = 0; i < NB_TILE_H; i++)
        game[i] = new Object*[NB_TILE_W];

    fill(map);
}

void GamingArea::fill(Object *map[NB_TILE_H][NB_TILE_W])
{
    for(int i = 0; i < NB_TILE_H; i++)
    {
        for(int j = 0; j < NB_TILE_W; j++)
        {
            game[i][j] = map[i][j];
        }
    }
}

void GamingArea::drawMap(Object ***game, int width, int height)
{
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            drawObject(game[i][j],i,j);
}

void GamingArea::drawObject(Object* obj, int i, int j)
{
    sf::Transform tf;
    tf.translate(j*TILE_W, i*TILE_H);
    draw(*obj,tf);
}

void GamingArea::update()
{
   drawMap(game, NB_TILE_W, NB_TILE_H);
}

GamingArea::~GamingArea()
{
    for(int i = 0; i < NB_TILE_W; i++)
        delete game[i];

    delete game;
}
