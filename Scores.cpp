#include "Scores.h"

Scores::Scores()
{
}

int Scores::Run(sf::RenderWindow& window)
{
    _texturecred.loadFromFile("Scores.png");
    _backgroundcred.setTexture(_texturecred);
    _font.loadFromFile("8bit.ttf");

    sf::Event Event;
    bool Running = true;

    while (Running)
    {
        while (window.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
            {
                window.close();
            }

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
        //window.draw(primero);
        //window.draw(segundo);
        window.display();

    }

    return (-1);
}

void Scores::MostrarPuntajes()
{
    Archivo* vPuntajes;
    Archivo reg;
    int cantReg = reg.ContarRegistros();
    vPuntajes = new Archivo[cantReg];
    if (vPuntajes == NULL) return;

    cargarVector(vPuntajes, cantReg);
    ordenarVector(vPuntajes, cantReg);

    for (int i = 0; i < cantReg; i++) {
        std::cout << vPuntajes[i].getPuntos() << std::endl;
    }

    delete vPuntajes;
}

void cargarVector(Archivo* v, int cant) {
    Archivo reg;

    for (int i = 0; i < cant; i++) {
        reg.LeerDeDisco(i);
        v[i].setPuntos(reg.getPuntos());
    }
}

void ordenarVector(Archivo* v, int cant) {
    Archivo aux;
    for (int i = 0; i < cant - 1; i++) {
        for (int j = i + 1; j < cant; j++) {
            if (v[i].getPuntos() > v[j].getPuntos()) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}