#include "ObjetoCompuesto3D.h"

ObjetoCompuesto3D::ObjetoCompuesto3D()
{
}

ObjetoCompuesto3D::~ObjetoCompuesto3D()
{
	for (int i = 0; i < _numHijos; i++)
		delete _hijos[i];

	delete[]_hijos;
}

void ObjetoCompuesto3D::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMultMatrixf(_mT->getM());

		for (int i = 0; i < _numHijos; i++)
		{
			glColor3f(_hijos[i]->getColor()->getR(), _hijos[i]->getColor()->getG(), _hijos[i]->getColor()->getB());
			_hijos[i]->dibuja();
		}
	glPopMatrix();
}