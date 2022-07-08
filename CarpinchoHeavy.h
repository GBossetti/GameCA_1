#pragma once
#include "Carpincho.h"

class CarpinchoHeavy : public Carpincho
{
public:
	CarpinchoHeavy();
	void update();
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
	void respawn();
	sf::FloatRect getBounds() const override;
};

