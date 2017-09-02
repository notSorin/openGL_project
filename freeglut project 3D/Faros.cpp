#include "Faros.h"
#include "Cilindro.h"

Faros::Faros()
{
	_color = new Color(0.1f, 0.1f, 0.9f);
	_numHijos = 2;
	_hijos = new Objeto3D*[_numHijos];

	/*_hijos[0] = new Faro(0.3f, 0.8f, 10, 4, new Color(0.0f, 1.0f, 1.0f));

	//Faro 2
	_hijos[1] = new Faro(0.3f, 0.8f, 10, 4, new Color(0.0f, 1.0f, 1.0f));
	_hijos[1]->traslada(&PV3D(4.0f, 0.0f, 0.0f, 1));*/

	rota(&PV3D(1.0f, 0.0f, 0.0f, 1), -90);
}

Faros::~Faros()
{
}