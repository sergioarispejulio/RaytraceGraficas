#pragma once
class Pixel
{
public:
	float r;
	float g;
	float b;
	Pixel();
	~Pixel();
	Pixel(float r1, float g1, float b1);
	Pixel sumar(Pixel ele);
	Pixel restar(Pixel ele);
	Pixel multiplicar(Pixel ele);
	Pixel multiplicarporn(float n);
};

