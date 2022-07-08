#include "Golf.h"

Golf::Golf()
{
	_body.setSize(sf::Vector2f(50, 100));
	_textura.loadFromFile("carpincho.png");
	_sprite.setTextureRect({ 0,0, (int)_textura.getSize().x, (int)_textura.getSize().y });
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);

}

void Golf::update()
{
	_sprite.move(_velocity);
	if (_sprite.getPosition().x > 600) {
		respawn();
	}
}

void Golf::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

void Golf::respawn()
{
	_sprite.setPosition(-250, 50 + (std::rand() % 300));

}

sf::FloatRect Golf::getBounds() const
{
	return _sprite.getGlobalBounds();
}
