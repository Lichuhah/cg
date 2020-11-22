#include <iostream>
#include <glut.h>

using namespace std;

float WinWid = 400, WinHei = 400;
float angle = 0.0, scale = 1.0;


void timer(int value) {
	angle++;
	glRotatef(15.0, 0, 10.0, 0);
	glutPostRedisplay();
	glutTimerFunc(70, timer, 0);
}


void init() {

	glClearColor(0.0, 0.0, 0.0, 1.0);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glOrtho(-WinWid / 2, WinWid / 2, -WinHei / 2, WinHei / 2, -200.0, 200.0);

	glMatrixMode(GL_MODELVIEW);

}


void draw() {

	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();

	glColor3ub(255, 0, 255);
	glBegin(GL_TRIANGLES);
	glVertex2f(-50.0f, -50.0f);
	glVertex2f(0.0f, 50.0);
	glVertex2f(50.0f, -50.0f);
	glEnd();
	glPopMatrix();
	glutSwapBuffers();

}


int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);


	glutInitWindowSize(WinWid, WinHei);
	glutInitWindowPosition(400, 150);
	glutCreateWindow("lab1");


	glutDisplayFunc(draw);
	glutTimerFunc(60, timer, 0);

	init();

	glutMainLoop();

}