#pragma once
#include "Objeto.h"

class Esfera : public Objeto
{
public:
	float radio;
	Vector3 punto;
	Vector3 puntointerseccion;
	float t;
	Esfera();
	~Esfera();
	bool intersecta(Camara camara);
	bool intersectaluz(Vector3 e, Vector3 d);
	bool indefinido(Vector3 d, Vector3 e);
	Vector3 devolverNORMAL(Camara camara);
	Vector3 devolverp(Camara camara);
private:
	float devolvert(Vector3 d, Vector3 e);
	float devolverbmenos4(Vector3 d, Vector3 e);
};

