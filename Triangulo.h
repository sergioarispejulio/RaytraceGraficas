#pragma once
#include "Objeto.h"
#include <limits>
#include <cmath>

class Triangulo : public Objeto
{
public:
	Vector3 A;
	Vector3 B;
	Vector3 C;
	Triangulo();
	~Triangulo();
	bool intersecta(Camara camara);
	bool intersectaluz(Vector3 e, Vector3 d);
	Vector3 devolverNORMAL(Camara camara);
	Vector3 devolverp(Camara camara);
private:
	float devolverM(Vector3 d);
	float devolverB(Vector3 d, Vector3 e, float	M);
	float devolverV(Vector3 d, Vector3 e, float	M);
	float devolvert(Vector3 d, Vector3 e, float	M);
	float determinante(float x1, float y1, float x2, float y2, float ele);
};

