#include "../Buffers.h"

#include "../Shapes.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

unsigned int vbo;
unsigned int vao;

namespace Liminal
{
    namespace Buffers
    {
        void GenBuffers()
        {
            glGenBuffers(1, &vbo);
            glBindBuffer(GL_ARRAY_BUFFER, vbo);
        }

        void PushFloats(float *p, int length)
        {
            glBufferData(GL_ARRAY_BUFFER, length * sizeof(float), p, GL_STATIC_DRAW);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
        }

        void PushTri(Tri tri)
        {
            glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), tri.p, GL_STATIC_DRAW);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
        }

        void Update()
        {
            glBindVertexArray(vao);
        }
    }
}
