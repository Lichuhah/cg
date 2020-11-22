#include <Windows.h>
#include <glut.h>
#include <ctime>
#include <iostream>
using namespace std;
GLdouble up_val_camera = 1.0;
GLdouble up_val_speed = 0.05;
GLdouble eyex = -16.0, eyey = -16.0, eyez = 15.0;
GLdouble centerx = 1.0, centery = 1.0, centerz = 0.0;
GLdouble upx = 1., upy = 1.0, upz = 1.0;

void draw(void)
{

	glShadeModel(GL_SMOOTH);
	GLfloat front_color[] = { 0,1,0,1 };
	GLfloat back_color[] = { 0,0,1,1 };
	float MatDiffuse1[] = { 1.0f, 0.0f, 0.0f, 0.0f };
	float MatSpecular1[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	float MatShininess1 = 0.0f;
	float MatEmission1[] = { 1.0f, 1.0f, 1.0f, 1.0f };


	for (float i = 5; i < 9; i += 2.0f) {
		glBegin(GL_TRIANGLE_STRIP);
		glColor3ub(200, 200, 200);
		//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDiffuse1);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular1);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatShininess1);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, MatEmission1);
		glVertex3f(-9.0f + i, -6.0f + i, 0.0f);
		glVertex3f(-7.5f + i, -7.5f + i, 3.0f);
		glVertex3f(-6.0f + i, -6.0f + i, 0.0f);


		glVertex3f(-6.0f + i, -6.0f + i, 0.0f);
		glVertex3f(-7.5f + i, -7.5f + i, 3.0f);
		glVertex3f(-6.0f + i, -9.0f + i, 0.0f);


		glVertex3f(-6.0f + i, -9.0f + i, 0.0f);
		glVertex3f(-7.5f + i, -7.5f + i, 3.0f);
		glVertex3f(-9.0f + i, -9.0f + i, 0.0f);

		glVertex3f(-9.0f + i, -9.0f + i, 0.0f);
		glVertex3f(-7.5f + i, -7.5f + i, 3.0f);
		glVertex3f(-9.0f + i, -6.0f + i, 0.0f);

		glEnd();
	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);
	float MatDiffuse2[] = { 1.0f, 1.0f, 1.0f, 0.0f };
	float MatSpecular2[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float MatShininess2 = 2.0f;
	float MatEmission2[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	for (float i = 5; i < 9; i += 2.0f) {
		glBegin(GL_TRIANGLE_STRIP);
		glColor3ub(200, 200, 200);
		//	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDiffuse2);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular2);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatShininess2);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, MatEmission2);
		glVertex3f(9.0f - i, -6.0f + i, 0.0f);
		glVertex3f(7.5f - i, -7.5f + i, 3.0f);
		glVertex3f(6.0f - i, -6.0f + i, 0.0f);


		glVertex3f(6.0f - i, -6.0f + i, 0.0f);
		glVertex3f(7.5f - i, -7.5f + i, 3.0f);
		glVertex3f(6.0f - i, -9.0f + i, 0.0f);


		glVertex3f(6.0f - i, -9.0f + i, 0.0f);
		glVertex3f(7.5f - i, -7.5f + i, 3.0f);
		glVertex3f(9.0f - i, -9.0f + i, 0.0f);

		glVertex3f(9.0f - i, -9.0f + i, 0.0f);
		glVertex3f(7.5f - i, -7.5f + i, 3.0f);
		glVertex3f(9.0f - i, -6.0f + i, 0.0f);

		glEnd();
	}
	glDisable(GL_BLEND);

	
	
	for (float i = 5; i < 9; i += 2.0f) {
		glBegin(GL_TRIANGLE_STRIP);
		glColor3ub(200, 200, 200);
		//	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDiffuse2);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular2);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatShininess2);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, MatEmission2);
		glVertex3f(9.0f - i, -6.0f + i, 0.0f);
		glVertex3f(7.5f - i, -7.5f + i, 3.0f);
		glVertex3f(6.0f - i, -6.0f + i, 0.0f);


		glVertex3f(6.0f - i, -6.0f + i, 0.0f);
		glVertex3f(7.5f - i, -7.5f + i, 3.0f);
		glVertex3f(6.0f - i, -9.0f + i, 0.0f);


		glVertex3f(6.0f - i, -9.0f + i, 0.0f);
		glVertex3f(7.5f - i, -7.5f + i, 3.0f);
		glVertex3f(9.0f - i, -9.0f + i, 0.0f);

		glVertex3f(9.0f - i, -9.0f + i, 0.0f);
		glVertex3f(7.5f - i, -7.5f + i, 3.0f);
		glVertex3f(9.0f - i, -6.0f + i, 0.0f);

		glEnd();
	}



}

void draw2(void)
{
	//glTranslatef(5.0, 5.0, 5.0);
	
	glTranslatef(-4.0, -4.0, 0.0);
	//glutSolidTeapot(3.0f);
	/*glutSolidSphere(3,10,5);
	glutSolidTorus(3, 5, 2, 3);*/
}
GLfloat light0_position[] = { 1.0, -4.0, 3.0, 1.0 };
GLfloat light1_position[] = { -20.0, 0.0, 0.0, 1.0 };
GLfloat light2_position[] = { -10.0, 12.0, 4.0, 1.0 };
void init_l(float a1, float a2, float a3) {
	float light0_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };// устанавливаем диффузный цвет света
	 // позиция источника света
	GLfloat light0_spot_direction[] = { 0.3, 0.0, -1.0 };
	light0_position[0] += a1;
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
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 18);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light0_spot_direction);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 5.0);

	float light1_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };// устанавливаем диффузный цвет света
	light1_position[0] += a2; // позиция источника света
	GLfloat light1_spot_direction[] = { 0.3, 0.0, -1.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	glColor3f(0.0, 0.0, 0.0);
	glDisable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHTING);
	glLightModelf(GL_LIGHT_MODEL_AMBIENT, GL_TRUE);
	glEnable(GL_LIGHT1); // разрешаем использовать light0 
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse); // устанавливаем источнику света light0 диффузный свет, который указали ранее 
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position); // устанавливаем положение источника света, указанное ранее 

	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_diffuse);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 18);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light1_spot_direction);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 5.0);

	float light2_diffuse[] = { 0.0, 0.0, 1.0, 1.0 };// устанавливаем диффузный цвет света
	light2_position[0] += a3; // позиция источника света
	GLfloat light2_spot_direction[] = { 0.4, 0.0, -1.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	glColor3f(0.0, 0.0, 0.0);
	glDisable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHTING);
	glLightModelf(GL_LIGHT_MODEL_AMBIENT, GL_TRUE);
	glEnable(GL_LIGHT2); // разрешаем использовать light0 
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse); // устанавливаем источнику света light0 диффузный свет, который указали ранее 
	glLightfv(GL_LIGHT2, GL_POSITION, light2_position); // устанавливаем положение источника света, указанное ранее 

	glLightfv(GL_LIGHT2, GL_SPECULAR, light2_diffuse);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 18);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light2_spot_direction);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 5.0);

}

