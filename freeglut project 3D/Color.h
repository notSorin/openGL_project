#pragma once
#include <GL/freeglut.h>

class Color
{
public:
	Color(GLfloat r, GLfloat g, GLfloat b);
	~Color();

	GLfloat getR()
	{
		return _r;
	}

	GLfloat getG()
	{
		return _g;
	}

	GLfloat getB()
	{
		return _b;
	}

private:
	GLfloat _r, _g, _b;
};