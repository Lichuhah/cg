#include <Windows.h>
#include <glut.h>
#include <ctime>
#include <iostream>
using namespace std;

void draw(void)
{

	glShadeModel(GL_SMOOTH);
	GLfloat front_color[] = { 0,1,0,1 };
	GLfloat back_color[] = { 0,0,1,1 };


	glBegin(GL_TRIANGLE_STRIP);
	glColor3ub(200, 200, 200);
	float MatDiffuse1[] = { 1.0f, 0.0f, 0.0f, 0.0f };
	float MatSpecular1[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	float MatShininess1 = 0.0f;
	float MatEmission1[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDiffuse1); //рассеянный свет
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular1); //отраженный свет
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatShininess1); //степень отражаемого света
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, MatEmission1); //излучаемый свет
	glVertex3f(-3.0f, 0.0f, 0.0f);
	glVertex3f(-1.5f, -1.5f, 3.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glColor3ub(200, 0, 0);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.5f, -1.5f, 3.0f);
	glVertex3f(0.0f, -3.0f, 0.0f);
	
	glVertex3f(0.0f, -3.0f, 0.0f);
	glVertex3f(-1.5f, -1.5f, 3.0f);
	glVertex3f(-3.0f, -3.0f, 0.0f);
	
	glVertex3f(-3.0f, -3.0f, 0.0f);
	glVertex3f(-1.5f, -1.5f, 3.0f);
	glVertex3f(-3.0f, 0.0f, 0.0f);
	
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	float MatDiffuse2[] = { 0.0f, 1.0f, 0.0f, 1.0f };
	float MatSpecular2[] = { 1.0f, 1.0f,1.0f, 1.0f };
	float MatShininess2 = 0.0f;
	float MatEmission2[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	glColor3ub(200, 200, 200);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDiffuse2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular2);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatShininess2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, MatEmission2);
	glVertex3f(-6.0f, -3.0f, 0.0f);
	glVertex3f(-4.5f, -4.5f, 3.0f);
	glVertex3f(-3.0f, -3.0f, 0.0f);

	glVertex3f(-3.0f, -3.0f, 0.0f);
	glVertex3f(-4.5f, -4.5f, 3.0f);
	glVertex3f(-3.0f, -6.0f, 0.0f);
	
	glVertex3f(-3.0f, -6.0f, 0.0f);
	glVertex3f(-4.5f, -4.5f, 3.0f);
	glVertex3f(-6.0f, -6.0f, 0.0f);
	
	glVertex3f(-6.0f, -6.0f, 0.0f);
	glVertex3f(-4.5f, -4.5f, 3.0f);
	glVertex3f(-6.0f, -3.0f, 0.0f);

	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	float MatDiffuse3[] = { 0.0f, 0.0f, 1.0f, 0.0f };
	float MatSpecular3[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	float MatShininess3 = 0;
	float MatEmission3[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	
	glColor3ub(200, 200, 200);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDiffuse3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular3);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatShininess3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, MatEmission3);
	glVertex3f(-9.0f, -6.0f, 0.0f);
	glVertex3f(-7.5f, -7.5f, 3.0f);
	glVertex3f(-6.0f, -6.0f, 0.0f);

	
	glVertex3f(-6.0f, -6.0f, 0.0f);
	glVertex3f(-7.5f, -7.5f, 3.0f);
	glVertex3f(-6.0f, -9.0f, 0.0f);

	
	glVertex3f(-6.0f, -9.0f, 0.0f);
	glVertex3f(-7.5f, -7.5f, 3.0f);
	glVertex3f(-9.0f, -9.0f, 0.0f);

	glVertex3f(-9.0f, -9.0f, 0.0f);
	glVertex3f(-7.5f, -7.5f, 3.0f);
	glVertex3f(-9.0f, -6.0f, 0.0f);

	glEnd();


}
void init_l() {
	float light0_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };// устанавливаем диффузный цвет света
	GLfloat light0_position[] = { 1.0, 1.0, 4.0, 1.0 }; // позиция источника света
	GLfloat light0_spot_direction[] = { 0.3, 0.0, -1.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	glColor3f(0.0, 0.0, 0.0);
	glDisable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHTING);
	glLightModelf(GL_LIGHT_MODEL_AMBIENT, GL_TRUE);
	glEnable(GL_LIGHT0); // разрешаем использовать light0 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse); // устанавливаем источнику света light0 диффузный свет, который указали ранее 
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position); // устанавливаем положение источника света, указанное ранее 
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_diffuse);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 30);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light0_spot_direction);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 15.0);
}
GLfloat spin = 0.0;
GLfloat speed = 0.005;
void RenderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
	init_l();
	
	
	glEnable(GL_NORMALIZE);
	
	gluLookAt(16.0, 16.0, 18.0, 1.0, 1.0, 4.0, 3.0, 3.0, 3.0);
	glRotatef(spin, 0, 0, 0.01);
	draw();
	spin += speed;
	glutSwapBuffers();
}


void Systemthing(int w, int h) {

	float ratio = w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}





	int main(int argc, char* argv[])
	{
		glutInit(&argc, argv);

		srand(time(NULL));

		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

		glutInitWindowSize(800, 680);
		glutInitWindowPosition(200, 170);
		glutCreateWindow("lab3");

		glutDisplayFunc(RenderScene);
		glutReshapeFunc(Systemthing);
		glutIdleFunc(RenderScene);

		glutMainLoop();

		return 0;
	}

