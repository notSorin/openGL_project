#include "Bombilla.h"


Bombilla::Bombilla(GLfloat radius, GLint slices, GLint stacks, Color *c)
{
	_radius = radius;
	_slices = slices;
	_stacks = stacks;
	_color = c;

	GLfloat d[] = { 1, 1, 1, 1.0 };
	glLightfv(GL_LIGHT3, GL_DIFFUSE, d);
	GLfloat a[] = { 0.0f, 0.0f, 0.0f, 1.0 };
	glLightfv(GL_LIGHT3, GL_AMBIENT, a);

	glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.00001);
	glDisable(GL_LIGHT3);
}


Bombilla::~Bombilla()
{
}

void Bombilla::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMultMatrixf(_mT->getM());
		GLfloat p[] = { 0.0, 0.0, 0.0, 1.0 };
		glLightfv(GL_LIGHT3, GL_POSITION, p);
		glColor3f(getColor()->getR(), getColor()->getG(), getColor()->getB());
		glutSolidSphere(_radius, _slices, _stacks);
	glPopMatrix();
}
