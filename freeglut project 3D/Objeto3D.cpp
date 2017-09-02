#include "Objeto3D.h"

Objeto3D::Objeto3D()
{
	_mT = new TAfin();
}

Objeto3D::~Objeto3D()
{
	delete _mT, _color;
}

void Objeto3D::traslada(PV3D *v)
{
	_mT->traslada(v);
}

void Objeto3D::rota(PV3D *v, GLfloat alfa)
{
	_mT->rota(v, alfa);
}

void Objeto3D::escala(PV3D *v)
{
	_mT->escala(v);
}