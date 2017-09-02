#include "Escena.h"
#include "Autopista.h"
#include "Coche.h"
#include "Farola.h"
#include "Arbol.h"
#include "Garaje.h"
#include "Esfera.h"
#include "FarolaConLuz.h"

Escena::Escena(GLuint texturas)
{
	_color = new Color(0.0f, 0.0f, 0.0f);
	_numHijos = 13;
	_hijos = new Objeto3D*[_numHijos];

	//Autopista
	_hijos[0] = new Autopista(new Color(0.3f, 0.3f, 0.3f));
	_hijos[0]->traslada(&PV3D(5.0f, 0.0f, -1.0f, 1));

	//Coche
	_hijos[1] = new Coche(texturas);
	_hijos[1]->traslada(&PV3D(5.0f, 1.7f, 8.0f, 1));
	_hijos[1]->rota(&PV3D(0.0f, 1.0f, 0.0f, 1), 180);

	//Farola 1
	_hijos[2] = new Farola();
	_hijos[2]->traslada(&PV3D(-10.0f, 0.0f, 11.0f, 1));

	//Farola 2
	_hijos[3] = new FarolaConLuz();
	_hijos[3]->traslada(&PV3D(10.0f, 0.0f, 11.0f, 1));

	/*GLfloat d[] = { 0.1, 0.0, 0.0, 1.0 };
	glLightfv(GL_LIGHT3, GL_DIFFUSE, d);
	GLfloat a[] = { 0.3f, 0.3f, 0.3f, 1.0 };
	glLightfv(GL_LIGHT3, GL_AMBIENT, a);
	GLfloat p[] = { 10.0, 8.0, 11.0, 1.0 };
	glLightfv(GL_LIGHT3, GL_POSITION, p);*/

	//Farola 3
	_hijos[4] = new Farola();
	_hijos[4]->traslada(&PV3D(30.0f, 0.0f, 11.0f, 1));

	GLfloat x = -20;

	//Árboles
	for (int i = 5; i < 8; i++)
	{
		_hijos[i] = new Arbol();
		_hijos[i]->traslada(&PV3D(x, 0.0f, -2.0f, 1));
		x += 20;
	}

	x = -20;

	for (int i = 8; i < 11; i++)
	{
		_hijos[i] = new Arbol();
		_hijos[i]->traslada(&PV3D(x, 0.0f, 25.0f, 1));
		x += 20;
	}

	//Garaje

	_hijos[11] = new Garaje();
	_hijos[11]->traslada(&PV3D(10.0f, -1.0f, -5.0f, 1));

	//Esfera
	_hijos[12] = new Esfera(5.0f, 120.0f, 120.0f, new Color(0.3f, 0.9f, 0.3f));
	_hijos[12]->traslada(&PV3D(-10, 2.0f, 5.0f, 1));

	//Poner la escena por debajo de la rejilla.
	traslada(&PV3D(0.0f, -1.0f, 0.0f, 1));
}

Escena::~Escena()
{
}

void Escena::girarCocheIzq()
{
	((Coche *)_hijos[1])->girarIzquierda();
}

void Escena::girarCocheDch()
{
	((Coche *)_hijos[1])->girarDerecha();
}

void Escena::avanzarCoche()
{
	((Coche *)_hijos[1])->avanzar();
}

void Escena::retrocederCoche()
{
	((Coche *)_hijos[1])->retroceder();
}

PV3D *Escena::getPosCoche()
{
	return _hijos[1]->getMT()->getPos();
}

void Escena::apagarFaros()
{
	((Coche *)_hijos[1])->apagarFaros();
}

void Escena::encenderFaros()
{
	((Coche *)_hijos[1])->encenderFaros();
}