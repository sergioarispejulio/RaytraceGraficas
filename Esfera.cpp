#include "Esfera.h"


Esfera::Esfera()
{
}


Esfera::~Esfera()
{
}

bool Esfera::intersecta(Camara camara)
{
	Vector3 e = camara.e;
	Vector3 d = camara.devolverD();
	if (indefinido(d,e) == false)
		return false;
	t = devolvert(d, e);
	Vector3 aux = d.multiplicacionnumero(t);
	puntointerseccion = e.suma(aux);
	if (devolverbmenos4(d,e) >= 0)
		return true;
	else 
		return false;
}

bool Esfera::intersectaluz(Vector3 e, Vector3 d)
{
	std::string palabra;
	float aux = d.multiplicacionescalar(e.resta(punto)) * d.multiplicacionescalar(e.resta(punto));
	float aux1 = (d.multiplicacionescalar(d));
	aux1 = aux1 * ((e.resta(punto).multiplicacionescalar(e.resta(punto)) - (radio*radio)));
	aux = aux - aux1;
	palabra = std::to_string(aux);
	if (palabra.find('#') != -1 || palabra.find('e') != -1 )
		return false;
	if (aux >= 0)
		return true;
	else
		return false;
}

float Esfera::devolvert(Vector3 d, Vector3 e)
{
	float aux = d.multiplicacionescalar(e.resta(punto)) * d.multiplicacionescalar(e.resta(punto));
	float aux1 = (d.multiplicacionescalar(d));
	aux1 = aux1 * ((e.resta(punto).multiplicacionescalar(e.resta(punto)) - (radio*radio) ));
	aux = sqrt(aux - aux1);
	float posi1 = ((-1 * d.multiplicacionescalar(e.resta(punto))) + aux) / (d.multiplicacionescalar(d));
	float posi2 = ((-1 * d.multiplicacionescalar(e.resta(punto))) - aux) / (d.multiplicacionescalar(d));
	if (posi1 <= posi2)
		return posi1;
	else
		return posi2;
}

bool Esfera::indefinido(Vector3 d, Vector3 e)
{
	std::string palabra;
	float aux = d.multiplicacionescalar(e.resta(punto)) * d.multiplicacionescalar(e.resta(punto));
	float aux1 = (d.multiplicacionescalar(d));
	aux1 = aux1 * ((e.resta(punto).multiplicacionescalar(e.resta(punto)) - (radio*radio)));
	aux = aux - aux1;
	palabra = std::to_string(aux);
	if (palabra.find('#') != -1)
		return false;
	if (aux >= 0)
		return true;
	else
		return false;
}

float Esfera::devolverbmenos4(Vector3 d, Vector3 e)
{
	float aux = d.multiplicacionescalar(e.resta(punto)) * d.multiplicacionescalar(e.resta(punto));
	float aux1 = (d.multiplicacionescalar(d));
	aux1 = aux1 * ((e.resta(punto).multiplicacionescalar(e.resta(punto)) - (radio*radio)));
	aux = aux - aux1;
	std::string palabra = std::to_string(aux);
	if (palabra.find('#') != -1)
		return -1;
	return aux;
}

Vector3 Esfera::devolverNORMAL(Camara camara)
{
	Vector3 p = devolverp(camara);
	Vector3 resu;
	resu = p.resta(punto);
	resu = Vector3(resu.x / radio, resu.y / radio, resu.z / radio);
	float aux = resu.modulo();
	return Vector3(resu.x / aux, resu.y / aux, resu.z / aux);
}

Vector3 Esfera::devolverp(Camara camara)
{
	Vector3 e = camara.e;
	Vector3 d = camara.devolverD();
	Vector3 p = e.suma(d.multiplicacionnumero(t));
	return p;
}