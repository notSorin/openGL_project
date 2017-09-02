#include "Quesito.h"
#define _USE_MATH_DEFINES
#include <cmath>

//Ángulo de revolución del quesito.
const int ANGULO_REVOLUCION = 59;

Quesito::Quesito()
{
}

Quesito::Quesito(GLfloat alturaQuesito, GLfloat radioQuesito, int nRotaciones, Color *c) : _nRotaciones(nRotaciones), _radioQuesito(radioQuesito), _alturaQuesito(alturaQuesito)
{
	_color = c;

	int puntosPerfil = 2;
	PV3D **perfil = new PV3D*[puntosPerfil];

	//Construir el perfil de la Revolución.
	perfil[0] = new PV3D(0.0f, 0.0f, radioQuesito, 1);
	perfil[1] = new PV3D(0.0f, alturaQuesito, radioQuesito, 1);

	//Tamaños de los arraya de Malla.
	_numVertices = nRotaciones * puntosPerfil + 2; //+2 del origen de coordenadas.
	_numCaras = nRotaciones * (puntosPerfil - 1) + 2; //x caras de revolución + 2 caras laterales + 1 cara superior.
	_numNormales = _numCaras;

	//Creación de los arrays de Malla.
	_vertices = new PV3D*[_numVertices];
	_normales = new PV3D*[_numNormales];
	_caras = new Cara*[_numCaras];

	//Colocar el perfil original en la tabla de vértices.
	for (int j = 0; j < puntosPerfil; j++)
		_vertices[j] = perfil[j]->clona();

	//Vértices en origen de coordenadas.
	_vertices[_numVertices - 2] = new PV3D(0.0f, 0.0f, 0.0f, 1);
	_vertices[_numVertices - 1] = new PV3D(0.0f, alturaQuesito, 0.0f, 1);

	//Vertices de la malla
	for (int i = 1; i < nRotaciones; i++)
	{
		double theta = (i * ANGULO_REVOLUCION / (double)nRotaciones) * (M_PI / 180), c = cos(theta), s = sin(theta);

		for (int j = 0; j < puntosPerfil; j++)
		{
			int indice = i * puntosPerfil + j;

			//Transformar el punto j-ésimo del perfil original.
			double x = c * perfil[j]->getX() + s * perfil[j]->getZ(), z = -s * perfil[j]->getX() + c * perfil[j]->getZ();

			_vertices[indice] = new PV3D((GLfloat)x, perfil[j]->getY(), (GLfloat)z, 1);
		}
	}

	delete perfil[0], perfil[1];
	delete[]perfil;

	//Construcción de las caras
	int indiceCara = 0;

	//Caras de la revolución.
	for (int i = 0; i < nRotaciones - 1; i++)
	{
		for (int j = 0; j < puntosPerfil - 1; j++)
		{
			int indice = i * puntosPerfil + j;
			VerticeNormal **vn = new VerticeNormal*[4];

			vn[0] = new VerticeNormal(indice, indiceCara);
			vn[1] = new VerticeNormal((indice + puntosPerfil) % _numVertices, indiceCara);
			vn[2] = new VerticeNormal((indice + 1 + puntosPerfil) % _numVertices, indiceCara);
			vn[3] = new VerticeNormal(indice + 1, indiceCara);

			_caras[indiceCara] = new Cara(4, vn);

			PV3D *v = calculoNormalNewell(_caras[indiceCara]);
			_normales[indiceCara] = v;
			indiceCara++;
		}
	}

	//Cara lateral 1.
	VerticeNormal **vn = new VerticeNormal*[4];

	vn[0] = new VerticeNormal(_numVertices - 1, indiceCara);
	vn[1] = new VerticeNormal(_numVertices - 2, indiceCara);
	vn[2] = new VerticeNormal(0, indiceCara);
	vn[3] = new VerticeNormal(1, indiceCara);

	_caras[indiceCara] = new Cara(4, vn);

	PV3D *v = calculoNormalNewell(_caras[indiceCara]);
	_normales[indiceCara] = v;

	//Cara lateral 2.
	indiceCara++;

	VerticeNormal **vn2 = new VerticeNormal*[4];

	vn2[0] = new VerticeNormal(_numVertices - 2, indiceCara);
	vn2[1] = new VerticeNormal(_numVertices - 1, indiceCara);
	vn2[2] = new VerticeNormal(_numVertices - 3, indiceCara);
	vn2[3] = new VerticeNormal(_numVertices - 4, indiceCara);

	_caras[indiceCara] = new Cara(4, vn2);

	PV3D *v2 = calculoNormalNewell(_caras[indiceCara]);
	_normales[indiceCara] = v2;

	indiceCara++;

	//Tapa quesito
	VerticeNormal **vn3 = new VerticeNormal*[nRotaciones + 1];

	vn3[0] = new VerticeNormal(nRotaciones * puntosPerfil + 1, indiceCara); //El PV3D(0, altura, 0, 1).

	//En las posiciones impares de _vertice[] están los vértices superiores de la revolución.
	for (int i = 1, a = 1; a <= nRotaciones; i += 2, a++)
		vn3[a] = new VerticeNormal(i, indiceCara);

	_caras[indiceCara] = new Cara(nRotaciones + 1, vn3);

	PV3D *v3 = calculoNormalNewell(_caras[indiceCara]);
	_normales[indiceCara] = v3;
}

Quesito::~Quesito()
{
}