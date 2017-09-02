#include "Disco.h"

Disco::Disco()
{
}

Disco::~Disco()
{
}

void Disco::dibuja()
{
	GLUquadricObj *q = gluNewQuadric();

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glMultMatrixf(_mT->getM());

	gluQuadricDrawStyle(q, GLU_FILL);
	gluDisk(q, 5.0f, 5.0f, 30, 30);

	glPopMatrix();
	gluDeleteQuadric(q);
}