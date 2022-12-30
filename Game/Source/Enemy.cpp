#include "Enemy.h"

Enemy::Enemy(fw::Mesh* mesh, fw::ShaderProgram* shader, fw::Texture* texture, fw::vec2 scale, fw::vec2 pos, float angle, fw::Camera* camera) 
	: GameObject(mesh, shader, texture, scale, pos, angle, camera)
{
	m_SpriteSheet = new fw::SpriteSheet;
	m_uvOffset = m_SpriteSheet->GetOffset("OldGuy1");
	m_uvScale = m_SpriteSheet->GetScale("OldGuy1");
	m_jsonSize = m_SpriteSheet->GetJsonSize();

	m_State = static_cast<int>(EnemyState::Idle);
}
Enemy::~Enemy()
{
	delete m_SpriteSheet;
}

void Enemy::Update(float deltaTime)
{
	if (m_State == static_cast<int>(EnemyState::Idle))
	{
		ImGui::Text("Idle State");
	}
	//all pathfinding and states would be here
}