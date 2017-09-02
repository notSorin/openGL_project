#pragma once
#include "PV3D.h"

class Camara
{
public:
	Camara();
	Camara(GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ, GLdouble lookX, GLdouble lookY, GLdouble lookZ, GLdouble upX, GLdouble upY, GLdouble upZ);

	GLfloat getEyeX() const 
	{ 
		return _eye->getX(); 
	}

	GLfloat getEyeY() const 
	{ 
		return _eye->getY(); 
	}

	GLfloat getEyeZ() const 
	{ 
		return _eye->getZ(); 
	}

	~Camara();
	void setUpCamera();
	void actualizarVectores();
	void recorre(GLdouble x, GLdouble y, GLdouble z);
	void giraX(GLdouble alfa);
	void giraY(GLdouble alfa);
	void giraZ(GLdouble alfa);
	void roll(GLdouble alfa);
	void yaw(GLdouble alfa);
	void pitch(GLdouble alfa);
	void activaMatriz();
	void esquina(PV3D* esquina);
	void lateral();
	void frontal();
	void cenital();

private:
	PV3D *_eye, *_look, *_up, *_u, *_v, *_n;
};