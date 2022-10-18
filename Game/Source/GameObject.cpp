#include "GameObject.h"

GameObject::GameObject(fw::Mesh* mesh, fw::vec2 scale, fw::vec2 pos, float angle) : 
	m_Mesh(mesh),
	m_Scale(scale),
	m_Position(pos),
	m_Angle(angle)
{
	m_Shader = new fw::ShaderProgram("Data/Shaders/Basic.vert", "Data/Shaders/Angels.frag");
}

GameObject::~GameObject()
{
	delete m_Shader;
}

void GameObject::Update(float deltaTime)
{
}

void GameObject::Draw()
{
	m_Mesh->drawMesh(m_Shader, m_Scale, m_Angle, m_Position);
}
