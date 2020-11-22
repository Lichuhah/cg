#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <GL/glew.h>
#include <glut.h>
#include <ctime>
#include <iostream>
#include <stdlib.h> // for rand functions
#include <stdio.h>
#include <math.h>
#include <glaux.h>    

#pragma comment(lib,"glaux.lib")
#pragma comment (lib, "legacy_stdio_definitions.lib")
using namespace std;
GLdouble up_val_camera = 1.0;
GLdouble up_val_speed = 0.05;
GLdouble eyex = 1, eyey = 1, eyez =35;
GLdouble centerx = 1.0, centery = 1.0, centerz = 0.0;
GLdouble upx = -0.05, upy = 0.2, upz = 0.0;
GLfloat ctrlpoints[4][4][3] = {
 {{-13.5, 1.0, -11.5}, {-12.5, 1.0,-11.5 }, {12.5, 1.0, -11.5 }, {13.5, 1.0,-11.5}},
 {{-13.5, 1.0, -10.5}, {-12.5, 1.0,-10.5 }, {12.5, 1.0, -10.5 }, {13.5, 1.0,-10.5}},
 {{-13.5, 1.0,  10.5}, {-12.5, 1.0, 10.5 },{ 12.5, 1.0,  10.5 }, {13.5, 1.0, 10.5}},
 {{-13.5, 1.0,  11.5}, {-12.5, 1.0, 11.5 }, {12.5, 1.0,  11.5 }, {13.5, 1.0, 10.5}}
};
GLfloat light0_position[] = { 10.0, -10.0, 10.0, 1.0 };
GLfloat light1_position[] = { -20.0, 10.0, 10.0, 1.0 };
GLfloat light2_position[] = { -10.0, 10.0, 10.0, 1.0 };

GLfloat spin = 0.0;
GLfloat speed = 0.000;

GLuint  texture[6];

void LoadTexture()
{
	glEnable(GL_TEXTURE_2D);
	AUX_RGBImageRec* texture2;
	texture2 = auxDIBImageLoad(L"pic.bmp");
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture2->sizeX, texture2->sizeY, 0,
		GL_RGB, GL_UNSIGNED_BYTE, texture2->data);
	glGenTextures(1, &texture[1]);
}

