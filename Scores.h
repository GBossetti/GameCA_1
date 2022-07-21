#pragma once
#include "cScreen.h"
#include "Archivo.h"
#include <iostream>

class Scores : public cScreen
{
private:
    sf::Font _font;
    sf::Text primero, segundo;
    sf::Sprite _backgroundcred;
    sf::Texture _texturecred;

public:
    Scores();
    virtual int Run(sf::RenderWindow& window);
    void MostrarPuntajes();
};

void cargarVector(Archivo* v, int cant);
void ordenarVector(Archivo* v, int cant);