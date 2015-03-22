#include <iostream>
#include <GL/glut.h>
#include "raytracerrenderer.h"

using namespace std;

void drawScene();
void reshape(int width, int height);
void keyboard(unsigned char, int x, int y);
void idle();
void initGL();

Renderer *renderer;

int main(int argc, char *argv[])
{
    renderer = new RayTracerRenderer(640, 480);
	int window;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
	
    window = glutCreateWindow("RayTracing");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);
    initGL();
    glutMainLoop();
}


void drawScene() {
    renderer->drawScene();
}

void reshape(int width, int height) {
    renderer->reshape(width, height);
}

void keyboard(unsigned char key, int x, int y) {
    renderer->keyboard(key, x, y);
}

void idle() {
    renderer->idle();
}

void initGL() {
    renderer->initGL();
}

