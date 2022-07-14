#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <ctime>
#include "Personaje.h"
#include "Carpincho.h"
#include "CarpinchoCopado.h"
#include "Jugadorxs.h"
#include "Pantallas.h"
#include "Scores.h"
#include "GameScene.h"


int main()
{
    std::srand((unsigned)std::time(0)); //Planto la semilla para poder usar random con ctime

    std::vector<cScreen*> Screens;
    int screen = 0;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Carpincho's Attack");
    window.setFramerateLimit(60);

    // Declaracion de escenas
    Menu menu;
    Screens.push_back(&menu); // Menu es 0 en el vector de escenas

    Credits creditos;
    Screens.push_back(&creditos); // 1

    Scores puntos;
    Screens.push_back(&puntos); //2

    //Jugadorxs player;
    //Screens.push_back(&player); // 3

    //GamePlay1 gp1;
    //Screens.push_back(&gp1); // 3
    //
    //GamePlay2 gp2;
    //Screens.push_back(&gp2); // 4
    //
    //GamePlay3 gp3;
    //Screens.push_back(&gp3); // 5

    GameScene game_scene;
    Screens.push_back(&game_scene); //3


    while (screen >= 0)
    {
        screen = Screens[screen]->Run(window);
    }

    return EXIT_SUCCESS;

}
/*
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
*/