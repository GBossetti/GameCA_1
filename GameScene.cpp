#include "GameScene.h"

int GameScene::Run(sf::RenderWindow& window)
{
    sf::Event Event;
    bool Running = true;
    sf::RenderStates states;



    while (Running)
    {
        //Verifying events
        while (window.pollEvent(Event))
        {
            // Window closed
            if (Event.type == sf::Event::Closed)
            {
                return (-1);
            }
            //Key pressed
            if (Event.type == sf::Event::KeyPressed)
            {
                switch (Event.key.code)
                {
                case sf::Keyboard::Escape:
                    return (0);
                   break;
                
                default:
                    break;
                }
            }
        }
    
	    while (!gp1.getCambiaNivel()) {
		    gp1.Run(window);
            gp1.update();
            setNombre(gp1.getNombre());
        }
	
	    while (!gp2.getCambiaNivel()) {
            gp2.setNombre(getNombre());
            setVidas(gp1.getVidas());
            setPuntos(gp1.getPuntos());
            gp2.setPuntos(this->_puntaje);
            gp2.setVidas(this->_vidas);
            gp2.Run(window);
            gp2.update();

	    }

	    while (!gp3.getCambiaNivel()) {
            gp3.setNombre(getNombre());
            setVidas(gp2.getVidas());
            setPuntos(gp2.getPuntos());
            gp3.setPuntos(this->_puntaje);
            gp3.setVidas(this->_vidas);
		    gp3.Run(window);
            gp3.update();
	    }

        // GRABAMOS PUNTAJE Y NOMBRE EN DISCO
        Grabar();

        // SETEAMOS A CERO LOS GP
        gp1.setValorInicial();
        gp2.setValorInicial();
        gp3.setValorInicial();
    

        return 0;
    }

    //Never reaching this point normally, but just in case, exit the application
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

void GameScene::setNombre(std::string nombre)
{
    strcpy(_nombre, nombre.c_str());
}

std::string GameScene::getNombre()
{   
    std::string nombre;
    nombre = _nombre;
    return nombre;
}

void GameScene::Grabar()
{
    Archivo aux;
    aux.setPuntos(_puntaje);
    aux.setNombre(_nombre);
    aux.GrabarEnDisco();
}

