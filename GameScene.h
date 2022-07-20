#pragma once
#include "cScreen.h"
#include "GamePlay1.h"
#include "GamePlay2.h"
#include "GamePlay3.h"
#include "Archivo.h"

class GameScene : public cScreen
{
private:
	GamePlay1 gp1;
	GamePlay2 gp2;
	GamePlay3 gp3;

	int _puntaje;
	int _vidas;

public:
	virtual int Run(sf::RenderWindow& window);
	void setVidas(int vida);
	void setPuntos(int puntos);
	void Grabar();
};

