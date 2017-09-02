#pragma once

#include <GL\freeglut.h>

class PV3D 
{
public:
	PV3D(GLfloat x, GLfloat y, GLfloat z, int pv);
	~PV3D();

	//Normaliza el PV3D.
	void normaliza();

	//Clonar el PV3D actuál.
	//DEVUELVE NEW.
	PV3D *clona();
	
	//Producto Escalar entre dos PV3D.
	GLfloat productoEscalar(PV3D *v);

	//Producto Vectorial entre dos PV3D.
	//DEVUELVE NEW.
	PV3D *productoVectorial(PV3D *v);

	GLfloat getX() const
	{
		return _x;
	}
	
	GLfloat getY() const
	{
		return _y;
	}
	
	GLfloat getZ() const
	{
		return _z;
	}

	void setX(GLfloat x)
	{
		_x = x;
	}

	void setY(GLfloat y)
	{
		_y = y;
	}

	void setZ(GLfloat z)
	{
		_z = z;
	}

	int getPV() const
	{
		return _pv;
	}

private:
	GLfloat _x, _y, _z;
	int _pv;
};