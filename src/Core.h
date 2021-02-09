#pragma once

#include "Core.h"

#ifdef BUILD_DLL
    #define LIMINAL_API __declspec(dllexport)
#else
    #define LIMINAL_API __declspec(dllimport)
#endif // BUILD_DLL
