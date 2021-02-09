#include "../SceneManager.h"

#include "../pch.h"
#include "../Shapes.h"
#include "../Components.h"
#include "../Renderer.h"
#include "../Logging.h"

#include <inttypes.h>

inline Liminal::Log log = Liminal::Log("Scene Manager");
std::vector<entt::entity> entityList; // So entity's can just be registered with a uint32_t

namespace Liminal
{
    namespace SceneManager
    {
        void Init()
        {
            // Initialize the scene manager
        }

        void Update()
        {
            // Go through every entity and update

            // First, render every entity with a mesh component with the bool 'render' equal to true
            auto viewMesh = registry.view<Mesh>();
            for (auto entity : viewMesh)
            {
                Renderer::Render(&entity, &registry);
            }

        }

        uint32_t CreateEntity()
        {
            auto entity = registry.create();
            entityList.push_back(entity);
            log.Print("Created entity %" PRIu32, (uint32_t)entityList.size() - 1);
            return (uint32_t)entityList.size() - 1;
        }

        uint32_t CreateModel(Liminal::Tri* tris, int triCount)
        {
            auto entity = registry.create();
            entityList.push_back(entity);
            uint32_t id = (uint32_t)entityList.size() - 1;
            log.Print("Creating model");

            // Add mesh component
            registry.emplace<Mesh>(entity);
            auto& mesh = registry.get<Mesh>(entity);

            mesh.triCount = triCount;
            mesh.tris = (Tri*)malloc(sizeof(Tri) * triCount);
            memcpy(mesh.tris, tris, sizeof(Tri) * triCount);

            return id;
        }
    }

    namespace _SceneManager
    {
        entt::entity* getEntity(uint32_t id)
        {
            return &entityList[id];
        }
    }
}
