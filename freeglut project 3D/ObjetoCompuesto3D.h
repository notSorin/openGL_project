#pragma once
#include "Objeto3D.h"

class ObjetoCompuesto3D : public Objeto3D
{
public:
	ObjetoCompuesto3D();
	virtual ~ObjetoCompuesto3D();

	void dibuja();

protected:
	int _numHijos;
	Objeto3D **_hijos;
};