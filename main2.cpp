#include <GLFW/glfw3.h>

void display()
{
    //limpa o buffer de pixels 
    //glClear(GL_COLOR_BUFFER_BIT);
    //desenha o quadrado
    glBegin(GL_LINE_LOOP);
    glVertex2f(100, 150);
    glVertex2f(100, 100);
    glVertex2f(150, 100);
    glVertex2f(150, 150);
    glEnd();
    //inicia o processo de desenho através dos dados bufferizados
    glFlush();
}
void translacao() {
    display();
    glTranslatef(-50.0f,75.0f,0.0);
    glRotatef(30,0, 0, 1);
    display();
    
}

static void teclado(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(void) {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
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

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-320, 320, -240, 240, 0, 1);

        translacao();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        glfwSetKeyCallback(window, teclado);

    }

    glfwTerminate();
    return 0;
}
