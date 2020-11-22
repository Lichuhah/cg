#include <GLFW/glfw3.h>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        GLfloat cubeVertexArray[8][3];
        GLfloat cubeColorArray[8][3];
        GLubyte cubeIndexArray[6][4];

        cubeVertexArray[0][0] = 0.0;
        cubeVertexArray[0][1] = 0.0;
        cubeVertexArray[0][2] = 1.0;
        cubeVertexArray[1][0] = 0.0;
        cubeVertexArray[1][1] = 1.0;
        cubeVertexArray[1][2] = 1.0;
        cubeVertexArray[2][0] = 1.0;
        cubeVertexArray[2][1] = 1.0;
        cubeVertexArray[2][2] = 1.0;
        cubeVertexArray[3][0] = 1.0;
        cubeVertexArray[3][1] = 0.0;
        cubeVertexArray[3][2] = 1.0;
        cubeVertexArray[4][0] = 0.0;
        cubeVertexArray[4][1] = 0.0;
        cubeVertexArray[4][2] = 0.0;
        cubeVertexArray[5][0] = 0.0;
        cubeVertexArray[5][1] = 1.0;
        cubeVertexArray[5][2] = 0.0;
        cubeVertexArray[6][0] = 1.0;
        cubeVertexArray[6][1] = 1.0;
        cubeVertexArray[6][2] = 0.0;
        cubeVertexArray[7][0] = 1.0;
        cubeVertexArray[7][1] = 0.0;
        cubeVertexArray[7][2] = 0.0;
        cubeColorArray[0][0] = 0.0;
        cubeColorArray[0][1] = 0.0;
        cubeColorArray[0][2] = 1.0;
        cubeColorArray[1][0] = 0.6;
        cubeColorArray[1][1] = 0.98;
        cubeColorArray[1][2] = 0.6;
        cubeColorArray[2][0] = 1.0;
        cubeColorArray[2][1] = 0.84;
        cubeColorArray[2][2] = 0.8;
        cubeColorArray[3][0] = 0.8;
        cubeColorArray[3][1] = 0.36;
        cubeColorArray[3][2] = 0.36;
        cubeColorArray[4][0] = 1.0;
        cubeColorArray[4][1] = 0.27;
        cubeColorArray[4][2] = 0.0;
        cubeColorArray[5][0] = 0.82;
        cubeColorArray[5][1] = 0.13;
        cubeColorArray[5][2] = 0.56;
        cubeColorArray[6][0] = 0.54;
        cubeColorArray[6][1] = 0.17;
        cubeColorArray[6][2] = 0.89;
        cubeColorArray[7][0] = 0.0;
        cubeColorArray[7][1] = 1.0;
        cubeColorArray[7][2] = 1.0;

        cubeIndexArray[0][0] = 0;
        cubeIndexArray[0][1] = 3;
        cubeIndexArray[0][2] = 2;
        cubeIndexArray[0][3] = 1;
        cubeIndexArray[1][0] = 0;
        cubeIndexArray[1][1] = 1;
        cubeIndexArray[1][2] = 5;
        cubeIndexArray[1][3] = 4;
        cubeIndexArray[2][0] = 7;
        cubeIndexArray[2][1] = 4;
        cubeIndexArray[2][2] = 5;
        cubeIndexArray[2][3] = 6;
        cubeIndexArray[3][0] = 3;
        cubeIndexArray[3][1] = 7;
        cubeIndexArray[3][2] = 6;
        cubeIndexArray[3][3] = 2;
        cubeIndexArray[4][0] = 1;
        cubeIndexArray[4][1] = 2;
        cubeIndexArray[4][2] = 6;
        cubeIndexArray[4][3] = 5;
        cubeIndexArray[5][0] = 0;
        cubeIndexArray[5][1] = 4;
        cubeIndexArray[5][2] = 7;
        cubeIndexArray[5][3] = 3;

        glBegin(GL_TRIANGLES);
        glVertexPointer(3, GL_FLOAT, 0, cubeVertexArray);
        glColorPointer(3, GL_FLOAT, 0, cubeColorArray);
        glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndexArray);
        glEnd();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}