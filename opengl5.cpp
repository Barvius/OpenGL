#include "stdafx.h"
#include <glut.h>
#include <math.h>
#include <string.h>
/*
void poly(int x1, int x2,int x3, int x4, int y1, int y2, int y3, int y4) {
	GLint X; GLint Y;
	glBegin(GL_POLYGON);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glVertex2d(x3, y3);
	glVertex2d(x4, y4);
	glEnd();

}

void drawLine(int x1, int y1, int x2, int y2) {
	const int deltaX = abs(x2 - x1);
	const int deltaY = abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;
	int error = deltaX - deltaY;
	glBegin(GL_LINES);
	glVertex2i(x2, y2);
	while (x1 != x2 || y1 != y2){
		glVertex2i(x1, y1);
		const int error2 = error * 2;
		if (error2 > -deltaY){
			error -= deltaY;
			x1 += signX;
		}
		if (error2 < deltaX){
			error += deltaX;
			y1 += signY;
		}
	}
	glEnd();
}

void DrawEllipse(float radiusX, float radiusY){
	glBegin(GL_POLYGON);
	for (int i = 0; i<360; i++){
		float rad = i*3.14159 / 180.0;
		glVertex2f(cos(rad)*radiusX, sin(rad)*radiusY);
	}
	glEnd();
}
void triangle() {
	glBegin(GL_TRIANGLES);
	glVertex2d(0, 0);
	glVertex2d(4,0);
	glVertex2d(4, 1);
	glEnd();
}

void drawDot(GLint x, GLint y) // рисуем точку 
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void cir_pix(int x0, int y0, int x, int y) // 8 точек на окружности
{
	drawDot(x0 + x, y0 + y);
	drawDot(x0 + y, y0 + x);
	drawDot(x0 + x, y0 - y);
	drawDot(x0 + y, y0 - x);
	drawDot(x0 - x, y0 - y);
	drawDot(x0 - y, y0 - x);
	drawDot(x0 - x, y0 + y);
	drawDot(x0 - y, y0 + x);
}

*/
void drawDot(GLfloat x, GLfloat y, int size) // рисуем точку 
{
	glPointSize(size);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	glFlush();
}



void DrawEllipse(float radiusX, float radiusY) {
	glBegin(GL_POLYGON);
	for (int i = 180; i <= 360; i++) {
		float rad = i*3.14159 / 180.0;
		glVertex2f(cos(rad)*radiusX, sin(rad)*radiusY);
	}
	glEnd();
}

void drawLine(int x1, int y1, int x2, int y2, int size) {
	const float deltaX = abs(x2 - x1);
	const float deltaY = abs(y2 - y1);
	const float signX = x1 < x2 ? 1 : -1;
	const float signY = y1 < y2 ? 1 : -1;
	//
	float error = deltaX - deltaY;
	//
	drawDot(x2, y2, size);
	while (x1 != x2 || y1 != y2)
	{
		drawDot(x1, y1, size);
		const int error2 = error * 2;
		//
		if (error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}
		if (error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}

}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	//glRotatef(45, 1, 1, 1);
	
	//glColor3f(0.0, 0.0, 1.0);
	glTranslated(100, 100, 0);
	DrawEllipse(60, 70);
	drawLine(-50, 0, 0, 100, 5);
	drawLine(50, 0, 0, 100, 5);
	drawLine(0, 0, 0, 100, 5);
		glTranslated(300, 75, 0);
	DrawEllipse(60, 70);
	drawLine(-50, 0, 0, 100, 5);
	drawLine(50, 0, 0, 100, 5);
	drawLine(0, 0, 0, 100, 5);


	glColor3f(0.0, 1.0, 1.0);
	drawLine(-300, 25, 0, 100, 20);
	drawLine(-150, 50, -150, -200, 20);
	//cir_pix(100,100,200,200);
	//poly(-5, 5, 5, -5, 0, 0, 7, 7);
	//glColor3f(0.5, 0.5, 0.5);
	//glTranslated(0, -2 ,0);
	//triangle();
	//glTranslated(-1, -2, 0);
	//triangle();
	glFlush();
}
void Start() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 690, 690);
	gluOrtho2D(0, 600, 0, 600);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(690, 690);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Graf");
	Start();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}