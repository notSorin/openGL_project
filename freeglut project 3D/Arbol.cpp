#include "Arbol.h"
#include "Cilindro.h"
#include "Esfera.h"

Arbol::Arbol()
{
	_color = new Color(0.0f, 0.0f, 0.0f);
	_numHijos = 3;
	_hijos = new Objeto3D*[_numHijos];

	//Base
	_hijos[0] = new Cilindro(1.5f, 0.7f, 10, 4, new Color(0.6f, 0.3f, 0.0f));
	_hijos[0]->rota(&PV3D(1.0f, 0.0f, 0.0f, 1), -90);

	//Cuerpo
	_hijos[1] = new Cilindro(1.0f, 5, 10, 4, new Color(0.6f, 0.3f, 0.0f));
	_hijos[1]->rota(&PV3D(1.0f, 0.0f, 0.0f, 1), -90);

	//Cabeza
	_hijos[2] = new Esfera(4.0f, 20, 20, new Color(0.0f, 1.0f, 0.0f));
	_hijos[2]->traslada(&PV3D(0.0f, 8.0f, 0.0f, 1));
}

Arbol::~Arbol()
{
}