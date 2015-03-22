#ifndef RENDERER
#define RENDERER

#include <iostream>
#include <cstdlib>
#include <string>
#include <GL/glut.h>
#include "RendererColor.h"

using namespace std;

class Renderer
{
public:
	Renderer(int width, int height, float backRed, float backGreen, float backBlue);
	~Renderer();

	void reset();
    void initGL();
    void drawScene();
    void reshape();
    void idle();
    void saveImage();
    void render(string title, string filename);
    void reshape(int width, int height);

    virtual void keyboard(int key, int x, int y);
	virtual RendererColor calculatePixel(int i, int j);
private:	
	RendererColor backgroundColor;
	RendererColor **buffer;
	bool isDrawing;
	int x, y;
	int window;
protected:
    int width;
    int height;
};

#endif

