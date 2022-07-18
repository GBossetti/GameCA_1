#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include"PopUp.h"

class Jugador : public PopUp
{
private:
	sf::String _playerInput;
	sf::Text _pideNombre, _playerText;
	bool ingreso;


public:
	Jugador();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void cargarNombre(int n);
	bool getIngreso();
	void update();
	std::string getNombre();
};


