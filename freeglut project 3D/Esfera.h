#pragma once
#include "ObjetoCuadrico.h"
#include "Color.h"

class Esfera : public ObjetoCuadrico
{
public:
	Esfera();
	Esfera(GLfloat radius, GLint slices, GLint stacks, Color *c);
	~Esfera();

	void dibuja();

protected:
	GLfloat _radius;
	GLint _slices, _stacks;
};