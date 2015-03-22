#include "Renderer.h"

using namespace std;

Renderer::Renderer(int width, int height, float backRed, float backGreen, float backBlue)
	: backgroundColor(backRed, backGreen, backBlue)
{
	this->width = width;
	this->height = height;
	buffer = new RendererColor*[this->width];
	
	for (int i = 0; i < this->width; i++)
		buffer[i] = new RendererColor[this->height];
	reset();
}


Renderer::~Renderer()
{
	for (int i = 0; i < this->width; i++)
		delete[] buffer[i];
	delete[] buffer;
}

void Renderer::reset()
{
	isDrawing = true;
	x = 0;
	y = 0;
}

RendererColor Renderer::calculatePixel(int i, int j)
{
	RendererColor color;

	return color;
}

void Renderer::keyboard(int key, int x, int y)
{
	switch (key)
	{
	case '\27':
		glutDestroyWindow(window);
		exit(0);
	default:
		break;
	}
	glutPostRedisplay();
}

void Renderer::initGL()
{
    glClearColor(backgroundColor.getRed(), backgroundColor.getGreen(), backgroundColor.getBlue(), 0.0f);
}

void Renderer::drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    glOrtho(0.0, width, 0.0, height, 1, -1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glBegin(GL_POINTS);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            glColor3f(buffer[i][j].getRed(), buffer[i][j].getGreen(), buffer[i][j].getBlue());
			glVertex2i(i, j);
        }
    }
    glEnd();
    glFlush();
}

void Renderer::reshape(int width, int height)
{
    this->width = width;
    this->height = height;
    for (int i = 0; i < this->width; i++)
        delete[] buffer[i];
    delete[] buffer;

    buffer = new RendererColor*[this->width];

    for (int i = 0; i < this->width; i++)
        buffer[i] = new RendererColor[this->height];
	glViewport(0, 0, this->width, this->height);
    reset();
}

void Renderer::idle()
{
    if(isDrawing) {
        buffer[x][y] = calculatePixel(x, y);
        ++x;

        if (x >= width) {
            x = 0;
            ++y;
            glutPostRedisplay();
        }

        if (y >= height) {
            isDrawing = false;
            glutPostRedisplay();
        }
    }
}

void Renderer::saveImage()
{
//TODO Implement this
}
