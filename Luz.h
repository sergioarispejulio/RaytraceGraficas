#pragma once
#include "Pixel.h"
#include "Camara.h"
#include "Esfera.h"
#include "Triangulo.h"

class Luz
{
public:
	Vector3 punto;
	Pixel color;
	Luz();
	~Luz();
	Pixel calcularpixelesfera(Camara camara, Esfera esfera);
	Pixel calcularpixeltriangulo(Camara camara, Triangulo triangulo);
	Pixel calcularpixelsombraesfera(Camara camara, Esfera esfera, Pixel actu);
	Pixel calcularpixelsombratriangulo(Camara camara, Triangulo triangulo, Pixel actu);
private:
	Vector3 devolverH(Vector3 v, Vector3 l);
	Vector3 normalizar(Vector3 ele);
	float maximo(float valor1, float valor2);

};

