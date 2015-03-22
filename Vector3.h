#pragma once
#include <cmath>

class Vector3
{
public:
	float x;
	float y;
	float z;
	Vector3();
	Vector3(float x1, float y1, float z1);
	~Vector3();
	Vector3 suma(Vector3 ele);
	Vector3 resta(Vector3 ele);
	float multiplicacionescalar(Vector3 ele);
	Vector3 multiplicacionvectorial(Vector3 ele);
	float modulo();
	Vector3 multiplicacionnumero(float num);
private:
	float determinante(float x1, float y1, float x2, float y2);
};

