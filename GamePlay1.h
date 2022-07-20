#pragma once
#include <SFML\Graphics.hpp>
#include "cScreen.h"
#include "Personaje.h"
#include "Obstaculo.h"
#include "Carpincho.h"
#include "CarpinchoCopado.h"
#include "PopUp.h"
#include<iostream>


class GamePlay1 : public sf::Drawable, public cScreen
{
private:
	Personaje repartidor;
	Carpincho carpincho;
	CarpinchoCopado camarada;
	Obstaculo barrera;
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
	bool cambia_nivel;
	bool escape;

public:
	GamePlay1();
	virtual int Run(sf::RenderWindow& window);
	int getVidas();
	int getPuntos();
	void update();
	void setTextos();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void aceleracion();
	void juego();
	void pausa();
	void gameOver();
	void setVidas();
	void setPuntos();
	bool getCambiaNivel();
	void setCambiaNivel();
	void setValorInicial();
	void setLlegada();
	void setTiempo();
	void setInmunidad();
	void setGameOver();
	void setEscape();
	bool getEscape();
};

