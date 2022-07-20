#pragma once
#include "cScreen.h"
#include "GamePlay1.h"
#include "GamePlay2.h"
#include "GamePlay3.h"
#include "Archivo.h"
#include "Jugador.h"

class GameScene : public cScreen
{
private:
	GamePlay1 gp1;
	GamePlay2 gp2;
	GamePlay3 gp3;
	Jugador player;

	int _puntaje;
	int _vidas;
	char _nombre[50];

	bool ingresaNombre;
	bool bandera;


public:
	virtual int Run(sf::RenderWindow& window);
	void setVidas(int vida);
	void setPuntos(int puntos);
	
	void setNombre(std::string nombre);
	std::string getNombre();
	void Grabar();
};

