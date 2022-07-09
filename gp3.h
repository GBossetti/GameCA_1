#pragma once
#include <SFML\Graphics.hpp>
#include "Personaje.h"
#include "Obstaculo.h"
#include "Carpincho.h"
#include "CarpinchoCopado.h"
#include "PopUp.h"
#include "Jugadorxs.h"
#include "CarpinchoHeavy.h"
#include "Golf.h"


class GamePlay3 : public sf::Drawable
{
private:
	Personaje repartidor;
	Carpincho carpincho;
	CarpinchoCopado camarada;
	CarpinchoHeavy heavy;
	Obstaculo barrera;
	Golf pelota;
	PopUp popup;

	sf::Sprite image;
	sf::Texture texture_fondo;
	sf::Font font;
	sf::Text text, text_vida, text_game_over, text_pausa;

	int vidas;
	int tiempojugado;
	int points;
	int time_inmunidad;
	bool juego_pausa;
	bool apreta_pausa;
	bool game_over;
	bool llegada;

public:
	GamePlay3();
	void update();
	void setTextos();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void aceleracion();
	void juego();
	void pausa();
	void gameOver();

	int getVidas();
	int getPuntos();
};


