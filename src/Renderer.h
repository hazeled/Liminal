#pragma once

#include "pch.h"

namespace Liminal
{
    namespace Renderer
    {
        void Init();
        void Render(entt::entity* entity, entt::registry* registry);
    }
}
