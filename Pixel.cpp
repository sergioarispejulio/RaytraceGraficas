#include "Pixel.h"


Pixel::Pixel()
{
	r = 0;
	g = 0;
	b = 0;
}


Pixel::~Pixel()
{
}

Pixel::Pixel(float r1, float g1, float b1)
{
	r = r1;
	g = g1;
	b = b1;
}


Pixel Pixel::sumar(Pixel ele)
{
	Pixel aux = Pixel(r + ele.r, g + ele.g, b + ele.b);
	if (aux.r > 1.0)
		aux.r = 1;
	if (aux.g > 1.0)
		aux.g = 1;
	if (aux.b > 1.0)
		aux.b = 1;
	if (aux.r < 0)
		aux.r = 0;
	if (aux.g < 0)
		aux.g = 0;
	if (aux.b < 0)
		aux.b = 0;
	return aux;
}

Pixel Pixel::restar(Pixel ele)
{
	Pixel aux = Pixel(r - ele.r, g - ele.g, b - ele.b);
	if (aux.r > 1.0)
		aux.r = 1;
	if (aux.g > 1.0)
		aux.g = 1;
	if (aux.b > 1.0)
		aux.b = 1;
	if (aux.r < 0)
		aux.r = 0;
	if (aux.g < 0)
		aux.g = 0;
	if (aux.b < 0)
		aux.b = 0;
	return aux;
}

Pixel Pixel::multiplicar(Pixel ele)
{
	return Pixel(r * ele.r, g * ele.g, b * ele.b);
}

Pixel Pixel::multiplicarporn(float n)
{
	Pixel aux = Pixel(r * n, g *n, b * n);
	if (aux.r > 1.0)
		aux.r = 1;
	if (aux.g > 1.0)
		aux.g = 1;
	if (aux.b > 1.0)
		aux.b = 1;
	if (aux.r < 0)
		aux.r = 0;
	if (aux.g < 0)
		aux.g = 0;
	if (aux.b < 0)
		aux.b = 0;
	return aux;
}



