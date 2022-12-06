#include "GameObject.h"

GameObject::GameObject(fw::Mesh* mesh, fw::ShaderProgram* shader, fw::Texture* texture, fw::vec2 scale, fw::vec2 pos, float angle) :
	m_Mesh(mesh),
	m_Texture(texture),
	m_Shader(shader),
	m_Scale(scale),
	m_Position(pos),
	m_Angle(angle)
	//m_uvScale(spriteSheet->GetOffset("HeartPiece"))
	//m_uvOffset(spriteSheet->GetScale("LinkWalkLeft1"))
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
	m_uvScale = vec2(16, 16);
	m_uvOffset = vec2(17, 112);

	m_Mesh->drawMesh(m_Shader,m_Texture, m_Scale, m_Angle, m_Position, 1, m_uvScale, m_uvOffset);
}



