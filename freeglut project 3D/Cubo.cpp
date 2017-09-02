#include "Cubo.h"

Cubo::Cubo(Color *c, GLuint texturas)
{
	_color = c;
	_numCaras = 6;
	_numNormales = _numCaras;
	_numVertices = 8;
	_textura = texturas;

	_caras = new Cara*[_numCaras];
	_normales = new PV3D*[_numNormales];
	_vertices = new PV3D*[_numVertices];

	_vertices[0] = new PV3D(-0.5f, -0.5f, 0.5f, 1);
	_vertices[1] = new PV3D(0.5f, -0.5f, 0.5f, 1);
	_vertices[2] = new PV3D(0.5f, 0.5f, 0.5f, 1);
	_vertices[3] = new PV3D(-0.5f, 0.5f, 0.5f, 1);
	_vertices[4] = new PV3D(0.5f, 0.5f, -0.5f, 1);
	_vertices[5] = new PV3D(0.5f, -0.5f, -0.5f, 1);
	_vertices[6] = new PV3D(-0.5f, -0.5f, -0.5f, 1);
	_vertices[7] = new PV3D(-0.5f, 0.5f, -0.5f, 1);

	VerticeNormal **v = new VerticeNormal*[4];
	v[0] = new VerticeNormal(0, 0);
	v[1] = new VerticeNormal(1, 0);
	v[2] = new VerticeNormal(2, 0);
	v[3] = new VerticeNormal(3, 0);

	_caras[0] = new Cara(4, v);
	_normales[0] = calculoNormalNewell(_caras[0]);
		 
	v = new VerticeNormal*[4];
	v[0] = new VerticeNormal(4, 1);
	v[1] = new VerticeNormal(5, 1);
	v[2] = new VerticeNormal(6, 1);
	v[3] = new VerticeNormal(7, 1);

	_caras[1] = new Cara(4, v);
	_normales[1] = calculoNormalNewell(_caras[1]);

	v = new VerticeNormal*[4];
	v[0] = new VerticeNormal(3, 2);
	v[1] = new VerticeNormal(7, 2);
	v[2] = new VerticeNormal(6, 2);
	v[3] = new VerticeNormal(0, 2);

	_caras[2] = new Cara(4, v);
	_normales[2] = calculoNormalNewell(_caras[2]);

	v = new VerticeNormal*[4];
	v[0] = new VerticeNormal(7, 3);
	v[1] = new VerticeNormal(3, 3);
	v[2] = new VerticeNormal(2, 3);
	v[3] = new VerticeNormal(4, 3);

	_caras[3] = new Cara(4, v);
	_normales[3] = calculoNormalNewell(_caras[3]);

	v = new VerticeNormal*[4];
	v[0] = new VerticeNormal(4, 4);
	v[1] = new VerticeNormal(2, 4);
	v[2] = new VerticeNormal(1, 4);
	v[3] = new VerticeNormal(5, 4);

	_caras[4] = new Cara(4, v);
	_normales[4] = calculoNormalNewell(_caras[4]);

	v = new VerticeNormal*[4];
	v[0] = new VerticeNormal(1, 5);
	v[1] = new VerticeNormal(0, 5);
	v[2] = new VerticeNormal(6, 5);
	v[3] = new VerticeNormal(5, 5);

	_caras[5] = new Cara(4, v);
	_normales[5] = calculoNormalNewell(_caras[5]);
}

Cubo::~Cubo()
{
}