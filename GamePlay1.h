#pragma once
#include <SFML\Graphics.hpp>
#include "cScreen.h"
#include "Personaje.h"
#include "Obstaculo.h"
#include "Carpincho.h"
#include "CarpinchoCopado.h"
#include "PopUp.h"
#include "Jugador.h"
#include<iostream>


class GamePlay1 : public sf::Drawable, public cScreen
{
private:
	Personaje repartidor;
	Carpincho carpincho;
	CarpinchoCopado camarada;
	Obstaculo barrera;
	PopUp popup;
	//Jugador player;

	sf::Sprite image;
	sf::Texture texture_fondo;
	sf::Font font;
	sf::Text text, text_vida, text_game_over, text_pausa, nombre;

	int vidas;
	int tiempojugado;
	int points;
	int time_inmunidad;
	bool juego_pausa;
	bool apreta_pausa;
	bool game_over;
	bool llegada;
	bool cambia_nivel;

	//bool ingreso_nombre;
	//bool bandera;

	bool escape;

public:
	GamePlay1();
	virtual int Run(sf::RenderWindow& window);
	void update();
	void setTextos();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void aceleracion();
	void juego();
	void pausa();
	void gameOver();
	
	//std::string getNombre();

	void setVidas();
	int getVidas();

	void setPuntos();
	int getPuntos();

	bool getCambiaNivel();
	void setCambiaNivel();
	
	void setValorInicial();
	void setLlegada();
	void setTiempo();
	void setInmunidad();
	void setGameOver();
	//void setIngresoNombre();

	void setEscape();
	bool getEscape();
};

