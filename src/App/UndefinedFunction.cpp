#include "../App.h"

#include <cstdio>
#include <stdlib.h>

// Virtual functions need to be defined in order to build the DLL
// This is the function they'll call if the user has not defined them
void UndefFunction(const char* name)
{
    printf("%s undefined, exiting...", name);
    exit(-1);
}

namespace Liminal
{
    void App::Update()
    {
        UndefFunction("Update");
    }
}
