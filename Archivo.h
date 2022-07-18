#pragma once
#include <cstdio>
#include <cstring>

class Archivo
{
private:
	int _puntos;
	char _nombre[50];

public:

	bool GrabarEnDisco();
	bool LeerDeDisco(int pos);
	int ContarRegistros();

	void setPuntos(int p);
	void setNombre(const char* n);

	int getPuntos();
	const char* getNombre();
};

