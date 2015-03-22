#include "Triangulo.h"


Triangulo::Triangulo()
{
}


Triangulo::~Triangulo()
{
}

bool Triangulo::intersecta(Camara camara)
{
	Vector3 d = camara.devolverD();
	float M = devolverM(d);
	t = devolvert(d, camara.e, M);
	std::string palabra = std::to_string(t);
	if (palabra.find('#') != -1 || palabra.find('e') != -1)
		return false;
	float V = devolverV(d, camara.e, M);
	float B = devolverB(d, camara.e, M);
	if (V > 0 && B > 0 && (V + B) < 1)
		return true;
	else
		return false;
}

bool Triangulo::intersectaluz(Vector3 e, Vector3 d)
{
	float M = devolverM(d);
	t = devolvert(d, e, M);
	std::string palabra = std::to_string(t);
	if (palabra.find('#') != -1 || palabra.find('e') != -1)
		return false;
	float V = devolverV(d, e, M);
	float B = devolverB(d, e, M);
	if (V > 0 && B > 0 && (V + B) < 1)
		return true;
	else
		return false;
}

float Triangulo::devolverM(Vector3 d)
{
	Vector3 linea1 = Vector3(A.x - B.x, A.x - C.x, d.x);
	Vector3 linea2 = Vector3(A.y - B.y, A.y - C.y, d.y);
	Vector3 linea3 = Vector3(A.z - B.z, A.z - C.z, d.z);
	float resu = determinante(linea2.y, linea2.z, linea3.y, linea3.z, linea1.x);
	resu = resu + determinante(linea2.x, linea2.z, linea3.x, linea3.z, linea1.y * -1);
	resu = resu + determinante(linea2.x, linea2.y, linea3.x, linea3.y, linea1.z);
	return resu;
}

float Triangulo::devolverB(Vector3 d, Vector3 e, float M)
{
	Vector3 linea1 = Vector3(A.x -e.x, A.x - C.x, d.x);
	Vector3 linea2 = Vector3(A.y - e.y, A.y - C.y, d.y);
	Vector3 linea3 = Vector3(A.z - e.z, A.z - C.z, d.z);
	float resu = determinante(linea2.y, linea2.z, linea3.y, linea3.z, linea1.x);
	resu = resu + determinante(linea2.x, linea2.z, linea3.x, linea3.z, linea1.y * -1);
	resu = resu + determinante(linea2.x, linea2.y, linea3.x, linea3.y, linea1.z);
	return resu / M;
}

float Triangulo::devolverV(Vector3 d, Vector3 e, float	M)
{
	Vector3 linea1 = Vector3(A.x - B.x, A.x - e.x, d.x);
	Vector3 linea2 = Vector3(A.y - B.y, A.y - e.y, d.y);
	Vector3 linea3 = Vector3(A.z - B.z, A.z - e.z, d.z);
	float resu = determinante(linea2.y, linea2.z, linea3.y, linea3.z, linea1.x);
	resu = resu + determinante(linea2.x, linea2.z, linea3.x, linea3.z, linea1.y * -1);
	resu = resu + determinante(linea2.x, linea2.y, linea3.x, linea3.y, linea1.z);
	return resu / M;
}

float Triangulo::devolvert(Vector3 d, Vector3 e, float	M)
{
	Vector3 linea1 = Vector3(A.x - B.x, A.x - C.x, A.x - e.x);
	Vector3 linea2 = Vector3(A.y - B.y, A.y - C.y, A.y - e.y);
	Vector3 linea3 = Vector3(A.z - B.z, A.z - C.z, A.z - e.z);
	float resu = determinante(linea2.y, linea2.z, linea3.y, linea3.z, linea1.x);
	resu = resu + determinante(linea2.x, linea2.z, linea3.x, linea3.z, linea1.y * -1);
	resu = resu + determinante(linea2.x, linea2.y, linea3.x, linea3.y, linea1.z);
	return resu / M;
}

float Triangulo::determinante(float x1, float y1, float x2, float y2, float ele)
{
	float resul = 0;
	resul = resul + (x1*y2);
	resul = resul + (-(x2*y1));
	resul = resul * ele;
	return resul;
}

Vector3 Triangulo::devolverNORMAL(Camara camara)
{
	Vector3 resu = B.resta(A);
	resu = resu.multiplicacionvectorial(C.resta(A));
	float aux = resu.modulo();
	resu = Vector3(resu.x / aux, resu.y / aux, resu.z / aux);
	aux = resu.modulo();
	return Vector3(resu.x / aux, resu.y / aux, resu.z / aux);
}

Vector3 Triangulo::devolverp(Camara camara)
{
	Vector3 e = camara.e;
	Vector3 d = camara.devolverD();
	Vector3 p = e.suma(d.multiplicacionnumero(t));
	return p;
}