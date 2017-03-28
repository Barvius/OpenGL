#include "stdafx.h"
#include <glut.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

float 
	DXn = -10, 
	DXk = 10, 
	DYn = 1024, 
	DYk = -1024,
	Xn = -10,
	Xk = 10,
	Yn, Yk;

float
	X = 1,
	Y = 1,
	Sx = 1,
	Sy = 1,
	A = 0;

void display() {
	glClear(GL_COLOR_BUFFER_BIT); // очистка окна цветом фона
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_STRIP);
	for (GLfloat x = DXn; x < DXk; x += 0.1) {
		GLfloat y = (1.85 - x) * cos(3.5 * x - 0.5);
		glVertex2f(x, y);
	}
	glEnd();
	// ось
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(DXn, 0);
	glVertex2f(DXk, 0);
	glVertex2f(0, DYn);
	glVertex2f(0, DYk);
	for (int i = DXn; i <= DXk; i++) {
		glVertex2f(i, -0.15);
		glVertex2f(i, 0.15);
	}
	for (int i = DYn; i <= DYk; i++) {
		glVertex2f(-0.15, i);
		glVertex2f(0.15, i);
	}
	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);
	char text[10];
	for (int i = DYn; i <= DYk; i++) {
		glRasterPos2i(1, i);
		sprintf(text, "%d", i);
		for (int j = 0; j < strlen(text); j++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, text[j]);
		}

	}
	for (int i = DXn; i <= DXk; i++) {
		glRasterPos2i(i, 1);
		sprintf(text, "%d", i);
		for (int j = 0; j < strlen(text); j++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, text[j]);
		}
	}
	/*
	float g = 0.009;
	sprintf(text, "%f", g);
	glRasterPos2i(3,5);
	for (int j = 0; j < strlen(text); j++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, text[j]);
	}
	*/
	
	glFlush(); // отправляем весь вывод на дисплей
}

void Start() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	for (float i = DXn; i <= DXk; i += 0.1) {
		float y = (1.85 - i) * cos(3.5 * i - 0.5);
		if (y > DYk) {
			Yk = DYk = y;
		}
		if (y < DYn) {
			Yn = DYn = y;
		}
	}
	printf("%f\t%f\n",Yn, Yk);
	gluOrtho2D(DXn, DXk, DYn, DYk);
	glViewport(DXk, DYn, DXk - DXn, DYn - DYk);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(1);
}

void Keyboard(unsigned char key, int x, int y) {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
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

	case 'e':
		A -= 10;
		glRotatef(A, 0.0f, 0.0f, 1.0f);
		break;

	case 'r':
		A += 10;
		glRotatef(A, 0.0f, 0.0f, 1.0f);
		break;
	}
	//printf("%d\n", A);
	glScaled(Sx, Sy, 0);
	glTranslated(X, Y, 0);
	display();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(720, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Graf");
	Start();
	glutDisplayFunc(display);
	glutKeyboardFunc(Keyboard);
	glutMainLoop();
	return 0;
}