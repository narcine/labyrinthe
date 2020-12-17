#include "gamingarea.h"
#include "objectfactory.h"

#include <iostream>

using Type = Object::Type;
using Layer = Object::Layer;

Object::Type const laby[GamingArea::NB_TILE_H][GamingArea::NB_TILE_W] {
    {Type::WALL, Type::WALL, Type::WALL, Type::WALL,Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::GROUND},
    {Type::WALL, Type::WALL, Type::WALL, Type::WALL,Type::GROUND, Type::GROUND, Type::GROUND, Type::GROUND, Type::GROUND, Type::GROUND, Type::GROUND, Type::GROUND, Type::GROUND, Type::GROUND, Type::GROUND, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::GROUND, Type::GROUND},
    {Type::WALL, Type::WALL, Type::WALL, Type::GROUND,Type::GROUND, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::GROUND, Type::GROUND, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::GROUND, Type::WALL},
    {Type::WALL, Type::WALL, Type::WALL, Type::WALL,Type::WALL, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::GROUND, Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::GROUND, Type::GROUND, Type::WALL, Type::WALL, Type::GROUND, Type::WALL},
    {Type::WALL, Type::WALL, Type::GROUND, Type::GROUND,Type::GROUND, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::GROUND, Type::WALL, Type::GROUND, Type::GROUND},
    {Type::WALL, Type::WALL, Type::GROUND, Type::WALL,Type::GROUND, Type::WALL, Type::GROUND, Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::GROUND, Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::GROUND},
    {Type::WALL, Type::GROUND, Type::GROUND, Type::WALL,Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::GROUND, Type::GROUND, Type::GROUND, Type::GROUND},
    {Type::WALL, Type::GROUND, Type::WALL, Type::WALL,Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL},
    {Type::WALL, Type::GROUND, Type::WALL, Type::GROUND,Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::GROUND, Type::GROUND, Type::WALL, Type::WALL, Type::WALL, Type::GROUND, Type::WALL},
    {Type::WALL, Type::GROUND, Type::WALL, Type::GROUND,Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::GROUND, Type::GROUND, Type::WALL, Type::WALL, Type::GROUND, Type::WALL},
    {Type::WALL, Type::GROUND, Type::WALL, Type::GROUND,Type::WALL, Type::GROUND, Type::GROUND, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::WALL, Type::GROUND, Type::GROUND, Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::GROUND, Type::WALL},
    {Type::WALL, Type::GROUND, Type::WALL, Type::GROUND,Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::GROUND, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::GROUND, Type::WALL},
    {Type::WALL, Type::GROUND, Type::WALL, Type::GROUND,Type::GROUND, Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::GROUND, Type::GROUND, Type::GROUND, Type::WALL},
    {Type::WALL, Type::GROUND, Type::WALL, Type::WALL,Type::WALL, Type::GROUND, Type::GROUND, Type::GROUND, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::GROUND, Type::GROUND, Type::WALL, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::WALL},
    {Type::WALL, Type::GROUND, Type::WALL, Type::WALL,Type::WALL, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::GROUND, Type::GROUND, Type::GROUND, Type::GROUND, Type::WALL, Type::WALL, Type::WALL},
    {Type::WALL, Type::GROUND, Type::GROUND, Type::GROUND,Type::GROUND, Type::GROUND, Type::GROUND, Type::WALL, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL},
    {Type::WALL, Type::WALL, Type::WALL, Type::WALL,Type::WALL, Type::GROUND, Type::GROUND, Type::GROUND, Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::GROUND, Type::GROUND, Type::GROUND, Type::GROUND, Type::GROUND, Type::WALL, Type::WALL, Type::WALL, Type::WALL},
    {Type::WALL, Type::WALL, Type::WALL, Type::GROUND,Type::GROUND, Type::GROUND, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::WALL, Type::WALL},
    {Type::WALL, Type::WALL, Type::GROUND, Type::GROUND,Type::WALL, Type::WALL, Type::WALL, Type::GROUND, Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::GROUND, Type::WALL, Type::GROUND, Type::WALL, Type::GROUND, Type::GROUND, Type::GROUND, Type::WALL, Type::WALL},
    {Type::WALL, Type::WALL, Type::GROUND, Type::WALL,Type::WALL, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::GROUND, Type::GROUND, Type::WALL, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL},
    {Type::WALL, Type::WALL, Type::GROUND, Type::WALL,Type::WALL, Type::WALL, Type::WALL, Type::GROUND, Type::WALL, Type::WALL, Type::WALL, Type::GROUND, Type::GROUND, Type::GROUND, Type::GROUND, Type::GROUND, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL},
    {Type::WALL, Type::WALL, Type::GROUND, Type::WALL,Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL, Type::WALL}
};

