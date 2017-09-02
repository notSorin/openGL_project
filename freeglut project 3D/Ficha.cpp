#include "Ficha.h"
#include "Quesito.h"
#include <cmath>

Ficha::Ficha(Color *c)
{
	_color = c;
	_numHijos = 6;
	_hijos = new Objeto3D*[_numHijos];

	for (int i = 0; i < _numHijos; i++)
	{
		_hijos[i] = new Quesito(0.5, 1, 20, c);
		_hijos[i]->rota(new PV3D(0.0f, 1.0f, 0.0f, 1), (GLfloat)i * 60);
	}
}

Ficha::~Ficha()
{
}