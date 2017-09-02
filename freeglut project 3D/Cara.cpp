#include "Cara.h"

Cara::Cara(int numVertices, VerticeNormal **arrayVn) : _numVertices(numVertices), _arrayVN(arrayVn)
{
}

Cara::~Cara()
{
	for (int i = 0; i < _numVertices; i++)
		delete _arrayVN[i];

	delete[]_arrayVN;
}