#pragma once
#include "ObjetoCuadrico.h"
#include "Color.h"

class Cilindro : public ObjetoCuadrico
{
public:
	Cilindro();
	Cilindro(GLfloat radius, GLfloat height, GLint slices, GLint stacks, Color *c);
	~Cilindro();

	void dibuja();

protected:
	GLfloat _radius, _height;
	GLint _slices, _stacks;
};