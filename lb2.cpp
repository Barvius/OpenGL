#include "stdafx.h"
#include <glut.h>
#include <math.h>
#include <string.h>
void display() {
	float min = 1000, max = 0;
	glClear(GL_COLOR_BUFFER_BIT); // очистка окна цветом фона
	glBegin(GL_LINE_STRIP);
	for (GLfloat x = -10.0; x < 10.0; x += 0.1){
		GLfloat y = (1.85 - x) * cos(3.5 * x - 0.5);
		glVertex2f(x, y);
		printf("%f\t%f\n",x,y);
	}
	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	for (GLfloat x = -10.0; x < 10.0; x += 0.1) {
		GLfloat y = (1.85 - x) * cos(3.5 * x - 0.5);
		if (y <= 0.2 && y >= -0.2){  
			glVertex2f(x, y - 0.15);
			glVertex2f(x, y + 0.15);
		}
		
		
	}

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-10,0);
	glVertex2f(10, 0);
	glVertex2f(0, -15);
	glVertex2f(0, 15);
	

	for (int i = -15; i < 15; i++){
		glVertex2f(-0.15, i);
		glVertex2f(0.15, i);
		glRasterPos2i(1, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
		glVertex2f(i, -0.15);
		glVertex2f(i, 0.15);
	}

	
	glEnd();

	glFlush(); // отправляем весь вывод на дисплей
}

void Start() {
	float min = 1000, max = 0;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	for (float i = -10; i < 10.0; i += 0.1) {
		float y = (1.85 - i) * cos(3.5 * i - 0.5);
		if (y > max) {
			max = y;
		}
		if (y < min) {
			min = y;
		}
	}
	printf("%f\t%f\n", min, max);
	gluOrtho2D(-10, 10, min, max);
	//gluOrtho2D(-10, 10, -12, 12);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(1);
}
/*
void setWindowMir(float left, float right, float bottom, float top) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);
}
void setViewEkr(int left, int right, int bottom, int top){
	glViewport(left, bottom, right - left, top - bottom);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
}
*/
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1280, 690);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Graf");
	Start();
	//setViewEkr(-10,10,-10,10);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}