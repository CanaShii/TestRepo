#include "Framework.h"
#include "GameObject.h"

GameObject::GameObject(fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::Texture* pTexture, vec2 pos, float angle, vec2 scale)
    : m_pMesh( pMesh )
    , m_pShader( pShader )
    , m_pTexture( pTexture )
    , m_Pos( pos )
    , m_Angle( angle )
    , m_Scale( scale )
{
}

GameObject::~GameObject()
{
}

void GameObject::Update(float deltaTime)
{
}

void GameObject::Draw()
{
    m_pMesh->Draw( m_pShader, m_pTexture, m_Pos, m_Angle, m_Scale, 1 );
}