GLfloat spin = 0.0;
GLfloat speed = 0.000;
void RenderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
	init_l(0,0,0);


	glEnable(GL_NORMALIZE);
	gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);
	//gluLookAt(16.0, 16.0, 10.0, 1.0, 1.0, 2.0, 3.0, 3.0, 3.0);
	glRotatef(spin, 0, 0, 0.01);
	draw();
	//spin += speed;
	glutSwapBuffers();
}


void Systemthing(int w, int h) {

	float ratio = w * 1.2 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}


void Keyboard(unsigned char key, int x, int y)
{

	switch (key)
	{
	case 'w':
		eyez += up_val_camera; break;
	case 's':
		eyez -= up_val_camera; break;
	case 'a':
		spin += 1;	 break;
	case 'd':
		spin -= 1;	 break;
	case 'b':
		init_l(-1.0f, 0.0f, 0.0f); break;
	case 'n':
		init_l(0.0f, -1.0f, 0.0f); break;
	case 'm':
		init_l(0.0f, 0.0f, -1.0f); break;
	case 'B':
		init_l(1.0f, 0.0f, 0.0f); break;
	case 'N':
		init_l(0.0f, 1.0f, 0.0f); break;
	case 'M':
		init_l(0.0f, 0.0f, 1.0f); break;
	}


}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	srand(time(NULL));

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(1240, 1020);
	glutInitWindowPosition(200, 170);
	glutCreateWindow("lab4");

	glutDisplayFunc(RenderScene);
	glutReshapeFunc(Systemthing);
	glutIdleFunc(RenderScene);
	glutKeyboardFunc(Keyboard);
	glutMainLoop();

	return 0;
}

