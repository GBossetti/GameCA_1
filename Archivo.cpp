#include "Archivo.h"
#include <iostream>

bool Archivo::GrabarEnDisco()
{
    FILE* p;
    bool grabo;

    p = fopen("puntajes.dat", "ab");
    if (p == NULL) return false;

    grabo = fwrite(this, sizeof(Archivo), 1, p);
    fclose(p);
    std::cout << "GrabarEnDisco";
    return grabo;
}

bool Archivo::LeerDeDisco(int pos)
{
    FILE* p;
    bool leyo;
    p = fopen("puntajes.dat", "rb");
    if (p == NULL) return false;
    fseek(p, sizeof(Archivo) * pos, 0);
    leyo = fread(this, sizeof(Archivo), 1, p);
    fclose(p);
    return leyo;
}

int Archivo::ContarRegistros()
{
    FILE* p;
    int cantReg, bytes;
    p = fopen("puntajes.dat", "rb");
    if (p == NULL) return 0;

    fseek(p, 0, 2);
    bytes = ftell(p);
    fclose(p);
    cantReg = bytes / sizeof(Archivo);
    
    return cantReg;
}

void Archivo::setPuntos(int p)
{
    _puntos = p;
}


int Archivo::getPuntos()
{
    return _puntos;
}

