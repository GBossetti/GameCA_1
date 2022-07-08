#pragma once
#include "cScreen.h"

#define items 4

class Menu : public cScreen
{
private:
    int _menuSelected;
    sf::Font _font;
    sf::Text _menu[items];
    sf::Sprite _background;
    sf::Texture _textureback;
    bool playing, credits, scores;

public:
    Menu();
    virtual int Run(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    void MoveUp();
    void MoveDown();
    int MenuPressed();
};

