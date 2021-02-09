#include "../App.h"

#include "../Screen.h"
#include "../Buffers.h"
#include "../Logging.h"
#include "../Shader.h"
#include "../SceneManager.h"
#include "../Renderer.h"

#include <cstdio>
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../GLFWStaticFunctions.h" // Has to be included after glew

namespace Liminal
{
    App::App(int w, int h, const char* title)
    {
        appLog = new Liminal::Log("App"); // Initialize log
        appLog->Print("App created");
        if (!glfwInit()) // Initialize GLFW
        {
            appLog->Error("GLFW Failed to initialize!");
            exit(-1);
        }
        Screen::Init(w, h, title); // Initialize the main screen
        if (glewInit() != GLEW_OK) // Initialize glew
        {
            appLog->Error("GLEW Failed to initialize!");
            exit(-1);
        }
        GLFWStaticFunctions::Setup(); // Initialize glfw functions (e.g error callback)
        Buffers::GenBuffers(); // Allocate the opengl buffers
        Renderer::Init();


        // Create test entity
        SceneManager::CreateEntity();

        Tri testTri[] = // Array of triangles
        {
            { // Triangle one
                 0.0f, 0.0f, 0.0f,
                 1.0f, 1.0f, 0.0f,
                -1.0f, 1.0f, 0.0f
            },
            { // Triangle two
                 0.0f,  0.0f, 0.0f,
                -1.0f, -1.0f, 0.0f,
                 1.0f, -1.0f, 0.0f,
            }
        };

        SceneManager::CreateModel(testTri, 2);


    }

    App
    ::~App()
    {
        delete appLog;
    }

    void App::Run()
    {
        appLog->Print("Run called");

        while (true)
        {
            // Update various elements
            // User update
            Update();
            Screen::Update();
            Buffers::Update();
            SceneManager::Update();

            //glDrawArrays(GL_TRIANGLES, 0, 6);

            if (!Screen::Active())
            {
                // The screen has been closed
                break;
            }
        }
    }

    // API functions

    /* Create the main screen used by the application.
     * MUST be called at least once in the client class' constructor
     */
    void App::CreateScreen(int w, int h, const char* title)
    {
        Screen::Init(w, h, title);
    }
}
