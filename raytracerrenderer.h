#ifndef RAYTRACERRENDERER_H
#define RAYTRACERRENDERER_H

#include "Renderer.h"
#include <vector>
#include "Camara.h"
#include "Esfera.h"
#include "Objeto.h"
#include "Luz.h"
#include "Triangulo.h"

class RayTracerRenderer : public Renderer
{
public:
	Luz luz;
	vector<Esfera> lista_esfera;
	vector<Triangulo> lista_triangulo;
	Pixel fondoambiente;
	Camara camara;
    RayTracerRenderer(int width, int height);
    virtual RendererColor calculatePixel(int i, int j);
private:
	Vector3 normalizar(Vector3 ele);
	Pixel chocaluz(Vector3 e, Vector3 d, Pixel actual);

};

#endif // RAYTRACERRENDERER_H
