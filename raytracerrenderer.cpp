#include "raytracerrenderer.h"

RayTracerRenderer::RayTracerRenderer(int width, int height)
    :Renderer(width, height, 0.0f, 0.0f, 0.0f)
{
	camara.e = Vector3(278.0, 273.0, -800.0);
	camara.pv = Vector3(278.0, 273.0, -700.0);
	camara.vp = Vector3(0, 1.0, 0);
	camara.distanciafocal = 0.035;
	camara.nx = width;
	camara.ny = height;
	camara.grados = 39.31;

	fondoambiente = Pixel(0.2, 0.2, 0.2);
	lista_esfera.resize(2);
	lista_esfera[0].colordifuso = Pixel(0.156, 0.126, 0.506);
	lista_esfera[0].colorespecular = Pixel(0.9, 0.9, 0.9);
	lista_esfera[0].punto = Vector3(379.0, 120.0, 370.0);
	lista_esfera[0].radio = 100;
	lista_esfera[0].coeficienteespecular = 100.0;
	lista_esfera[1].colordifuso = Pixel(0.656, 0.626, 0.107);
	lista_esfera[1].colorespecular = Pixel(0, 0, 0);
	lista_esfera[1].punto = Vector3(120.0, 100.0, 130.0);
	lista_esfera[1].radio = 120;
	lista_esfera[1].coeficienteespecular = 1.0;

	lista_triangulo.resize(2);
	lista_triangulo[0].A = Vector3(552.8, 0, 0);
	lista_triangulo[0].B = Vector3(0, 0, 0);
	lista_triangulo[0].C = Vector3(0, 0, 559.2);
	lista_triangulo[0].colordifuso = Pixel(0, 0.4, 0);
	lista_triangulo[0].colorespecular = Pixel(0, 0, 0);
	lista_triangulo[0].coeficienteespecular = 1.0;

	lista_triangulo[1].A = Vector3(0, 0, 559.2);
	lista_triangulo[1].B = Vector3(549.6, 0,552.8);
	lista_triangulo[1].C = Vector3(552.8, 0, 0);
	lista_triangulo[1].colordifuso = Pixel(0, 0.4, 0);
	lista_triangulo[1].colorespecular = Pixel(0, 0, 0);
	lista_triangulo[1].coeficienteespecular = 1.0;

	luz.color = Pixel(0.8, 0.7, 0.6);
	luz.punto = Vector3(270.0, 547.0, 279.5);
}

RendererColor RayTracerRenderer::calculatePixel(int i, int j)
{
    RendererColor color((float)i / width, (float)j / height, 1.0f);
	Pixel aux;
	aux.r = color.getRed();
	aux.b = color.getBlue();
	aux.g = color.getGreen();
	camara.i = i;
	camara.j = j;
	float t = 9999999999999999999;
	for (int z = 0; z < lista_esfera.size(); z++)
	{
		if (lista_esfera[z].intersecta(camara))
		{
			if (lista_esfera[z].t < t && lista_esfera[z].t > 0)
			{
				aux = luz.calcularpixelesfera(camara, lista_esfera[z]);
				color.setRed(aux.r);
				color.setGreen(aux.g);
				color.setBlue(aux.b);
				t = lista_esfera[z].t;
			}
			else
			{
				Vector3 p = lista_esfera[z].devolverp(camara);
				Vector3 v = normalizar(camara.e.resta(p));
				Vector3 l = normalizar(luz.punto.resta(p));
				aux = chocaluz(p, l, aux);
			}
		}
	}
	for (int z = 0; z < lista_triangulo.size(); z++)
	{
		if (lista_triangulo[z].intersecta(camara))
		{
			if (lista_triangulo[z].t < t && lista_triangulo[z].t > 0)
			{
				aux = luz.calcularpixeltriangulo(camara, lista_triangulo[z]);
				color.setRed(aux.r);
				color.setGreen(aux.g);
				color.setBlue(aux.b);
				t = lista_triangulo[z].t;
			}
			else
			{
				Vector3 p = lista_triangulo[z].devolverp(camara);
				Vector3 v = normalizar(camara.e.resta(p));
				Vector3 l = normalizar(luz.punto.resta(p));
				aux = chocaluz(p, l, aux);
			}
		}
	}
    return color;
}

Vector3 RayTracerRenderer::normalizar(Vector3 ele)
{
	float aux = ele.modulo();
	return Vector3(ele.x / aux, ele.y / aux, ele.z / aux);
}

Pixel RayTracerRenderer::chocaluz(Vector3 e, Vector3 d, Pixel actual)
{
	Pixel resu = actual;
	float t = 9999999999999999999;
	for (int z = 0; z < lista_esfera.size(); z++)
	{
		if (lista_esfera[z].intersectaluz(e,d))
		{
			if (lista_esfera[z].tdeluz < t && lista_esfera[z].tdeluz >= 0)
			{
				resu = lista_esfera[z].colordifuso.multiplicar(fondoambiente);
			}
		}
	}
	for (int z = 0; z < lista_triangulo.size(); z++)
	{
		if (lista_triangulo[z].intersectaluz(e, d))
		{
			if (lista_triangulo[z].tdeluz < t && lista_triangulo[z].tdeluz >= 0)
			{
				resu = lista_triangulo[z].colordifuso.multiplicar(fondoambiente);
			}
		}
	}
	return resu;
}
