#include "Garaje.h"
#include "Cubo.h"

Garaje::Garaje()
{
	_color = new Color(0.0f, 0.0f, 0.0f);
	_numHijos = 4;
	_hijos = new Objeto3D*[_numHijos];

	//Pared 1
	_hijos[0] = new Cubo(new Color(0.9f, 0.9f, 0.9f), -1);
	_hijos[0]->traslada(&PV3D(-3.0f, 3.5f, 0.0f, 1));
	_hijos[0]->escala(&PV3D(0.5f, 5.0f, 10.0f, 1));

	//Pared 2
	_hijos[1] = new Cubo(new Color(0.9f, 0.9f, 0.9f), -1);
	_hijos[1]->traslada(&PV3D(3.0f, 3.5f, 0.0f, 1));
	_hijos[1]->escala(&PV3D(0.5f, 5.0f, 10.0f, 1));

	//Pared 3
	_hijos[2] = new Cubo(new Color(0.3f, 0.2f, 0.1f), -1);
	_hijos[2]->traslada(&PV3D(0.0f, 3.5f, -5.0f, 1));
	_hijos[2]->escala(&PV3D(6.0f, 5.0f, 0.5f, 1));

	//Pared 4
	_hijos[3] = new Cubo(new Color(0.9f, 0.0f, 0.0f), -1);
	_hijos[3]->traslada(&PV3D(0.0f, 5.8f, 0.0f, 1));
	_hijos[3]->escala(&PV3D(6.0f, 0.5f, 10.0f, 1));
}

Garaje::~Garaje()
{
}