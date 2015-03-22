#include "Luz.h"


Luz::Luz()
{
}


Luz::~Luz()
{
}

Pixel Luz::calcularpixelesfera(Camara camara, Esfera esfera)
{
	Vector3 Normal = esfera.devolverNORMAL(camara);
	Vector3 p = esfera.devolverp(camara);
	Vector3 v = normalizar(camara.e.resta(p));
	Vector3 l = normalizar(punto.resta(p));
	Vector3 H = devolverH(v, l);
	H = normalizar(H);
	float aux = maximo(0, Normal.multiplicacionescalar(l));
	Pixel resu = esfera.colordifuso.multiplicar(color.multiplicarporn(aux));
	resu = esfera.colordifuso.multiplicar(color).sumar(resu);
	aux = maximo(0, Normal.multiplicacionescalar(H));
	resu = resu.sumar(esfera.colorespecular.multiplicar(color.multiplicarporn(pow(aux,esfera.coeficienteespecular))));
	return resu;
	
}

Pixel Luz::calcularpixeltriangulo(Camara camara, Triangulo triangulo)
{
	Vector3 Normal = triangulo.devolverNORMAL(camara);
	Vector3 p = triangulo.devolverp(camara);
	Vector3 v = camara.e.resta(p);
	Vector3 l = normalizar(punto.resta(p));
	Vector3 H = devolverH(v, l);
	H = normalizar(H);
	float aux = maximo(0, Normal.multiplicacionescalar(l));
	Pixel resu = triangulo.colordifuso.multiplicar(color.multiplicarporn(aux));
	resu = triangulo.colordifuso.multiplicar(color).sumar(resu);
	aux = maximo(0, Normal.multiplicacionescalar(H)); 
	resu = resu.sumar(triangulo.colorespecular.multiplicar(color.multiplicarporn(pow(aux,triangulo.coeficienteespecular))));
	return resu;
}

Pixel Luz::calcularpixelsombraesfera(Camara camara, Esfera esfera, Pixel actu)
{
	Vector3 Normal = esfera.devolverNORMAL(camara);
	Vector3 p = esfera.devolverp(camara);
	Vector3 v = normalizar(camara.e.resta(p));
	Vector3 l = normalizar(punto.resta(p));
	Vector3 H = devolverH(v, l);
	H = normalizar(H);
	float aux = maximo(0, Normal.multiplicacionescalar(l));
	Pixel resul = actu.sumar(esfera.colordifuso.multiplicar(color.multiplicarporn(aux)));
	aux = Normal.multiplicacionescalar(H);
	resul = resul.sumar(esfera.colorespecular.multiplicar(color.multiplicarporn(pow(aux,esfera.coeficienteespecular))));
	return resul;
}

Pixel Luz::calcularpixelsombratriangulo(Camara camara, Triangulo triangulo, Pixel actu)
{
	Vector3 Normal = triangulo.devolverNORMAL(camara);
	Vector3 p = triangulo.devolverp(camara);
	Vector3 v = camara.e.resta(p);
	Vector3 l = normalizar(punto.resta(p));
	Vector3 H = devolverH(v, l);
	H = normalizar(H);
	float aux = maximo(0, Normal.multiplicacionescalar(l));
	Pixel resul = actu.sumar(triangulo.colordifuso.multiplicar(color.multiplicarporn(aux)));
	aux = Normal.multiplicacionescalar(H);
	resul = resul.sumar(triangulo.colorespecular.multiplicar(color.multiplicarporn(pow(aux, triangulo.coeficienteespecular))));
	return resul;
}

Vector3 Luz::devolverH(Vector3 v, Vector3 l)
{
	Vector3 resul = v.suma(l);
	float aux = resul.modulo();
	return Vector3(resul.x / aux, resul.y / aux, resul.z / aux);
}


float Luz::maximo(float valor1, float valor2)
{
	if (valor1 >= valor2)
		return valor1;
	else
		return valor2;
}

Vector3 Luz::normalizar(Vector3 ele)
{
	float aux = ele.modulo();
	return Vector3(ele.x / aux, ele.y / aux, ele.z / aux);
}
