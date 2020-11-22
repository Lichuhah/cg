#include <Windows.h>
#include <glut.h>
#include <ctime>
#include <iostream>
#include <cassert>
using namespace std;

// mainCRTStartup

// ===================================================
//                  Window configuration
int k = 65;
GLint Window_width = 16 * k, Window_height = 9 * k;
int   Window_pos_x = 200, Window_pos_y = 170;
// ---------------------------------------------------
//                  else   configuration
const char* name_app = "lab3 app ";
int steps = 0;
int light_mode = 0;
int figure_mode = 0;
GLfloat spin = 0.0;
GLfloat speed = 0.05;
GLdouble up_val_camera = 1.0;
GLdouble up_val_speed = 0.05;
GLfloat MAX_SPEED = 10.0;

// ---------------------------------------------------
//                  camera configuration
GLdouble default_eyex = -5.0, default_eyey = -5.0, default_eyez = 3.0;
GLdouble default_centerx = 1.0, default_centery = 1.0, default_centerz = 0.0;
GLdouble default_upx = 1.0, default_upy = 1.0, default_upz = 1.0;

GLdouble eyex = default_eyex, eyey = default_eyey, eyez = default_eyez;
GLdouble centerx = default_centerx, centery = default_centery, centerz = default_centerz;
GLdouble upx = default_upx, upy = default_upy, upz = default_upz;

#define reset_camera_eye    eyex    = default_eyex,         eyey    = default_eyey,        eyez    = default_eyez;  
#define reset_camera_center centerx = default_centerx,      centery = default_centery,     centerz = default_centerz;
#define reset_camera_up     upx     = default_upx,          upy     = default_upy,         upz     = default_upz;     
// ---------------------------------------------------
//              color config
class rgb_colors {
private:
    GLubyte r = 0;
    GLubyte g = 0;
    GLubyte b = 0;
public:

    void set_rgb(GLubyte new_r, GLubyte new_g, GLubyte new_b)
    {
        r = new_r;
        g = new_g;
        b = new_b;
    }
    void set_random_rgb(const char* symbol = "ub")
    {
        if (symbol == "ub")
        {
            r = rand_color_ub();
            g = rand_color_ub();
            b = rand_color_ub();
        }
        else
        {
            r = rand_color_f();
            g = rand_color_f();
            b = rand_color_f();
        }
    }
    void update_color(const char* param)
    {
        if (param == "rand")
        {
            set_random_rgb();
            glColor3ub(r, g, b);
        }
        else if (param == "old")
        {
            glColor3ub(r, g, b);
        }
    }

    GLubyte rand_color_ub(void)
    {
        GLubyte MIN_VAL = 0;
        GLubyte MAX_VAL = 255;

        return MIN_VAL + rand() % MAX_VAL;
    }
    GLclampf rand_color_f(void)
    {
        float MIN_VAL = 0.0;
        int MAX_VAL = 1;

        return (MIN_VAL + rand() % 255) / 255;
    }
};

// ---------------------------------------------------
rgb_colors color_top, color1, color2, color3, color4;

// ===================================================

void light(int mode)
{
    GLfloat mat_specular[] = { 1.0, 0.0, 0.0, 1.0 };  // зеркальный цвет материала
    GLfloat mat_diffuse[] = { 0.0, 0.0, 0.8, 0.1 };   // диффузный цвет материала
    GLfloat mat_emission[] = { 0.0, 1.0, 0.0, 1.0 };  // исходящий цвет материала    EMISSION    
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 0.5 }; // фоновый цвет материала
    GLfloat white_light[] = { 1.0, 1.0, 1.0, 0.5 };   // белый цвет
    GLfloat blak_light[] = { 0.0, 0.0, 0.0, 0.0 };    // черный цвет

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);
    glColor3f(0.0, 0.0, 0.0);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);   // цвет отраженного света
    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);    // отраженный свет
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);     // рассеянный свет

    switch (mode)
    {
    case 0: // зеркальное 1 
        mat_shininess[0] = { 50.0 };
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);      // положение источника
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);    // степень отраженного света
        break;
    case 1: // зеркальное 2  
        mat_shininess[0] = { 6.0 };
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);      // положение источника
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);    // степень отраженного света
        break;
    case 2: // диффузорное  
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);      // положение источника
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
        break;
        //case 3: // различный цвет внешних поверхностей
            // break;
            // находится в draw_object5
    default:
        light_mode = 0;
        break;
    }

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void speed_control()
{

    if (abs(spin) > 360.0) { spin = spin - 360.0; }

    //if (abs(speed) > MAX_SPEED) { steps = abs(speed); reset_speed(steps); }
    //if (abs(speed) > MAX_SPEED) { speed = speed - MAX_SPEED; }

    spin += speed;
}

