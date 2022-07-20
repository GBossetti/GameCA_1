#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"
#include "Obstaculo.h"


class Carpincho : public Obstaculo
{
public:
	Carpincho();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void respawn(); 
	sf::FloatRect getBounds() const override;
};


