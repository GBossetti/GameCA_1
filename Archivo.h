#pragma once
#include <cstdio>

class Archivo
{
private:
	int _puntos;

public:

	bool GrabarEnDisco();
	bool LeerDeDisco(int pos);
	int ContarRegistros();

	void setPuntos(int p);
	int getPuntos();
};

