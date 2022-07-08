#pragma once
#include "cScreen.h"

class Credits : public cScreen
{
private:
    sf::Font _font;
    sf::Text nombre1, nombre2;
    sf::Sprite _backgroundcred;
    sf::Texture _texturecred;

public:
    Credits();
    virtual int Run(sf::RenderWindow& window);
};

