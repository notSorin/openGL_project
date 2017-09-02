#include "PV3D.h"
#include <cmath>

PV3D::PV3D(GLfloat x, GLfloat y, GLfloat z, int pv) : _x(x), _y(y), _z(z), _pv(pv)
{
}

PV3D::~PV3D()
{
}

//Normaliza el PV3D actuál.
void PV3D::normaliza()
{
	GLfloat modulo = sqrt(pow(_x, 2) + pow(_y, 2) + pow(_z, 2));

	_x /= modulo;
	_y /= modulo;
	_z /= modulo;
}

PV3D *PV3D::clona()
{
	return new PV3D(_x, _y, _z, _pv);
}

GLfloat PV3D::productoEscalar(PV3D *v)
{
	return _x * v->_x + _y * v->_y + _z * v->_z;
}

PV3D *PV3D::productoVectorial(PV3D *v)
{
	return new PV3D(_y * v->_z - _z * v->_y, _z * v->_x - _x * v->_z, _x * v->_y - _y * v->_x, 1);
}