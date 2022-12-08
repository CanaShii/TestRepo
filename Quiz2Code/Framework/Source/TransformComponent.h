#pragma once
#include "BaseComponent.h"
#include "Mesh/Mesh.h"
#include "../../Game/Source/DataTypes.h"


namespace fw {
    class TransformComponent : public BaseComponent
    {
    public:
        TransformComponent();
        ~TransformComponent();

        vec2 m_Pos = vec2(0, 0);
        float m_Angle = 0;
        vec2 m_Scale = vec2(1, 1);
    };
}
