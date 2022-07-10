#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "cScreen.h"
#include"PopUp.h"

class Jugadorxs : public PopUp, public cScreen
{
private:
	sf::String _playerInput;
	sf::Text _pideNombre, _playerText;
	bool ingreso_nombre;
	int i;


public:
	Jugadorxs();
	virtual int Run(sf::RenderWindow& window);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void cargarNombre(int n);
	void update();
};

