#include "Framework.h"
#include "GameObject.h"
#include "BaseComponent.h"
#include "RenderableComponent.h"
#include "TransformComponent.h"

GameObject::GameObject(fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::Texture* pTexture, vec2 pos, float angle, vec2 scale)
{
    
    m_RComponent->m_pMesh = pMesh;
    m_RComponent->m_pShader = pShader;
    m_RComponent->m_pTexture = pTexture;

    m_Components.push_back(m_RComponent);

    m_TComponent->m_Scale = scale;
    m_TComponent->m_Pos = pos;
    m_TComponent->m_Angle = angle;

    m_Components.push_back(m_TComponent);
}

GameObject::~GameObject()
{
    for (auto it : m_Components)
    {
        delete it;
    }
}

void GameObject::Update(float deltaTime)
{
}

void GameObject::Draw()
{
    int Rtype;
    int TType;
    for (int i = 0; i < m_Components.size(); i++)
    {
        
        

        fw::RenderableComponent* r1 = dynamic_cast<fw::RenderableComponent*>(m_Components[i]);
        if (r1 == nullptr)
        {
            break;
        }
        else
        {
            fw::TransformComponent* t1 = dynamic_cast<fw::TransformComponent*>(m_Components[i+1]);
            m_pMesh->Draw(r1, t1, 1);
        }

       
    }


    
}
