#include "Esfera.h"

Esfera::Esfera()
{
}

Esfera::Esfera(GLfloat radius, GLint slices, GLint stacks, Color *c) : _radius(radius), _slices(slices), _stacks(stacks)
{
	_color = c;
}


Esfera::~Esfera()
{
}

void Esfera::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMultMatrixf(_mT->getM());
		glColor3f(getColor()->getR(), getColor()->getG(), getColor()->getB());
		glutSolidSphere(_radius, _slices, _stacks);
	glPopMatrix();
}