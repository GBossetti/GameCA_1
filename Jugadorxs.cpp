#include "Jugadorxs.h"

Jugadorxs::Jugadorxs()
{
	//i = 0;
	ingreso = false;

	//Cuadro de texto
	_cuadro.setSize(sf::Vector2f(400, 300));
	_cuadro.setOrigin(sf::Vector2f(_cuadro.getLocalBounds().width / 2, _cuadro.getLocalBounds().height / 2));
	_cuadro.setPosition(sf::Vector2f(300, 300));
	_cuadro.setFillColor(sf::Color::Black);	_font.loadFromFile("8bit.ttf");

	// Establecemos fuente y tamanio
	_font.loadFromFile("8bit.ttf");

	//Texto Pide Nombre
	_pideNombre.setFont(_font);
	_pideNombre.setCharacterSize(30);
	_pideNombre.setPosition(sf::Vector2f(200, 150));
	_pideNombre.setString("INSERTE SU NOMBRE:");

	//Carga Nombre
	_playerText.setFont(_font);
	_playerText.setCharacterSize(30);
	_playerText.setPosition(sf::Vector2f(200, 170));
}

void Jugadorxs::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_cuadro, states);
	target.draw(_pideNombre, states);
	target.draw(_playerText, states);
}



void Jugadorxs::cargarNombre(int unicode)
{
	//NO FUNCIONA BIEN
	//if (i != 0 && unicode == 8) {
	//		i = -1;
	//		_nombre[i] = ' ';
	//}
	//	
	//if (unicode < 128) {
	//	_nombre[i] = (char)unicode;
	//}
	//
	//if (unicode == 10) {
	//	_nombre[i] = '\0';
	//}
	//_playerText.setString(_nombre);
	//i++;
	
	 
	//FUNCIONA PERO NO BORRA
	//_playerInput += static_cast<char>(unicode);
	//_playerInput += (char)unicode;
	//_playerText.setString(_playerInput);

	int textSize = _playerInput.getSize();
	if (unicode == 8) { //If backspace
		if (textSize > 0)
			_playerInput.erase(textSize - 1, 1); //Genera un arithmetic overflow
	}
	else if (unicode >= 32 && unicode <= 126) {
		_playerInput += (char)unicode;
	}
	else if (unicode >= 192 && unicode <= 255) {
		_playerInput += (char)unicode;
	}    
}

bool Jugadorxs::getIngreso()
{
	return ingreso;
}

void Jugadorxs::update() 
{
	_playerText.setString(_playerInput);
}

