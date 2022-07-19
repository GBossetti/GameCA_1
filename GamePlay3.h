#pragma once
#include <SFML\Graphics.hpp>
#include "cScreen.h"
#include "Personaje.h"
#include "Obstaculo.h"
#include "Carpincho.h"
#include "CarpinchoCopado.h"
#include "PopUp.h"
#include "CarpinchoHeavy.h"
#include "Golf.h"


class GamePlay3 : public sf::Drawable, public cScreen
{
private:
	Personaje repartidor;
	Carpincho carpincho;
	CarpinchoCopado camarada;
	CarpinchoHeavy heavy;
	Obstaculo barrera;
	Golf pelota;
	PopUp popup;

	std::string _nombre;
	sf::Sprite image;
	sf::Texture texture_fondo;
	sf::Font font;
	sf::Text text, text_vida, text_game_over, text_pausa, nombre, text_final;

	int vidas;
	int tiempojugado;
	int points;
	int time_inmunidad;
	bool juego_pausa;
	bool apreta_pausa;
	bool game_over;
	bool llegada;
	bool cambia_nivel;

public:
	GamePlay3();
	virtual int Run(sf::RenderWindow& window);
	void update();
	void setTextos();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void aceleracion();
	void juego();
	void pausa();
	void gameOver();

	void setVidas(int vida);
	int getVidas();

	void setPuntos(int puntos);
	int getPuntos();

	bool getCambiaNivel();
	void setCambiaNivel();

	void setValorInicial();
	void setLlegada();
	void setTiempo();
	void setInmunidad();
	void setGameOver();

	void setNombre(std::string nom);

};

