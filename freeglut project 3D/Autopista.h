#pragma once
#include "ObjetoCompuesto3D.h"
#include "Color.h"

class Autopista : public ObjetoCompuesto3D
{
public:
	Autopista(Color *c);
	~Autopista();
};