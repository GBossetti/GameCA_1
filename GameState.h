#pragma once
#include <SFML/Graphics.hpp>

class GameState {
public:
    virtual ~GameState();
    virtual void init() = 0;
    virtual void handleInput(sf::Event* event) = 0;
    virtual void update(float timeElapsed) = 0;
    virtual void draw(sf::RenderWindow* window) = 0;
};
