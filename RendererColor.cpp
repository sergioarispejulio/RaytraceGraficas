#include "RendererColor.h"

RendererColor::RendererColor(float red, float green, float blue)
{
	setRed(red);
	setGreen(green);
	setBlue(blue);
}

void RendererColor::setRed(float red)
{
	this->red = red;
}

void RendererColor::setGreen(float green)
{
	this->green = green;
}

void RendererColor::setBlue(float blue)
{
	this->blue = blue;
}

float RendererColor::getRed() const
{
	return red;
}

float RendererColor::getGreen() const
{
	return green;
}

float RendererColor::getBlue() const
{
	return blue;
}