#include <SFML/Graphics.hpp>

#include "gamingarea.h"

int main()
{
   GamingArea window(GamingArea::TILE_W*GamingArea::NB_TILE_W, GamingArea::TILE_H*GamingArea::NB_TILE_H, "Labyrinthe");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.update();
        window.display();
    }

    return 0;
}
