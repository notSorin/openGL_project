#pragma once
#include "Malla.h"
#include "Color.h"

class Cubo : public Malla
{
public:
	Cubo(Color *c, GLuint texturas);
	~Cubo();
};