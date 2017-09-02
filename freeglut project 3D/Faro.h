#pragma once
#include "Cilindro.h"

class Faro : public Cilindro
{
public:
	Faro(GLfloat radius, GLfloat height, GLint slices, GLint stacks, Color *c, int nFaro);
	~Faro();

	void dibuja();
	void encenderFaro();
	void apagarFaro();

private:
	int _nFaro;
};