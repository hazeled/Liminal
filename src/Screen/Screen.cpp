#include "../Screen.h"

#include "../Logging.h"

#include <GLFW/glfw3.h>

GLFWwindow* win;
int w, h;

static Liminal::Log log = Liminal::Log("Screen");
bool winCreated = false;

namespace Liminal
{
    void Screen::Init(int w, int h, const char* title)
    {
        w = w;
        h = h;
        log.Print("Screen created");
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLVERSIONMAJOR);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLVERSIONMINOR);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        win = glfwCreateWindow(w, h, title, NULL, NULL);
        if (!win)
        {
            log.Error("Screen failed to be created");
        }
        glfwSetKeyCallback(win, Screen::KeyCallback);
        glfwMakeContextCurrent(win);
        winCreated = true;
    }

    void Screen::Exit()
    {
        if (winCreated)
        {
            log.Print("Window exited");
            winCreated = false;
            glfwDestroyWindow(win);
        }
    }

    void Screen::Update()
    {
        if (winCreated)
        {
            glfwSwapBuffers(win);
            glClear(GL_COLOR_BUFFER_BIT);

            if (glfwWindowShouldClose(win))
            {
                Screen::Exit();
            }

            glfwPollEvents();
        }
    }

    void Screen::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
    }

    bool Screen::Active()
    {
        return winCreated;
    }
}


