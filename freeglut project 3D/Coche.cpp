#include "Coche.h"
#include "Cubo.h"
#include "Ficha.h"
#include "Cilindro.h"
#include "Faro.h"

const GLfloat VELOCIDAD = 0.5f, RATACION_RUEDAS = 10.0f;

Coche::Coche(GLuint texturas)
{
	_color = new Color(0.0f, 0.0f, 0.0f);
	_numHijos = 12;
	_hijos = new Objeto3D*[_numHijos];

	//Cuerpo
	_hijos[0] = new Cubo(new Color(0.8f, 0.0f, 0.0f), texturas);
	_hijos[0]->escala(&PV3D(4.0f, 2.0f, 2.0f, 1));

	//Rueda 1
	_hijos[1] = new Ficha(new Color(0.1f, 0.1f, 0.1f));
	_hijos[1]->traslada(&PV3D(1.5f, -0.5f, 1.0f, 1));
	_hijos[1]->rota(&PV3D(1.0f, 0.0f, 0.0f, 1), 90);

	//Rueda 2
	_hijos[2] = new Ficha(new Color(0.1f, 0.1f, 0.1f));
	_hijos[2]->traslada(&PV3D(-1.5f, -0.5f, 1.0f, 1));
	_hijos[2]->rota(&PV3D(1.0f, 0.0f, 0.0f, 1), 90);

	//Rueda 3
	_hijos[3] = new Ficha(new Color(0.1f, 0.1f, 0.1f));
	_hijos[3]->traslada(&PV3D(-1.5f, -0.5f, -1.0f, 1));
	_hijos[3]->rota(&PV3D(1.0f, 0.0f, 0.0f, 1), -90);

	//Rueda 4
	_hijos[4] = new Ficha(new Color(0.1f, 0.1f, 0.1f));
	_hijos[4]->traslada(&PV3D(1.5f, -0.5f, -1.0f, 1));
	_hijos[4]->rota(&PV3D(1.0f, 0.0f, 0.0f, 1), -90);

	//Faro 1
	_hijos[5] = new Faro(0.4f, 0.2f, 10, 4, new Color(0.1f, 0.1f, 0.9f), 1);
	_hijos[5]->traslada(&PV3D(2.2f, 0.3f, 0.6f, 1));
	_hijos[5]->rota(&PV3D(0.0f, 1.0f, 0.0f, 1), -90);

	//Faro 2
	_hijos[11] = new Faro(0.4f, 0.2f, 10, 4, new Color(0.1f, 0.1f, 0.9f), 2);
	_hijos[11]->traslada(&PV3D(2.2f, 0.3f, -0.6f, 1));
	_hijos[11]->rota(&PV3D(0.0f, 1.0f, 0.0f, 1), -90);

	//Parabrisas
	_hijos[6] = new Cubo(new Color(1.0f, 1.0f, 1.0f), -1);
	_hijos[6]->traslada(&PV3D(1.0f, 1.3f, 0.0f, 1));
	_hijos[6]->rota(&PV3D(0.0f, 0.0f, 1.0f, 1), 30);
	_hijos[6]->escala(&PV3D(0.3f, 1.0f, 1.7f, 1));

	//Alerón
	_hijos[7] = new Cubo(new Color(0.0f, 1.0f, 0.0f), -1);
	_hijos[7]->traslada(&PV3D(-1.5f, 1.5f, 0.0f, 1));
	_hijos[7]->escala(&PV3D(0.3f, 0.3f, 1.7f, 1));

	//Parte alerón 1
	_hijos[8] = new Cubo(new Color(0.0f, 1.0f, 0.0f), -1);
	_hijos[8]->traslada(&PV3D(-1.5f, 1.2f, -0.8f, 1));
	_hijos[8]->rota(&PV3D(0.0f, 0.0f, 1.0f, 1), 90);
	_hijos[8]->escala(&PV3D(1.0f, 0.3f, 0.3f, 1));

	//Parte alerón 2
	_hijos[9] = new Cubo(new Color(0.0f, 1.0f, 0.0f), -1);
	_hijos[9]->traslada(&PV3D(-1.5f, 1.2f, 0.8f, 1));
	_hijos[9]->rota(&PV3D(0.0f, 0.0f, 1.0f, 1), 90);
	_hijos[9]->escala(&PV3D(1.0f, 0.3f, 0.3f, 1));

	//Tubo de escape
	_hijos[10] = new Cilindro(0.3f, 0.8f, 10, 4, new Color(0.0f, 1.0f, 1.0f));
	_hijos[10]->traslada(&PV3D(-2.5f, -0.5f, 0.4f, 1));
	_hijos[10]->rota(&PV3D(0.0f, 1.0f, 0.0f, 1), 90);
}

Coche::~Coche()
{
}

void Coche::girarIzquierda()
{
	rota(&PV3D(0.0f, 1.0f, 0.0f, 1), 5);
}

void Coche::girarDerecha()
{
	rota(&PV3D(0.0f, 1.0f, 0.0f, 1), -5);
}

void Coche::avanzar()
{
	//Rotar las ruedas.
	_hijos[1]->rota(&PV3D(0.0f, 1.0f, 0.0f, 1), -RATACION_RUEDAS);
	_hijos[2]->rota(&PV3D(0.0f, 1.0f, 0.0f, 1), -RATACION_RUEDAS);
	_hijos[3]->rota(&PV3D(0.0f, 1.0f, 0.0f, 1), RATACION_RUEDAS);
	_hijos[4]->rota(&PV3D(0.0f, 1.0f, 0.0f, 1), RATACION_RUEDAS);

	//Mover el coche.
	traslada(&PV3D(VELOCIDAD, 0.0f, 0.0f, 1));
}

void Coche::retroceder()
{
	//Rotar las ruedas.
	_hijos[1]->rota(&PV3D(0.0f, 1.0f, 0.0f, 1), RATACION_RUEDAS);
	_hijos[2]->rota(&PV3D(0.0f, 1.0f, 0.0f, 1), RATACION_RUEDAS);
	_hijos[3]->rota(&PV3D(0.0f, 1.0f, 0.0f, 1), -RATACION_RUEDAS);
	_hijos[4]->rota(&PV3D(0.0f, 1.0f, 0.0f, 1), -RATACION_RUEDAS);

	//Mover el coche.
	traslada(&PV3D(-VELOCIDAD, 0.0f, 0.0f, 1));
}

void Coche::encenderFaros()
{
	((Faro *)_hijos[5])->encenderFaro();
	((Faro *)_hijos[11])->encenderFaro();
}

void Coche::apagarFaros()
{
	((Faro *)_hijos[5])->apagarFaro();
	((Faro *)_hijos[11])->apagarFaro();
}