#include "GameScene.h"


int GameScene::Run(sf::RenderWindow& window)
{
    gp1.setEscape();
    gp2.setEscape();
    gp3.setEscape();

    ingresaNombre = false;
    bandera = true;

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
            //if (Event.type == sf::Event::KeyPressed)
            //{
            //    switch (Event.key.code)
            //    {
            //    case sf::Keyboard::Escape:
            //        return (0);
            //       break;
            //    
            //    default:
            //        break;
            //    }
            //}
        }
    
	    while (!gp1.getCambiaNivel()) {
		    gp1.Run(window);
            gp1.update();
            //setNombre(gp1.getNombre());
            if (gp1.getEscape() ) {
                gp1.setValorInicial();
                return 0;
            }
        }
	    
	    while (!gp2.getCambiaNivel()) {
            //gp2.setNombre(getNombre());
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
            //gp3.setNombre(getNombre());
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

        setPuntos(gp3.getPuntos()); //para guardar puntos una vez finaliza gp3

        // GRABAMOS PUNTAJE Y NOMBRE EN DISCO
        std::cout << "Puntos" << _puntaje << std::endl;
        // std::cout << "Nombre" << _nombre;
        
        //while (!ingresaNombre) {
        //    player.cargarNombre(static_cast<char>(Event.text.unicode));
        //    player.update();
        //    window.draw(player, states);
        //    std::cout << "ASCII character typed: " << static_cast<char>(Event.text.unicode) << std::endl;
        //
        //    if (Event.text.unicode == 13 && !bandera) {
        //        ingresaNombre = true;
        //    }
        //    bandera = false;
        //
        //    //Clearing screen
        //    window.clear(sf::Color::Black);
        //
        //    //Drawing
        //    window.display();
        //}

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

