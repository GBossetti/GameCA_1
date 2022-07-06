#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <ctime>
#include "Personaje.h"
#include "Carpincho.h"
#include "CarpinchoCopado.h"
#include "GamePlay.h"
#include "Jugadorxs.h"

int main()
{
    std::srand((unsigned)std::time(0)); //Planto la semilla para poder usar random con ctime

    //Inicialización de la ventana:
    sf::RenderWindow window(sf::VideoMode(800, 600), "Carpincho's Attack"); //Píxeles tamaño de ventana + nombre
    window.setFramerateLimit(60); //Forzamos a que corra a 60 frames per second

    GamePlay gp;
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




        gp.aceleracion();
        gp.juego();
        gp.setTextos();
        gp.pausa();
        gp.gameOver();
        gp.update();

        window.clear();

        //Draw
        //window.draw(gp);
        window.draw(player);

        //Display - Fli
        window.display();
    }
       
    //Liberación del juego
    return 0;
}