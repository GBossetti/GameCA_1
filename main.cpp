#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <ctime>
#include "Personaje.h"
#include "Carpincho.h"
#include "CarpinchoCopado.h"
#include "Pantallas.h"
#include "Scores.h"
#include "GameScene.h"


int main()
{
    std::srand((unsigned)std::time(0)); 

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

    GameScene game_scene;
    Screens.push_back(&game_scene); //3


    while (screen >= 0)
    {
        screen = Screens[screen]->Run(window);
    }

    return EXIT_SUCCESS;

}