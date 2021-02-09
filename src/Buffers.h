#pragma once

#include "Shapes.h"

namespace Liminal
{
    namespace Buffers
    {
        void GenBuffers();

        /* binds floats in
         *  x1 y1 z1
         *  x2 y2 z2
         *  x3 y3 z3
         * format*/
        void PushFloats(float *p, int length);
        void PushTri(Tri tri);

        void Update();
    }
}
