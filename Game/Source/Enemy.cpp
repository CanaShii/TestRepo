#include "Enemy.h"

Enemy::Enemy(fw::Mesh* mesh, fw::ShaderProgram* shader, fw::Texture* texture, fw::vec2 scale, fw::vec2 pos, float angle, fw::Camera* camera) 
	: GameObject(mesh, shader, texture, scale, pos, angle, camera)
{

}
Enemy::~Enemy()
{

}

void Enemy::Update(float deltaTime)
{

}