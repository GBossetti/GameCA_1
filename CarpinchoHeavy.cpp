#include "CarpinchoHeavy.h"

CarpinchoHeavy::CarpinchoHeavy()
{
	_textura.loadFromFile("carpincho2.png");
	_sprite.setTextureRect({ 0,0, (int)_textura.getSize().x, (int)_textura.getSize().y });
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
}

void CarpinchoHeavy::update()
{
	_sprite.move(_velocity);
	if (_sprite.getPosition().y > 600) {
		respawn();
	}
}

void CarpinchoHeavy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

void CarpinchoHeavy::respawn()
{
	_sprite.setPosition((std::rand() % 200) + 150 + _sprite.getLocalBounds().width, -200);
}

sf::FloatRect CarpinchoHeavy::getBounds() const
{
	return _sprite.getGlobalBounds();
}
