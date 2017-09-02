#pragma once
#include "ObjetoCompuesto3D.h"
#define _USE_MATH_DEFINES
#include "Color.h"

class Ficha : public ObjetoCompuesto3D
{
public:
	Ficha(Color *c);
	~Ficha();
};