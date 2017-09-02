#include "Tablero.h"
#include "Cubo.h"

Tablero::Tablero(int alto, int ancho, int largo, Color *c)
{
	_color = c;
	_numHijos = alto * ancho * largo;
	_hijos = new Objeto3D*[_numHijos];

	for (int al = 0; al < alto; al++)
		for (int la = 0; la < largo; la++)
			for (int an = 0; an < ancho; an++)
			{
				//Situar y trasladar los cubos adecuademente.
				_hijos[ancho * largo * al + ancho * la + an] = new Cubo(c, -1);
				_hijos[ancho * largo * al + ancho * la + an]->traslada(&PV3D((GLfloat)la, (GLfloat)al, (GLfloat)an, 1));
			}
}

Tablero::~Tablero()
{
}