#include <Windows.h>
#include <glut.h>
#include <ctime>
#include <iostream>
using namespace std;

void draw(void)
{

    glShadeModel(GL_SMOOTH);
    glColor3ub(20, 200, 20);

    glBegin(GL_TRIANGLE_STRIP);

    
    glVertex3f(-3.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 3.0f);
    glVertex3f(0.0f, -3.0f, 0.0f); 

    glColor3ub(200, 200, 200);
    glVertex3f(3.0f, 0.0f, 0.0f); 
    glVertex3f(0.0f, 0.0f, 3.0f);
    glVertex3f(0.0f, -3.0f, 0.0f);  

    glColor3ub(20, 200, 200);
    glVertex3f(3.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 3.0f);
    glVertex3f(0.0f, 3.0f, 0.0f);

    glColor3ub(200, 20, 20);
    glVertex3f(-3.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 3.0f);
    glVertex3f(0.0f, 3.0f, 0.0f);

    glEnd();


}
GLfloat spin = 0.0;
GLfloat speed = 0.05;
void RenderScene(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(13.0, 13.0, 14.0,  1.0, 1.0, 4.0, 1.0, 1.0, 1.0);
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
    glutCreateWindow("lab2");

    glutDisplayFunc(RenderScene);
    glutReshapeFunc(Systemthing);
    glutIdleFunc(RenderScene);

    glutMainLoop();

    return 0;
}

