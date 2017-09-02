#pragma once
#include "ObjetoCompuesto3D.h"

class Coche : public ObjetoCompuesto3D
{
public:
	Coche(GLuint texturas);
	~Coche();

	void girarIzquierda();
	void girarDerecha();
	void avanzar();
	void retroceder();
	void encenderFaros();
	void apagarFaros();
};