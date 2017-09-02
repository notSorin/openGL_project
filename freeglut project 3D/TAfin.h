#pragma once
#include <GL/freeglut.h>
#include "PV3D.h"

class TAfin
{
public:
	TAfin();
	~TAfin();

	void traslada(PV3D *v);
	void rota(PV3D *v, GLfloat alfa);
	void escala(PV3D *v);

	//Devuelve puntero a la matriz de transformaci�n.
	//NO DEVUELVE NEW.
	GLfloat *getM()
	{
		return _m;
	}

	//Devuelve la posici�n de la matriz de transformaci�n del objeto.
	//DEVUELVE NEW.
	PV3D *getPos() const
	{
		//La posici�n se encuentra en las posiciones
		//12, 13, 14 y 15 de la matriz de transformaci�n.
		return new PV3D(_m[12], _m[13], _m[14], (int)_m[15]);
	}

private:
	void postMultiplica(GLfloat *m1);

	GLfloat _m[16];
};