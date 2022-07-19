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

    MostrarPuntajes();

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

    int cantRegMostrar = 2;
    int punto1 = 0, punto2 = 0;

    for (int i = 0; i < cantRegMostrar; i++) {
        if (punto1 == 0) {
            punto1 = vPuntajes[i].getPuntos();
        }
        else {
            if (punto2 == 0) {
                punto2 = vPuntajes[i].getPuntos();
            }
        }
    }
    
    primero.setFont(_font);
    primero.setPosition(300, 200);
    primero.setFillColor(sf::Color::White);
    primero.setString("PUNTOS: " + std::to_string(punto1));

    segundo.setFont(_font);
    segundo.setPosition(300, 250);
    segundo.setFillColor(sf::Color::White);
    segundo.setString("PUNTOS: " + std::to_string(punto2));


    delete vPuntajes;
}

void cargarVector(Archivo* v, int cant) {
    Archivo reg;

    for (int i = 0; i < cant; i++) {
        reg.LeerDeDisco(i);
        v[i].setNombre(reg.getNombre());
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