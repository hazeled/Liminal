#pragma once

#include "Shapes.h"
#include "Shader.h"

namespace Liminal
{
    struct Transform
    {
        float x, y, z;
    };

    struct Mesh
    {
        int triCount;
        Liminal::Tri* tris;
        bool render = true;
    };

    struct Material
    {
        Liminal::Program* program;
    };
}
