#pragma once

#include "PV3D.h"
#include "Cara.h"
#include "Objeto3D.h"

class Malla : public Objeto3D
{
public:
	Malla();
	Malla(GLuint textura);
	virtual ~Malla();

	void dibuja();

	//Calcula la normal a una Cara por el método de Newell.
	//DEVUELVE NEW.
	PV3D* calculoNormalNewell(Cara *c);

	//Dibuja las normales de cada cara de la Malla.
	void dibujarNormales();

protected:
	int _numVertices;
	PV3D **_vertices;

	int _numNormales;
	PV3D **_normales;
	
	int _numCaras;
	Cara **_caras;

	GLuint _textura = -1;
};