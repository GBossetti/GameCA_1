#pragma once
#include "cScreen.h"

class Scores : public cScreen
{
private:
    sf::Font _font;
    sf::Text nombre1, nombre2;
    sf::Sprite _backgroundcred;
    sf::Texture _texturecred;

public:
    Scores();
    virtual int Run(sf::RenderWindow& window);
};