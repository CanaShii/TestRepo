#include "GameObject.h"

GameObject::GameObject(fw::Mesh* mesh, fw::ShaderProgram* shader, fw::Texture* texture, fw::vec2 scale, fw::vec2 pos, float angle) :
	m_Mesh(mesh),
	m_Texture(texture),
	m_Shader(shader),
	m_Scale(scale),
	m_Position(pos),
	m_Angle(angle)
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
	m_Mesh->drawMesh(m_Shader,m_Texture, m_Scale, m_Angle, m_Position, 1);
}