GamingArea::GamingArea(int width, int height, std::string name) :
    sf::RenderWindow(sf::VideoMode(width, height), name)
{
    game = new Object***[NB_TILE_H];
    for(int i = 0; i < NB_TILE_H; i++)
    {
        game[i] = new Object**[NB_TILE_W];
        for(int j = 0; j < NB_TILE_W; j++)
        {
            game[i][j] = new Object*[NB_LAYER];
            for(int l = 0; l < NB_LAYER; l++)
            {
                game[i][j][l] = nullptr;
            }
        }
    }

    initMap();
}

void GamingArea::fill(Type const map[NB_TILE_H][NB_TILE_W])
{
    for(int i = 0; i < NB_TILE_H; i++)
    {
        for(int j = 0; j < NB_TILE_W; j++)
        {
            addObject(ObjectFactory::createObject(map[i][j]), i, j);
        }
    }
}

void GamingArea::drawMap(Object ****game, int width, int height)
{
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            for(int l = 0; l < NB_LAYER; l++)
                drawObject(game[i][j][l],i,j);
}

void GamingArea::drawObject(Object* obj, int i, int j)
{
    if(obj == nullptr) return;
    sf::Transform tf;
    tf.translate(j*TILE_W, i*TILE_H);
    draw(*obj,tf);
}

void GamingArea::deleteObject(int i, int j, Layer l)
{
    if(game[i][j][static_cast<int>(l)] != nullptr)
    {
        delete game[i][j][static_cast<int>(l)];
        game[i][j][static_cast<int>(l)] = nullptr;
    }
}

void GamingArea::addObject(Object* obj, int i, int j)
{
    if(obj == nullptr) return;
    deleteObject(i, j, obj->getLayer());
    game[i][j][static_cast<int>(obj->getLayer())] = obj;
}

void GamingArea::addObject(Object* obj, Object::Orientation ori, int i, int j)
{
    if(obj == nullptr) return;
    obj->setOrientation(ori);
    deleteObject(i, j, obj->getLayer());
    game[i][j][static_cast<int>(obj->getLayer())] = obj;
}

void GamingArea::clear()
{
    for(int i= 0; i < NB_TILE_H; i++)
    {
        for(int j = 0; j < NB_TILE_W; j++)
        {
            for(int l = 0; l < NB_LAYER; l++)
            {
                if(game[i][j][l] != nullptr)
                {
                    delete game[i][j][l];
                    game[i][j][l] = nullptr;
                }
            }
        }
    }
}

void GamingArea::initMap()
{
   fill(laby);
}

void GamingArea::drawGame()
{
    drawMap(game, NB_TILE_W, NB_TILE_H);
}

GamingArea::~GamingArea()
{
    for(int i = 0; i < NB_TILE_H; i++)
    {
        for(int j = 0; j < NB_TILE_W; j++)
        {
            for(int l = 0; l < NB_LAYER; l++)
            {
                if(game[i][j][l] != nullptr)
                    delete game[i][j][l];
            }
            delete[] game[i][j];
        }
        delete[] game[i];
    }

    delete[] game;
}
