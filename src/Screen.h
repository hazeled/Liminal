#pragma once

struct GLFWwindow;

namespace Liminal
{
    namespace Screen
    {
        void Init(int w, int h, const char* title);
        void Exit();
        void Update();
        static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
        bool Active();
    };
}
