#pragma once
#include "TAfin.h"
#include "Color.h"

class Objeto3D
{
public:
	Objeto3D();
	virtual ~Objeto3D();

	void traslada(PV3D *v);
	void rota(PV3D *v, GLfloat alfa);
	void escala(PV3D *v);

	virtual void dibuja() = 0;

	//Devuelve puntero a la matriz de transformación del Objeto3D.
	//NO DEVUELVE NEW.
	TAfin *getMT() const
	{
		return _mT;
	}

	//Devuelve puntero al Color del Objeto3D.
	//NO DEVUELVE NEW.
	Color *getColor() const
	{
		return _color;
	}

protected:
	TAfin *_mT;
	Color *_color;
};