#pragma once

#include "Core.h"

// Forward declarations
namespace Liminal
{
    class Log;
}

namespace Liminal
{
    class LIMINAL_API App
    {
    public:
        App(int w, int h, const char* title);
        virtual ~App();
        void Run();

        // Functions to be defined by the user
        virtual void Update();

    protected:
        void CreateScreen(int w, int h, const char* title);

    private:
        Liminal::Log* appLog;
    };

    App* CreateApp();
}
