#pragma once
#include "Malla.h"
#include "Color.h"

class Quesito : public Malla
{
public:
	Quesito();
	Quesito(GLfloat alturaQuesito, GLfloat radioQuesito, int nRotaciones, Color *c);
	~Quesito();

private:
	int _nRotaciones;
	GLfloat _radioQuesito, _alturaQuesito;
};