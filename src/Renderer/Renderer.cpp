#include "../Renderer.h"

#include "../pch.h"
#include "../ShaderSource/Debug.h"
#include "../Shader.h"
#include "../SceneManager.h"
#include "../Buffers.h"
#include "../Components.h"
#include "../Logging.h"

static Liminal::Log log = Liminal::Log("Renderer");
static Liminal::Program* debugProgram; // Shader used when no shader is available

namespace Liminal
{
    namespace Renderer
    {
        void Init()
        {
            debugProgram = new Program(Shaders::Debug::vert, Shaders::Debug::frag); // Shader used when no shader is available
        }

        void Render(entt::entity* entity, entt::registry* registry)
        {
            auto& mesh = registry->get<Mesh>(*entity);

            if (registry->has<Material>(*entity))
            {
                auto& material = registry->get<Material>(*entity);
                material.program->Use();
            } else {
                debugProgram->Use();
            }

            if (mesh.render)
            {
                float* floats = (float*)malloc(sizeof(float) * 9 * mesh.triCount);

                int n = 0; // Current float in floats we're writing to
                for (int i = 0; i < mesh.triCount; i++)
                {
                    for (int j = 0; j < 9; j++)
                    {
                        floats[n] = mesh.tris[i].p[j];
                        n++;
                    }
                }

                Buffers::PushFloats(floats, mesh.triCount * 9);

                free(floats);

                glDrawArrays(GL_TRIANGLES, 0, mesh.triCount * 3);
            }
        }
    }
}
