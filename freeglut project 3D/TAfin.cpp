#include "TAfin.h"

TAfin::TAfin()
{
	_m[0] = 1; _m[4] = 0; _m[8] = 0; _m[12] = 0;
	_m[1] = 0; _m[5] = 1; _m[9] = 0; _m[13] = 0;
	_m[2] = 0; _m[6] = 0; _m[10] = 1; _m[14] = 0;
	_m[3] = 0; _m[7] = 0; _m[11] = 0; _m[15] = 1;
}

TAfin::~TAfin()
{
}

void TAfin::traslada(PV3D *v)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glTranslatef(v->getX(), v->getY(), v->getZ());
		GLfloat m1[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, m1);
	glPopMatrix();
	postMultiplica(m1);
}

void TAfin::rota(PV3D *v, GLfloat alfa)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glRotatef(alfa, v->getX(), v->getY(), v->getZ());
		GLfloat m1[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, m1);
	glPopMatrix();
	postMultiplica(m1);
}

void TAfin::escala(PV3D *v)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glScalef(v->getX(), v->getY(), v->getZ());
		GLfloat m1[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, m1);
	glPopMatrix();
	postMultiplica(m1);
}

void TAfin::postMultiplica(GLfloat *m1)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadMatrixf(_m);
		glMultMatrixf(m1);
		glGetFloatv(GL_MODELVIEW_MATRIX, _m);
	glPopMatrix();
}