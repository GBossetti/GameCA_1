#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <ctime>
#include "Personaje.h"
#include "Carpincho.h"
#include "CarpinchoCopado.h"
#include "GamePlay.h"
#include "Jugadorxs.h"
#include "gp1.h"
#include "gp2.h"
#include "gp3.h"

int main()
{
    std::srand((unsigned)std::time(0)); //Planto la semilla para poder usar random con ctime

    //Inicialización de la ventana:
    sf::RenderWindow window(sf::VideoMode(800, 600), "Carpincho's Attack"); //Píxeles tamaño de ventana + nombre
    window.setFramerateLimit(60); //Forzamos a que corra a 60 frames per second

    GamePlay gp;
    GamePlay1 gp1;
    GamePlay2 gp2;
    GamePlay3 gp3;


    Jugadorxs player;


    //GameLoop
    while (window.isOpen())
    {
        //ReadInput
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
         
            if (player.getIngreso() && event.type == sf::Event::TextEntered)
            {
                player.cargarNombre(static_cast<char>(event.text.unicode));
                player.update();
                std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;

            }
        }




        gp3.aceleracion();
        gp3.juego();
        gp3.setTextos();
        gp3.pausa();
        gp3.gameOver();
        gp3.update();

        window.clear();

        //Draw
        //window.draw(gp3);
        window.draw(player);

        //Display - Fli
        window.display();
    }
       
    //Liberación del juego
    return 0;
}