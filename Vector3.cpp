#include "Vector3.h"


Vector3::Vector3(float x1, float y1, float z1)
{
	x = x1;
	y = y1;
	z = z1;
}

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}



Vector3::~Vector3()
{
}

Vector3 Vector3::suma(Vector3 ele)
{
	return Vector3(x + ele.x, y + ele.y, z + ele.z);
}

Vector3 Vector3::resta(Vector3 ele)
{
	return Vector3(x - ele.x, y - ele.y, z - ele.z);
}

Vector3 Vector3::multiplicacionvectorial(Vector3 ele)
{
	float posx = determinante(y,z,ele.y,ele.z);
	float posy = determinante(x, z, ele.x, ele.z) * -1;
	float posz = determinante(x, y, ele.x, ele.y);
	return Vector3(posx,posy,posz);
}

float Vector3::determinante(float x1, float y1, float x2, float y2)
{
	float resul = 0;
	resul = resul + (x1*y2);
	resul = resul + (-(x2*y1));
	return resul;
}

float Vector3::multiplicacionescalar(Vector3 ele)
{
	float resu = 0;
	resu = resu + (x*ele.x);
	resu = resu + (y*ele.y);
	resu = resu + (z*ele.z);
	return resu;
}


float Vector3::modulo()
{
	float resu = 0;
	resu = resu + pow(x, 2);
	resu = resu + pow(y, 2);
	resu = resu + pow(z, 2);
	return sqrt(resu);
}

Vector3 Vector3::multiplicacionnumero(float num)
{
	return Vector3(x*num, y*num, z*num);
}
