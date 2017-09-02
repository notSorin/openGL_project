#pragma once

#include "VerticeNormal.h"

class Cara 
{
public:
	Cara(int numVertices, VerticeNormal **arrayVn);
	~Cara();

	int getNumeroVertices()
	{
		return _numVertices;
	}

	int getIndiceNormalK(int j)
	{
		return _arrayVN[j]->getIndiceNormal();
	}
	
	int getIndiceVerticeK(int j)
	{
		return _arrayVN[j]->getIndiceVertice();
	}

private:
	int _numVertices;
	VerticeNormal **_arrayVN;
};