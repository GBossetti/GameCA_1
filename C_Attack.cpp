#include "C_Attack.h"

C_Attack::C_Attack()
{
	sf::RenderWindow _window;
	sf::Clock _clock;
	State _state = Uninitialized;
	std::map<State, GameState*> _stateInstances;
}

void C_Attack::start()
{
    if (_state != Uninitialized) return;

    _window.create(sf::VideoMode(800, 600), "Carpincho's Attack");
    _window.setFramerateLimit(60);

    _stateInstances[Menu] = new Menu();
    _stateInstances[Menu]->init();

    _stateInstances[Scores] = new Scores();
    _stateInstances[Scores]->init();

    _stateInstances[Creditos] = new Creditos();
    _stateInstances[Creditos]->init();

    _stateInstances[gp1] = new gp1();
    _stateInstances[gp1]->init();

    _stateInstances[gp2] = new gp2();
    _stateInstances[gp2]->init();

    _stateInstances[gp3] = new gp3();
    _stateInstances[gp3]->init();

    _state = Menu;

    gameLoop();

    auto itr = _stateInstances.begin();
    while (itr != _stateInstances.end()) {
        delete itr->second;
        itr++;
    }
    _window.close();
}

void C_Attack::gameLoop()
{
    while (_state != Exiting) {
        float timeElapsed = _clock.restart().asSeconds();
        _window.clear(sf::Color::Black);

        // Para no cmabiar el estado durante los frames
        GameState* currentState = _stateInstances[_state];

        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                _state = Exiting; 
            }

            currentState->handleInput(&event);
        }

        // Update our entities
        currentState->update(timeElapsed);

        // Draw our new entities
        currentState->draw(&_window);

        _window.display();
    }
}

void C_Attack::setState(State s)
{
    _state = s;
}
