#include <GLFW/glfw3.h>
#include <cstdio>

/* GLFW needs a handful of c-style static
 * functions. GLFWStaticFunctions.h will
 * handle those functions (e.g error callback */

namespace Liminal
{
    namespace GLFWStaticFunctions
    {
        void ErrorCallback(int error, const char* desc)
        {
            printf("Error %d: %s\n", error, desc);
        }


        void Setup()
        {
            glfwSetErrorCallback(ErrorCallback);
        }
    }
}
