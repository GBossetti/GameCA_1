#pragma once
#include "Obstaculo.h"

class Golf : public Obstaculo
{
public:
	Golf();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void respawn();
	sf::FloatRect getBounds() const override;
};

