#include "stdafx.h"
#include <glut.h>
#include <math.h>
#include <string.h>

float
X = 1,
Y = 1,
Z = 1,
Sx = 1,
Sy = 1,
Sz = 1,
A = 45,
B = 45,
C = 45;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glRotatef(45, 1, 1, 1);
	glColor3f(1.0, 0.0, 0.0);
	glutWireCube(5);
	glFlush();
	GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

}

void Start() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 690, 690);
	glOrtho(-10, 10, -10, 10, -10, 10);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glPointSize(1);
	glMatrixMode(GL_MODELVIEW);

}

void Keyboard(unsigned char key, int x, int y) {
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	/*
	ws - Xscale
	ad - Yscale
	zx - Zscale
	tg - Xpos
	fh - Ypos
	cv - Zpos
	uj - Xrotate
	ik - Yrotate
	ol - Zrotate
	*/
	switch (key) {
	case 'd':
		Sx += 0.1;
		break;
	case 'a':
		Sx -= 0.1;
		break;
	case 'w':
		Sy += 0.1;
		break;
	case 's':
		Sy -= 0.1;
		break;
	case 'z':
		Sx += 0.1;
		break;
	case 'x':
		Sx -= 0.1;
		break;
	case 't':
		Y += 1;
		break;
	case 'g':
		Y -= 1;
		break;
	case 'h':
		X += 1;
		break;
	case 'f':
		X -= 1;
		break;
	case 'c':
		Z += 1;
		break;
	case 'v':
		Z -= 1;
		break;
	case 'u':
		A -= 1;
		break;
	case 'j':
		A += 1;
		break;
	case 'i':
		B -= 1;
		break;
	case 'k':
		B += 1;
		break;
	case 'o':
		C -= 1;
		break;
	case 'l':
		C += 1;
		break;
	}
	glRotatef(A, 1.0f, 0.0f, 0.0f);
	glRotatef(B, 0.0f, 1.0f, 0.0f);
	glRotatef(C, 0.0f, 0.0f, 1.0f);
	glScaled(Sx, Sy, Sz);
	glTranslated(X, Y, Z);
	display();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(690, 690);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Graf");
	Start();
	glutDisplayFunc(display);
	glutKeyboardFunc(Keyboard);
	glutMainLoop();
	return 0;
}