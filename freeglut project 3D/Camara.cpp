#include "Camara.h"
#define _USE_MATH_DEFINES
#include <cmath>

Camara::Camara(){};

Camara::Camara(GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ, GLdouble lookX, GLdouble lookY, GLdouble lookZ, GLdouble upX, GLdouble upY, GLdouble upZ)
{
	_eye = new PV3D(eyeX, eyeY, eyeZ, 1);
	_look = new PV3D(lookX, lookY, lookZ, 1);
	_up = new PV3D(upX, upY, upZ, 0);

	setUpCamera();

	actualizarVectores();
}

Camara::~Camara()
{
}

void Camara::setUpCamera()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(_eye->getX(), _eye->getY(), _eye->getZ(), _look->getX(), _look->getY(), _look->getZ(), _up->getX(), _up->getY(), _up->getZ());
}

void Camara::actualizarVectores()
{
	_n = new PV3D(_eye->getX() - _look->getX(), _eye->getY() - _look->getY(), _eye->getZ() - _look->getZ(), 0);
	_n->normaliza();
	_u = _up->productoVectorial(_n);
	_u->normaliza();
	_v = _n->productoVectorial(_u);
}

void Camara::recorre(GLdouble x, GLdouble y, GLdouble z)
{
	GLfloat nuevaX, nuevaY, nuevaZ;

	nuevaX = _eye->getX();
	nuevaX += x;
	_eye->setX(nuevaX);

	nuevaY = _eye->getY();
	nuevaY += y;
	_eye->setY(nuevaY);

	nuevaZ = _eye->getZ();
	nuevaZ += z;
	_eye->setZ(nuevaZ);

	setUpCamera();
	actualizarVectores();
}

void Camara::giraX(GLdouble alfa)
{
	if (!(_eye->getY() == 0 && _eye->getZ() == 0))
	{
		GLdouble radio = sqrt(pow(_eye->getY(), 2) + pow(_eye->getZ(), 2)); //Se obtiene el radio actual aplicando pitágoras
		GLdouble pos = atan2(_eye->getZ(), _eye->getY()); //Arcotangente de dos puntos para saber el angulo actual del ojo
		GLdouble auxY = radio * cos(pos + alfa * M_PI / 180); //Nueva Y sera el radio actual por el coseno de la posicion actual mas a la que vamos
		GLdouble auxZ = radio * sin(pos + alfa *M_PI / 180); //Nueva Z sera el radio actual por el seno de la posicion actual mas a la que vamos

		_eye->setY(auxY); //Poiscinar el ojo en las nueva coordenada Y
		_eye->setZ(auxZ); //Poiscinar el ojo en las nueva coordenada Z

		actualizarVectores(); //Actualizar los vectores
		activaMatriz(); //Activar su matriz
	}
}

void Camara::giraY(GLdouble alfa)
{
	if (!(_eye->getX() == 0 && _eye->getZ() == 0))
	{
		GLdouble radio = sqrt(pow(_eye->getX(), 2) + pow(_eye->getZ(), 2)); //Se obtiene el radio actual aplicando pitágoras
		GLdouble pos = atan2(_eye->getZ(), _eye->getX()); //Arcotangente de dos puntos para saber el angulo actual del ojo
		GLdouble auxX = radio * cos(pos + alfa * M_PI / 180); //Nueva x sera el radio actual por el coseno de la posicion actual mas a la que vamos
		GLdouble auxZ = radio * sin(pos + alfa * M_PI / 180); //Nueva Z sera el radio actual por el seno de la posicion actual mas a la que vamos

		_eye->setX(auxX); //Poiscinar el ojo en las nueva coordenada X
		_eye->setZ(auxZ); //Poiscinar el ojo en las nueva coordenada Z

		actualizarVectores(); //Actualizar los vectores
		activaMatriz(); //Activar su matriz
	}
}

void Camara::giraZ(GLdouble alfa)
{
	if (!(_eye->getX() == 0 && _eye->getY() == 0))
	{
		GLdouble radio = sqrt(pow(_eye->getX(), 2) + pow(_eye->getY(), 2)); //Se obtiene el radio actual aplicando pitágoras
		GLdouble pos = atan2(_eye->getY(), _eye->getX()); //Arcotangente de dos puntos para saber el angulo actual del ojo
		GLdouble auxX = radio * cos(pos + alfa * M_PI / 180); //Nueva x sera el radio actual por el coseno de la posicion actual mas a la que vamos
		GLdouble auxY = radio * sin(pos + alfa * M_PI / 180); //Nueva y sera el radio actual por el seno de la posicion actual mas a la que vamos
		
		_eye->setX(auxX); //Poiscinar el ojo en las nueva coordenada X
		_eye->setY(auxY); //Poiscinar el ojo en las nueva coordenada Y

		actualizarVectores(); //Actualizar los vectores
		activaMatriz(); //Activar su matriz
	}
}

