#include "Scores.h"

Scores::Scores()
{
}

int Scores::Run(sf::RenderWindow& window)
{
    _texturecred.loadFromFile("Scores.png");
    _backgroundcred.setTexture(_texturecred);
    _font.loadFromFile("8bit.ttf");

    MostrarPuntajes();

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
        window.draw(primero);
        window.draw(segundo);
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

    cargarVector(vPuntajes, cantReg);
    ordenarVector(vPuntajes, cantReg);

    for (int i = 0; i < cantReg; i++) {
        std::cout << vPuntajes[i].getPuntos() << std::endl;
    }

    int cantRegMostrar = 2;
    int punto1=0, punto2=0;

    for (int i = 0; i < cantRegMostrar; i++) {
        if (punto1 == 0) {
            punto1 = vPuntajes[i].getPuntos();
            std::cout << "punto1" << punto1 << std::endl;
        }
        else {
            if (punto2 == 0) {
                punto2 = vPuntajes[i].getPuntos();
                std::cout << "punto2" << punto2 << std::endl;
            }
        }
    }
    
    primero.setFont(_font);
    primero.setPosition(250, 200);
    primero.setFillColor(sf::Color::White);
    primero.setString("MEJOR PUNTAJE 1: " + std::to_string(punto1));
    
    segundo.setFont(_font);
    segundo.setPosition(250, 250);
    segundo.setFillColor(sf::Color::White);
    segundo.setString("MEJOR PUNTAJE 2: " + std::to_string(punto2));


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
            if (v[i].getPuntos() < v[j].getPuntos()) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}