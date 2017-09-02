#pragma once
#include "Esfera.h"

class Bombilla : public Esfera
{
public:
	Bombilla(GLfloat radius, GLint slices, GLint stacks, Color *c);
	~Bombilla();

	void dibuja();
};

