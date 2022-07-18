#include "Scores.h"

Scores::Scores()
{
}

int Scores::Run(sf::RenderWindow& window)
{
    _texturecred.loadFromFile("Scores.png");
    _backgroundcred.setTexture(_texturecred);

    _font.loadFromFile("8bit.ttf");
    nombre1.setFont(_font);
    nombre2.setFont(_font);
    nombre1.setPosition(300, 500);
    nombre2.setPosition(300, 525);
    nombre1.setFillColor(sf::Color::White);
    nombre2.setFillColor(sf::Color::White);
    nombre1.setString("PRIMER MEJOR PUNTAJE");
    nombre2.setString("SEUNDO MEJOR PUNTAJE");

    sf::Event Event;
    bool Running = true;

    while (Running)
    {
        while (window.pollEvent(Event))
        {
            //if (Event.type == sf::Event::Closed)
            //{
            //    return (-1);
            //}

            if (Event.type == sf::Event::KeyPressed)
            {
                switch (Event.key.code)
                {
                case sf::Keyboard::Escape:

                    return (0);
                    break;
                }
            }
        }

        window.clear();

        window.draw(_backgroundcred);
        window.draw(nombre1);
        window.draw(nombre2);

        window.display();

    }


    return (-1);
}

void Scores::MostrarPuntajes()
{
    Archivo reg;
    int cantReg = reg.ContarRegistros();

    Archivo* vPuntajes;
    vPuntajes = new Archivo[cantReg];
    if (vPuntajes == NULL) return;

    for (int i = 0; i < cantReg; i++) {
        reg.LeerDeDisco(i);
        vPuntajes[i].setNombre(reg.getNombre());
        vPuntajes[i].setPuntos(reg.getPuntos());
    }

    Archivo aux;
    for (int i = 0; i < cantReg - 1; i++) {
        for (int j = i + 1; j < cantReg; j++) {
            if (vPuntajes[i].getPuntos() > vPuntajes[j].getPuntos()) {
                aux = vPuntajes[i];
                vPuntajes[i] = vPuntajes[j];
                vPuntajes[j] = aux;
            }
    }

    delete vPuntajes;
}
