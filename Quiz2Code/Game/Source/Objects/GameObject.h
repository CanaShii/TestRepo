#pragma once

#include "../DataTypes.h"
#include <vector>


class RenderableComponent;
class TransformComponent;
class BaseComponent;

class GameObject
{
public:
    GameObject(fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::Texture* pTexture, vec2 pos, float angle, vec2 scale);
    virtual ~GameObject();

    virtual void Update(float deltaTime);
    virtual void Draw();

protected:


    std::vector<fw::BaseComponent*> m_Components;

    fw::RenderableComponent* m_RComponent;
    fw::TransformComponent* m_TComponent;
};
