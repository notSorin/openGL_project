#include "Cilindro.h"

Cilindro::Cilindro()
{
}

Cilindro::Cilindro(GLfloat radius, GLfloat height, GLint slices, GLint stacks, Color *c) : _radius(radius), _height(height), _slices(slices), _stacks(stacks)
{
	_color = c;
}

Cilindro::~Cilindro()
{
}

void Cilindro::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMultMatrixf(_mT->getM());
		glColor3f(getColor()->getR(), getColor()->getG(), getColor()->getB());
		glutSolidCylinder(_radius, _height, _slices, _stacks);
	glPopMatrix();
}