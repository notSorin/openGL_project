#pragma once
#include "ObjetoCompuesto3D.h"

class Escena : public ObjetoCompuesto3D
{
public:
	Escena(GLuint texturas);
	~Escena();

	void avanzarCoche();
	void retrocederCoche();
	void girarCocheIzq();
	void girarCocheDch();
	void apagarFaros();
	void encenderFaros();

	//Devuelve puntero a la posición del coche de la Escena.
	//DEVUELVE NEW.
	PV3D *getPosCoche();
};