void Camara::roll(GLdouble alfa)
{
	//Se deja fijo el n.
	PV3D *aux = _u->clona();
	GLdouble uX, uY, uZ, vX, vY, vZ;

	uX = cos(alfa) * aux->getX() + sin(alfa) * _v->getX();
	uY = cos(alfa) * aux->getY() + sin(alfa) * _v->getY();
	uZ = cos(alfa) * aux->getZ() + sin(alfa) * _v->getZ();

	_u->setX(uX);
	_u->setY(uY);
	_u->setZ(uZ);

	vX = -sin(alfa) * aux->getX() + cos(alfa) * _v->getX();
	vY = -sin(alfa) * aux->getY() + cos(alfa) * _v->getY();
	vZ = -sin(alfa) * aux->getZ() + cos(alfa) * _v->getZ();

	_v->setX(vX);
	_v->setY(vY);
	_v->setZ(vZ);

	activaMatriz();
}

void Camara::yaw(GLdouble alfa)
{
	//Se deja fijo el v.
	PV3D *aux = _u->clona();
	GLdouble uX, uY, uZ, nX, nY, nZ;

	uX = cos(alfa) * aux->getX() - sin(alfa) * _n->getX();
	uY = cos(alfa) * aux->getY() - sin(alfa) * _n->getY();
	uZ = cos(alfa) * aux->getZ() - sin(alfa) * _n->getZ();

	_u->setX(uX);
	_u->setY(uY);
	_u->setZ(uZ);

	nX = sin(alfa) * aux->getX() + cos(alfa) * _n->getX();
	nY = sin(alfa) * aux->getY() + cos(alfa) * _n->getY();
	nZ = sin(alfa) * aux->getZ() + cos(alfa) * _n->getZ();

	_n->setX(nX);
	_n->setY(nY);
	_n->setZ(nZ);

	activaMatriz();
}

void Camara::pitch(GLdouble alfa)
{
	//Se deja fijo el u.
	PV3D *auxV = _v->clona(), *auxN = _n->clona();
	GLdouble vX, vY, vZ, nX, nY, nZ;

	vX = cos(alfa) * auxV->getX() + sin(alfa) * auxN->getX();
	vY = cos(alfa) * auxV->getY() + sin(alfa) * auxN->getY();
	vZ = cos(alfa) * auxV->getZ() + sin(alfa) * auxN->getZ();

	_v->setX(vX);
	_v->setY(vY);
	_v->setZ(vZ);

	nX = -sin(alfa) * auxV->getX() + cos(alfa) * auxN->getX();
	nY = -sin(alfa) * auxV->getY() + cos(alfa) * auxN->getY();
	nZ = -sin(alfa) * auxV->getZ() + cos(alfa) * auxN->getZ();

	_n->setX(nX);
	_n->setY(nY);
	_n->setZ(nZ);

	activaMatriz();
}

void Camara::activaMatriz()
{
	GLdouble matriz[16];

	glMatrixMode(GL_MODELVIEW);

	matriz[0] = _u->getX();			matriz[4] = _u->getY();			matriz[8] = _u->getZ();			matriz[12] = -_eye->productoEscalar(_u);
	matriz[1] = _v->getX();		    matriz[5] = _v->getY();			matriz[9] = _v->getZ();			matriz[13] = -_eye->productoEscalar(_v);
	matriz[2] = _n->getX();			matriz[6] = _n->getY();			matriz[10] = _n->getZ();		matriz[14] = -_eye->productoEscalar(_n);
	matriz[3] = 0;					matriz[7] = 0;					matriz[11] = 0;					matriz[15] = 1;

	glLoadMatrixd(matriz);
}

void Camara::esquina(PV3D* esquina)
{
	//El ojo se situa en la esquina que se pasa por parametro.
	_look = new PV3D(0, 0, 0, 0);
	_eye = esquina;
	_up = new PV3D(0, 1, 0, 0);
	
	actualizarVectores();
	activaMatriz();
}

void Camara::lateral()
{
	//El ojo se sitúa con la coordenada X las demás se quedan a 0.
	_look = new PV3D(0, 0, 0, 0);
	_eye = new PV3D(getEyeX(), 0, 0, 0);
	_up = new PV3D(0, 1, 0, 0);

	actualizarVectores();
	activaMatriz();
}

void Camara::frontal()
{
	//El ojo se sitúa con la coordenada Z las demás se quedan a 0.
	_look = new PV3D(0, 0, 0, 0);
	_eye = new PV3D(0, 0, getEyeZ(), 0);
	_up = new PV3D(0, 1, 0, 0);

	actualizarVectores();
	activaMatriz();
}

void Camara::cenital()
{
	//El ojo se sitúa con la coordenada Y las demás se quedan a 0.
	//El vector up cambia para orientar la cámara en el sentido de las Z's.
	_look = new PV3D(0, 0, 0, 0);
	_eye = new PV3D(0, getEyeY(), 0, 0);
	_up = new PV3D(0, 0, 1, 0);

	actualizarVectores();
	activaMatriz();
}