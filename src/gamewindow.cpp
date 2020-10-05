#include "gamewindow.h"

GameWindow::GameWindow(int width, int height, std::string name) :
   sf::RenderWindow(sf::VideoMode(width, height), name)
{
}

GameWindow::~GameWindow()
{
}
