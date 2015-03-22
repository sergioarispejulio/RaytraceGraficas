#include "Camara.h"


Camara::Camara()
{
}


Camara::~Camara()
{
}

Vector3 Camara::devolverV()
{
	float modulo = vp.modulo();
	return Vector3(vp.x/modulo,vp.y/modulo,vp.z/modulo);
}

Vector3 Camara::devolverW()
{
	Vector3 dv = devolverDV();
	float modulo = dv.modulo();
	return Vector3((dv.x*-1 / modulo), (dv.y*-1 / modulo), (dv.z*-1 / modulo));
}

Vector3 Camara::devolverU()
{
	Vector3 v = devolverV();
	Vector3 w = devolverW();
	Vector3 multi = v.multiplicacionvectorial(w);
	float modulo = multi.modulo();
	return Vector3(multi.x / modulo, multi.y / modulo, multi.z / modulo);
}

Vector3 Camara::devolverDV()
{
	return pv.resta(e);
}

Vector3 Camara::devolverD()
{
	Vector3 ele1 = devolverW().multiplicacionnumero(-1 * distanciafocal);
	Vector3 ele2 = devolverU().multiplicacionnumero(devolveru());
	Vector3 ele3 = devolverV().multiplicacionnumero(devolverv());
	return ele1.suma(ele2).suma(ele3);
}

float Camara::devolverr()
{
	return ((float)nx / (float)ny) * devolvert();
}

float Camara::devolvert()
{
	return distanciafocal * tan((grados / 2)*3.14159 / 180);
}

float Camara::devolverl()
{
	return -1 * devolverr();
}

float Camara::devolverb()
{
	return -1 * devolvert();
}

float Camara::devolveru()
{
	return devolverl() + ((devolverr() - devolverl()) * ((i + 0.5) / nx));
}

float Camara::devolverv()
{
	return devolverb() + ((devolvert() - devolverb()) * ((j + 0.5) / ny));
}
