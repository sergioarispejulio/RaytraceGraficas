#pragma once
#include "Vector3.h"
#include <math.h> 

class Camara
{
public:
	Vector3 e;
	Vector3 vp;
	Vector3 pv;
	int i;
	int j;
	int nx;
	int ny;
	float grados;
	float distanciafocal;
	Camara();
	~Camara();
	Vector3 devolverV();
	Vector3 devolverW();
	Vector3 devolverU();
	Vector3 devolverDV();
	Vector3 devolverD();
	float devolverr();
	float devolvert();
	float devolverl();
	float devolverb();
	float devolveru();
	float devolverv();
};