void upd_color(rgb_colors& color, int count)
{
    if (count % 45 == 0) { color.update_color("rand"); }
    else { color.update_color("old"); }
}
void set_color(rgb_colors& color, GLubyte new_r, GLubyte new_g, GLubyte new_b)
{
    color.set_rgb(new_r, new_g, new_b);
    glColor3ub(new_r, new_g, new_b);
}

void draw_object(void)
{
    // фигура с градиентом и случайным распределением цвета

    int count = round(spin);

    glShadeModel(GL_SMOOTH);

    glBegin(GL_TRIANGLE_STRIP);

    upd_color(color4, count);
    glVertex3f(-2.0f, 0.0f, 0.0f);

    upd_color(color_top, count);
    glVertex3f(0.0f, 0.0f, 6.0f);

    upd_color(color3, count);
    glVertex3f(0.0f, -2.0f, 0.0f);

    upd_color(color1, count);
    glVertex3f(2.0f, 0.0f, 0.0f);

    upd_color(color_top, count);
    glVertex3f(0.0f, 0.0f, 6.0f);

    upd_color(color3, count);
    glVertex3f(0.0f, -2.0f, 0.0f);

    upd_color(color1, count);
    glVertex3f(2.0f, 0.0f, 0.0f);

    upd_color(color_top, count);
    glVertex3f(0.0f, 0.0f, 6.0f);

    upd_color(color2, count);
    glVertex3f(0.0f, 2.0f, 0.0f);

    upd_color(color4, count);
    glVertex3f(-2.0f, 0.0f, 0.0f);

    upd_color(color_top, count);
    glVertex3f(0.0f, 0.0f, 6.0f);

    upd_color(color2, count);
    glVertex3f(0.0f, 2.0f, 0.0f);

    glEnd();



    glBegin(GL_QUAD_STRIP);

    upd_color(color1, count);
    glVertex3f(2.0f, 0.0f, 0.0f);

    upd_color(color2, count);
    glVertex3f(0.0f, 2.0f, 0.0f);

    upd_color(color3, count);
    glVertex3f(0.0f, -2.0f, 0.0f);

    upd_color(color4, count);
    glVertex3f(-2.0f, 0.0f, 0.0f);

    glEnd();

    glFinish();

}
void draw_object2(void)
{
    // фигура без градиента

    int count = spin;

    glShadeModel(GL_FLAT);

    glBegin(GL_TRIANGLE_STRIP);

    glColor3ub(102, 176, 50);
    glVertex3f(2.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 6.0f);
    glVertex3f(0.0f, -2.0f, 0.0f);

    glColor3ub(186, 85, 211);
    glVertex3f(-2.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 6.0f);
    glVertex3f(0.0f, -2.0f, 0.0f);

    glColor3ub(15, 192, 252);
    glVertex3f(2.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 6.0f);
    glVertex3f(0.0f, 2.0f, 0.0f);

    glColor3ub(244, 0, 161);
    glVertex3f(-2.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 6.0f);
    glVertex3f(0.0f, 2.0f, 0.0f);

    glEnd();

    glColor3ub(217, 96, 59);
    glBegin(GL_QUAD_STRIP);

    glVertex3f(2.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 2.0f, 0.0f);
    glVertex3f(0.0f, -2.0f, 0.0f);
    glVertex3f(-2.0f, 0.0f, 0.0f);

    glEnd();

    glFinish();
}
void draw_object3(void)
{
    // Фигура с градиентом

    int count = spin;

    //glShadeModel(GL_SMOOTH);

    glBegin(GL_TRIANGLE_STRIP);

    set_color(color4, 0, 255, 0);
    glVertex3f(-2.0f, 0.0f, 0.0f);

    set_color(color_top, 255, 255, 0);
    glVertex3f(0.0f, 0.0f, 6.0f);

    set_color(color3, 0, 255, 255);
    glVertex3f(0.0f, -2.0f, 0.0f);

    set_color(color1, 255, 0, 0);
    glVertex3f(2.0f, 0.0f, 0.0f);

    set_color(color_top, 255, 255, 0);
    glVertex3f(0.0f, 0.0f, 6.0f);

    set_color(color3, 0, 255, 255);
    glVertex3f(0.0f, -2.0f, 0.0f);

    set_color(color1, 255, 0, 0);
    glVertex3f(2.0f, 0.0f, 0.0f);

    set_color(color_top, 255, 255, 0);
    glVertex3f(0.0f, 0.0f, 6.0f);

    set_color(color2, 0, 0, 255);
    glVertex3f(0.0f, 2.0f, 0.0f);

    set_color(color4, 0, 255, 0);
    glVertex3f(-2.0f, 0.0f, 0.0f);

    set_color(color_top, 255, 255, 0);
    glVertex3f(0.0f, 0.0f, 6.0f);

    set_color(color2, 0, 0, 255);
    glVertex3f(0.0f, 2.0f, 0.0f);

    glEnd();



    glBegin(GL_QUAD_STRIP);

    set_color(color1, 255, 0, 0);
    glVertex3f(2.0f, 0.0f, 0.0f);

    set_color(color2, 0, 0, 255);
    glVertex3f(0.0f, 2.0f, 0.0f);

    set_color(color3, 0, 255, 255);
    glVertex3f(0.0f, -2.0f, 0.0f);

    set_color(color4, 0, 255, 0);
    glVertex3f(-2.0f, 0.0f, 0.0f);

    glEnd();

    glFinish();
}
void draw_object4(void)
{
    glBegin(GL_TRIANGLE_STRIP);
    float MatDiffuse1[] = { 0.0f, 0.0f, 1.0f, 1.0f };
    float MatSpecular1[] = { 0.1f, 0.1f, 0.0f, 0.1f };
    float MatShininess1 = 0;
    glColor3ub(200, 200, 200);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDiffuse1);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular1);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatShininess1);
    glVertex3f(-3.0f, 0.0f, 0.0f);
    glVertex3f(-1.5f, -1.5f, 3.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);

    glColor3ub(200, 0, 0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDiffuse1);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular1);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatShininess1);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-1.5f, -1.5f, 3.0f);
    glVertex3f(0.0f, -3.0f, 0.0f);

    glColor3ub(2, 2, 200);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDiffuse1);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular1);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatShininess1);
    glVertex3f(0.0f, -3.0f, 0.0f);
    glVertex3f(-1.5f, -1.5f, 3.0f);
    glVertex3f(-3.0f, -3.0f, 0.0f);

    glColor3ub(2, 200, 2);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDiffuse1);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular1);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatShininess1);
    glVertex3f(-3.0f, -3.0f, 0.0f);
    glVertex3f(-1.5f, -1.5f, 3.0f);
    glVertex3f(-3.0f, 0.0f, 0.0f);

    glEnd();
}
void draw_object5(void)
{
    glShadeModel(GL_FLAT);

    glEnable(GL_COLOR_MATERIAL);

    glBegin(GL_TRIANGLE_STRIP);

    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glColor3ub(102, 176, 50);
    glVertex3f(2.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 6.0f);
    glVertex3f(0.0f, -2.0f, 0.0f);

    glColorMaterial(GL_FRONT, GL_SPECULAR);
    glColor3ub(186, 85, 211);
    glVertex3f(-2.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 6.0f);
    glVertex3f(0.0f, -2.0f, 0.0f);

    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glColor3ub(15, 192, 252);
    glVertex3f(2.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 6.0f);
    glVertex3f(0.0f, 2.0f, 0.0f);

    glColorMaterial(GL_FRONT, GL_SPECULAR);
    glColor3ub(244, 0, 161);
    glVertex3f(-2.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 6.0f);
    glVertex3f(0.0f, 2.0f, 0.0f);

    glEnd();

    glBegin(GL_QUAD_STRIP);

    glColor3ub(217, 96, 59);
    glVertex3f(2.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 2.0f, 0.0f);
    glVertex3f(0.0f, -2.0f, 0.0f);
    glVertex3f(-2.0f, 0.0f, 0.0f);

    glEnd();


    glDisable(GL_COLOR_MATERIAL);
}
void draw_ortex(void)
{
    // единичные вектора

    // x - red
    glColor3ub(255, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(10.0f, 0.0f, 0.0f);
    glEnd();

    // y - blue
    glColor3ub(0, 0, 255);
    glBegin(GL_LINE_LOOP);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 10.0f, 0.0f);
    glEnd();

    // z - green
    glColor3ub(0, 255, 0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 10.0f);
    glEnd();
}

