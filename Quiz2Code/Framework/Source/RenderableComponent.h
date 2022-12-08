#pragma once
#include "BaseComponent.h"
#include "Mesh/Mesh.h"


namespace fw {

    class RenderableComponent : public BaseComponent
    {
    public:
        RenderableComponent();
        ~RenderableComponent();

        fw::Mesh* m_pMesh = nullptr;
        fw::ShaderProgram* m_pShader = nullptr;
        fw::Texture* m_pTexture = nullptr;
    };
}
