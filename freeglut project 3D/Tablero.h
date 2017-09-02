#pragma once
#include "ObjetoCompuesto3D.h"
#include "Color.h"

class Tablero : public ObjetoCompuesto3D
{
public:
	Tablero(int alto, int ancho, int largo, Color *c);
	~Tablero();
};