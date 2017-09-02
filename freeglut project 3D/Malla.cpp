#include "Malla.h"

Malla::Malla()
{
	_textura = -1;
	_color = nullptr;
}

Malla::Malla(GLuint textura)
{
	_textura = textura;
	_color = nullptr;
}

Malla::~Malla()
{
	for (int i = 0; i < _numVertices; i++)
		delete _vertices[i];

	delete[]_vertices;

	for (int i = 0; i < _numNormales; i++)
		delete _normales[i];

	delete[]_normales;

	for (int i = 0; i < _numCaras; i++)
		delete _caras[i];

	delete[]_caras;
}

void Malla::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMultMatrixf(_mT->getM());

		for (int i = 0; i < _numCaras; i++)
		{
			glLineWidth(1.0);

			if (_textura != -1 && i == 3)
				glEnable(GL_TEXTURE_2D);
			glBegin(GL_POLYGON); //o glBegin(GL_LINE_LOOP);

			for (int j = 0; j < _caras[i]->getNumeroVertices(); j++)
			{
				int iN = _caras[i]->getIndiceNormalK(j);
				int iV = _caras[i]->getIndiceVerticeK(j);

				glNormal3f(_normales[iN]->getX(), _normales[iN]->getY(), _normales[iN]->getZ());

				if (i == 3 && _textura != -1)
				{
					switch (j)
					{
					case 0:
						glTexCoord2f(0, 0);
						break;
					case 1:
						glTexCoord2f(0, 1);
						break;
					case 2:
						glTexCoord2f(1, 1);
						break;
					case 3:
						glTexCoord2f(1, 0);
						break;
					}
				}
				
				glVertex3f(_vertices[iV]->getX(), _vertices[iV]->getY(), _vertices[iV]->getZ());
			}
			
			glEnd();
			if (_textura != -1 && i == 3)
				glDisable(GL_TEXTURE_2D);
		}
		
	glPopMatrix();
}

PV3D* Malla::calculoNormalNewell(Cara* c)
{
	GLfloat nx = 0.0, ny = 0.0, nz = 0.0;
	PV3D *verticeActual = NULL, *verticeSig = NULL;
	int nV = c->getNumeroVertices();

	for (int i = 0; i < nV; i++)
	{
		verticeActual = _vertices[c->getIndiceVerticeK(i)];
		verticeSig = _vertices[c->getIndiceVerticeK((i + 1) % c->getNumeroVertices())];

		nx += (verticeActual->getY() - verticeSig->getY()) * (verticeActual->getZ() + verticeSig->getZ());
		ny += (verticeActual->getZ() - verticeSig->getZ()) * (verticeActual->getX() + verticeSig->getX());
		nz += (verticeActual->getX() - verticeSig->getX()) * (verticeActual->getY() + verticeSig->getY());
	}

	PV3D *n = new PV3D(nx, ny, nz, 0);

	n->normaliza();

	return n;
}

void Malla::dibujarNormales()
{
	glColor3f(1.0f, 1.0f, 1.0f);

	for (int i = 0; i < _numCaras ; i++)
	{
		Cara* c = _caras[i];

		int nVertices = c->getNumeroVertices(),
			v0 = c->getIndiceVerticeK(0),
			v1 = c->getIndiceVerticeK(1),
			v2 = c->getIndiceVerticeK(nVertices / 2),
			v3 = c->getIndiceVerticeK(nVertices - 1),
			n = c->getIndiceNormalK(0);

		GLdouble vX = (_vertices[v0]->getX() + _vertices[v1]->getX() + _vertices[v2]->getX() + _vertices[v3]->getX()) / 4,
				 vY = (_vertices[v0]->getY() + _vertices[v1]->getY() + _vertices[v2]->getY() + _vertices[v3]->getY()) / 4,
				 vZ = (_vertices[v0]->getZ() + _vertices[v1]->getZ() + _vertices[v2]->getZ() + _vertices[v3]->getZ()) / 4;

		glBegin(GL_LINES);
		glVertex3d(vX, vY, vZ);
		glVertex3d(_normales[n]->getX() + vX, _normales[n]->getY() + vY, _normales[n]->getZ() + vZ);
		glEnd();
	}
}