void RenderScene(void) {

    // очистить буфер цвета и глубины.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST); //фигуры не просвечиваются
    // обнулить трансформацию
    glLoadIdentity();

    // установить камеру
    gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);

    //поворот на заданную величину
    glRotatef(spin, 0.0, 0.0, 0.01);

    light(light_mode);


    switch (figure_mode)
    {
    case 0:
        draw_object5(); break;
    case 1:
        glutSolidSphere(2.0, 40, 16); break;
    case 2:
        glutSolidIcosahedron(); break;
    default:
        figure_mode = 0; break;
    }

    draw_ortex();

    speed_control();

    glutSwapBuffers();
}
void ChangeSize(int w, int h) {

    float ratio = w * 1.0 / h;
    // используем матрицу проекции
    glMatrixMode(GL_PROJECTION);
    // обнуляем матрицу
    glLoadIdentity();
    // установить параметры вьюпорта
    glViewport(0, 0, w, h);
    // установить корректную перспективу
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);
    // вернуться к матрице проекции
    glMatrixMode(GL_MODELVIEW);
}

void Keyboard(unsigned char key, int x, int y)
{

    switch (key)
    {
    case '\33': // esc
        exit(0); break;
    case '\40': // space
        exit(0); break;
    case '1': // up speed spin
        speed += up_val_speed; break;
    case '2': // down speed spin
        speed -= up_val_speed; break;

        // =============================
    // camera control
    case 'Q':
        eyex += up_val_camera; break;
    case 'W':
        eyey += up_val_camera; break;
    case 'E':
        eyez += up_val_camera; break;
    case 'A':
        centerx += up_val_camera; break;
    case 'S':
        centery += up_val_camera; break;
    case 'D':
        centerz += up_val_camera; break;
    case 'Z':
        upx += up_val_camera; break;
    case 'X':
        upy += up_val_camera; break;
    case 'C':
        upz += up_val_camera; break;
    case 'q':
        eyex -= up_val_camera; break;
    case 'w':
        eyey -= up_val_camera; break;
    case 'e':
        eyez -= up_val_camera; break;
    case 'a':
        centerx -= up_val_camera; break;
    case 's':
        centery -= up_val_camera; break;
    case 'd':
        centerz -= up_val_camera; break;
    case 'z':
        upx -= up_val_camera; break;
    case 'x':
        upy -= up_val_camera; break;
    case 'c':
        upz -= up_val_camera; break;
    case 'R':
        reset_camera_eye
            reset_camera_center
            reset_camera_up
            break;
    case 'r':
        reset_camera_eye
            reset_camera_center
            reset_camera_up
            break;
    case 'T':
        speed = 0; break;
    case 't':
        speed = 0; break;
    case 'F':
        light_mode += 1;  break;
    case 'f':
        light_mode += 1;  break;
    case 'P':
        figure_mode += 1; break;
    case 'p':
        figure_mode -= 1; break;
        //cout << eyex << "|" << eyey << "|" << eyez << "|" << centerx << "|" << centery << "|" << centerz << "|" << upx << "|" << upy << "|" << upz << "|" << endl;  break;
        // =============================
    }
}
void Mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN) glutIdleFunc(RenderScene); break;
    case GLUT_RIGHT_BUTTON: if (state == GLUT_DOWN) glutIdleFunc(NULL); break;
    }
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);

    srand(time(NULL));

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(Window_width, Window_height);
    glutInitWindowPosition(Window_pos_x, Window_pos_y);
    glutCreateWindow(name_app);

    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);

    //Keyboard and Mouse
    glutKeyboardFunc(Keyboard);
    glutMouseFunc(Mouse);

    glutIdleFunc(RenderScene);

    glutMainLoop();

    return 0;
}