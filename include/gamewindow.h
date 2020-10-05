#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <SFML/Graphics.hpp>
#include <string>

class GameWindow: public sf::RenderWindow
{
public:
    GameWindow(int width, int height, std::string name);
    virtual ~GameWindow();
};

#endif // GAMEWINDOW_H
