#include "Faro.h"

Faro::Faro(GLfloat radius, GLfloat height, GLint slices, GLint stacks, Color *c, int nFaro)
{
	_radius = radius;
	_height = height;
	_slices = slices;
	_stacks = stacks;
	_color = c;
	_nFaro = nFaro;

	if (_nFaro == 1)
	{ 
		glEnable(GL_LIGHT1);

		GLfloat d[] = { 0.0, 0.0, 1.0, 1.0 };
		glLightfv(GL_LIGHT1, GL_DIFFUSE, d);
		GLfloat a[] = { 0.3f, 0.3f, 0.3f, 1.0 };
		glLightfv(GL_LIGHT1, GL_AMBIENT, a);
		GLfloat p[] = { 0.0, 0.0, 0.0, 1.0 };
		glLightfv(GL_LIGHT1, GL_POSITION, p);

		glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 10.0f);
		glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 4);
	}
	else
	{
		glEnable(GL_LIGHT2);

		GLfloat d[] = { 0.0, 0.0, 1.0, 1.0 };
		glLightfv(GL_LIGHT2, GL_DIFFUSE, d);
		GLfloat a[] = { 0.3f, 0.3f, 0.3f, 1.0 };
		glLightfv(GL_LIGHT2, GL_AMBIENT, a);
		GLfloat p[] = { 0.0, 0.0, 0.0, 1.0 };
		glLightfv(GL_LIGHT2, GL_POSITION, p);
		
		glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 10.0f);
		glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 4);
	}
	
}

Faro::~Faro()
{
}

void Faro::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMultMatrixf(_mT->getM());

		if (_nFaro == 1)
		{
			GLfloat dir[] = { 0.0f, 0.0f, -1.0f };
			glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dir);
			GLfloat p[] = { 0.0, 0.0, 0.0, 1.0 };
			glLightfv(GL_LIGHT1, GL_POSITION, p);
			glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.001);
		}
		else
		{
			GLfloat dir[] = { 0.0f, 0.0f, -1.0f };
			glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, dir);
			GLfloat p[] = { 0.0, 0.0, 0.0, 1.0 };
			glLightfv(GL_LIGHT2, GL_POSITION, p);
			glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.001);
		}

		glColor3f(getColor()->getR(), getColor()->getG(), getColor()->getB());
		glutSolidCylinder(_radius, _height, _slices, _stacks);
	glPopMatrix();
}

void Faro::encenderFaro()
{
	if (_nFaro ==1)
		glEnable(GL_LIGHT1);
	else
		glEnable(GL_LIGHT2);
}

void Faro::apagarFaro()
{
	if (_nFaro == 1)
		glDisable(GL_LIGHT1);
	else
		glDisable(GL_LIGHT2);
}