void draw2(void)
{

	glShadeModel(GL_SMOOTH);
	int i, j;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glRotatef(25.0, 1.0, 1.0, 1.0);
	for (j = 0; j <= 8; j++) {
		glBegin(GL_LINE_STRIP);
		for (i = 0; i <= 30; i++)
			glEvalCoord2f((GLfloat)i / 30.0, (GLfloat)j / 8.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
		for (i = 0; i <= 30; i++)
			glEvalCoord2f((GLfloat)j / 8.0, (GLfloat)i / 30.0);
		glEnd();
	}
	glPopMatrix();
	glFlush();

	glColor3d(1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(-50, 0, 0);
	glVertex3f(50, 0, 0);
	glEnd();
	glColor3d(0, 1, 0);
	glBegin(GL_LINES);
	glVertex3f(0, -50, 0);
	glVertex3f(0, 50, 0);
	glEnd();
	glColor3d(0, 0, 1);
	glBegin(GL_LINES);
	glVertex3f(0, 0, -50);
	glVertex3f(0, 0, 50);
	glEnd();

	float MatDiffuse1[] = { 1.0f, 1.0f, 1.0f, 0.0f };
	float MatSpecular1[] = { 1.0f, 1.0f, 1.0f, 0.0f };
	float MatShininess1 = 5.0f;
	float MatEmission1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glNewList(1, GL_COMPILE);
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular1);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatShininess1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, MatEmission1);
	glColor3ub(200, 200, 200);
	glBegin(GL_QUADS);
	for (double i = 0; i > -1; i -=0.2) {
		cout << i;
		// задняя грань
		glVertex3f(-1.0f-i, 1.0f - 2*i, 0.0f + i); glTexCoord2d(0, 0);
		glVertex3f(-1.0f - i, 5.0f - 2 * i, 0.0f + i); glTexCoord2d(0, 1);
		glVertex3f(1.0f+i, 5.0f - 2 * i, 0.0f + i); glTexCoord2d(1, 1);
		glVertex3f(1.0f + i, 1.0f - 2 * i, 0.0f + i); glTexCoord2d(1, 0);

		// левая грань
		glVertex3f(-1.0f - i, 1.0f - 2 * i, 0.0f + i); glTexCoord2d(0, 0);
		glVertex3f(-1.0f - i, 5.0f - 2 * i, 0.0f + i); glTexCoord2d(0, 1);
		glVertex3f(-1.0f - i, 5.0f - 2 * i, 3.0f + i); glTexCoord2d(1, 1);
		glVertex3f(-1.0f - i, 1.0f - 2 * i, 3.0f + i); glTexCoord2d(1, 0);

		// правая грань
		glVertex3f(1.0f+i, 1.0f - 2 * i, 0.0f + i); glTexCoord2d(0, 0);
		glVertex3f(1.0f + i, 5.0f - 2 * i, 0.0f + i); glTexCoord2d(0, 1);
		glVertex3f(1.0f + i, 5.0f - 2 * i, 3.0f + i); glTexCoord2d(1, 1);
		glVertex3f(1.0f + i, 1.0f - 2 * i, 3.0f + i); glTexCoord2d(1, 0);
		// передняя грань
		glVertex3f(-1.0f - i, 1.0f - 2 * i, 3.0f + i); glTexCoord2d(0, 0);
		glVertex3f(-1.0f - i, 5.0f - 2 * i, 3.0f + i); glTexCoord2d(0, 1);
		glVertex3f(1.0f + i, 5.0f - 2 * i, 3.0f + i); glTexCoord2d(1, 1);
		glVertex3f(1.0f + i, 1.0f - 2 * i, 3.0f + i); glTexCoord2d(1, 0);
	}
	// передняя грань
	glEnd();
	glEndList();
	
	glCallList(1);
	for (double i = 45.0; i < 360.0; i += 45.0) {
		glPushMatrix();
		glRotatef(i, 0.0, 0.0, 1.0);
		glCallList(1);
		glPopMatrix();
	}

}

void init_fog() {
	GLuint filter;                          // Используемый фильтр для текстур

	GLuint fogMode[] = { GL_EXP, GL_EXP2, GL_LINEAR }; // Хранит три типа тумана

	GLuint fogfilter = 2;                    // Тип используемого тумана

	GLfloat fogColor[4] = { 0.5f, 0.5f, 0.5f, 1.0f }; // Цвет тумана

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);      // Будем очищать экран, заполняя его цветом тумана. ( Изменено )


	glEnable(GL_FOG);                       // Включает туман (GL_FOG)

	glFogi(GL_FOG_MODE, fogMode[fogfilter]);// Выбираем тип тумана

	glFogfv(GL_FOG_COLOR, fogColor);        // Устанавливаем цвет тумана

	glFogf(GL_FOG_DENSITY, 0.15f);          // Насколько густым будет туман

	glHint(GL_FOG_HINT, GL_DONT_CARE);      // Вспомогательная установка тумана

	glFogf(GL_FOG_START, 35.0f);             // Глубина, с которой начинается туман

	glFogf(GL_FOG_END, 100.0f);               // Глубина, где туман заканчивается.
}

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
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 60);
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
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 60);
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
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 60);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light2_spot_direction);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 5.0);

}

void RenderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
	//init_l(0,0,0);
	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
		0, 1, 12, 4, &ctrlpoints[0][0][0]);
	glEnable(GL_MAP2_VERTEX_3);
	glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
	glEnable(GL_NORMALIZE);
	gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);
	glRotatef(spin, spin, spin, 0.01);
	draw2();
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
	case 'g': init_fog(); break;
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
	LoadTexture();
	init_l(0, 0, 0);
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(Systemthing);
	glutIdleFunc(RenderScene);
	glutKeyboardFunc(Keyboard);
	glutMainLoop();

	return 0;
}

