#include "FarolaConLuz.h"
#include "Cilindro.h"
#include "Bombilla.h"

FarolaConLuz::FarolaConLuz()
{
	_color = new Color(0.0f, 0.0f, 0.0f);
	_numHijos = 2;
	_hijos = new Objeto3D*[_numHijos];

	//Cuerpo de la farola.
	_hijos[0] = new Cilindro(0.2f, 8, 8, 8, new Color(0.0f, 0.9f, 0.0f));
	_hijos[0]->rota(&PV3D(1.0f, 0.0f, 0.0f, 1), -90);

	//Luz de la farola.
	_hijos[1] = new Bombilla(1, 8, 8, new Color(0.9f, 0.9f, 0.0f));
	_hijos[1]->traslada(&PV3D(0.0f, 8.0f, 0.0f, 1));
}


FarolaConLuz::~FarolaConLuz()
{
}
