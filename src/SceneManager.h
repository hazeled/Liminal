#pragma once

#include "pch.h"
#include "Shapes.h"

namespace Liminal
{
    namespace _SceneManager
    {
        // Internal functions
        entt::entity* getEntity(uint32_t id);
    }


    namespace SceneManager
    {
        inline static entt::registry registry;
        void Init();
        void Update();

        uint32_t CreateEntity();
        uint32_t CreateModel(Liminal::Tri* tris, int triCount);

        // Template functions must be defined in .h file
        template <class component>
        component* GetComponent(uint32_t id)
        {
            auto entity =_SceneManager::getEntity(entity);
            return &registry.get<component>(entity);
        }
        template <class component>
        component* SetComponent(uint32_t id)
        {
            auto entity =_SceneManager::getEntity(entity);
            registry.emplace<component>(entity);
            return &registry.get<component>(entity);
        }
    }
}
