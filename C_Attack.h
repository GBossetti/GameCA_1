#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "GamePlay.h"

class C_Attack
{
public:
    C_Attack();
    static void start();
    static void gameLoop();

    enum State { Uninitialized, Menu, Scores, Creditos, gp1, gp2, gp3, Exiting };
    static void setState(State s);
private:
    static State _state;
    static std::map<State, GameState*> _stateInstances;
    static sf::RenderWindow _window;
    static sf::Clock _clock;
};

