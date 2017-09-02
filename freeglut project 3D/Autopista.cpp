#include "Autopista.h"
#include "Tablero.h"

Autopista::Autopista(Color *c)
{
	_color = c;
	_numHijos = 2;
	_hijos = new Objeto3D*[_numHijos];

	//Carril 1
	_hijos[0] = new Tablero(1, 10, 60, c);
	_hijos[0]->traslada(&PV3D(-30.0f, 0.0f, 2, 1));
	_hijos[0]->escala(&PV3D(1.0f, 0.3f, 1.0f, 1));
	
	//Carril 2
	_hijos[1] = new Tablero(1, 10, 60, c);
	_hijos[1]->traslada(&PV3D(-30.0f, 0.0f, 13, 1));
	_hijos[1]->escala(&PV3D(1.0f, 0.3f, 1.0f, 1));
}

Autopista::~Autopista()
{
}