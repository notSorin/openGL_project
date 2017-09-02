#pragma once

class VerticeNormal
{
public:
	VerticeNormal(int indiceVertice, int indiceNormal);
	~VerticeNormal();

	int getIndiceNormal() const
	{
		return _indiceNormal;
	}
	
	int getIndiceVertice() const
	{
		return _indiceVertice;
	}

private:
	int _indiceVertice, _indiceNormal;
};