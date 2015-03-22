#pragma once
#include "Pixel.h"
#include "Camara.h"
#include "Vector3.h"
#include <string>

class Objeto
{
public:
	Objeto();
	~Objeto();
	Pixel colordifuso;
	Pixel colorespecular;
	float coeficienteespecular;
	float t;
	float tdeluz;
	bool intersecta(Camara camara);
};

