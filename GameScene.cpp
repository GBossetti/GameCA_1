#include "GameScene.h"


int GameScene::Run(sf::RenderWindow& window)
{
    gp1.setEscape();
    gp2.setEscape();
    gp3.setEscape();

    sf::Event Event;
    bool Running = true;
    sf::RenderStates states;

    while (Running)
    {
        while (window.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
            {
                return (-1);
            }
        }

        while (!gp1.getCambiaNivel()) {
            gp1.Run(window);
            gp1.update();
            if (gp1.getEscape()) {
                gp1.setValorInicial();
                return 0;
            }
        }

        while (!gp2.getCambiaNivel()) {
            setVidas(gp1.getVidas());
            setPuntos(gp1.getPuntos());
            gp2.setPuntos(this->_puntaje);
            gp2.setVidas(this->_vidas);
            gp2.Run(window);
            gp2.update();
            if (gp2.getEscape()) {
                gp2.setValorInicial();
                gp1.setValorInicial();
                return 0;
            }
        }

        while (!gp3.getCambiaNivel()) {
            setVidas(gp2.getVidas());
            setPuntos(gp2.getPuntos());
            gp3.setPuntos(this->_puntaje);
            gp3.setVidas(this->_vidas);
            gp3.Run(window);
            gp3.update();
            if (gp3.getEscape()) {
                gp3.setValorInicial();
                gp2.setValorInicial();
                gp1.setValorInicial();
                return 0;
            }
        }

        setPuntos(gp3.getPuntos());

        if (gp3.getCambiaNivel())
        {
            Grabar();
        }

        gp1.setValorInicial();
        gp2.setValorInicial();
        gp3.setValorInicial();

        return 0;
    }

    return -1;
}

void GameScene::setVidas(int vida)
{
    _vidas = vida;
}

void GameScene::setPuntos(int puntos)
{
    _puntaje = puntos;
}


void GameScene::Grabar()
{
    Archivo aux;
    aux.setPuntos(_puntaje);
    aux.GrabarEnDisco();
}

