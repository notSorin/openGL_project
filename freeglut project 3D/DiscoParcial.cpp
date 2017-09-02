#include "DiscoParcial.h"

DiscoParcial::DiscoParcial()
{
}

DiscoParcial::~DiscoParcial()
{
}

void DiscoParcial::dibuja()
{
	GLUquadricObj *q = gluNewQuadric();

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glMultMatrixf(_mT->getM());

	gluQuadricDrawStyle(q, GLU_FILL);
	gluPartialDisk(q, 5.0f, 5.0f, 30, 30, 0.0f, 90.0f);

	glPopMatrix();
	gluDeleteQuadric(q);
}