#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	Enemy(fw::Mesh* mesh, fw::ShaderProgram* shader, fw::Texture* texture, fw::vec2 scale, fw::vec2 pos, float angle, fw::Camera* camera);
	~Enemy();

	virtual void Update(float deltaTime) override;

protected:
	
	fw::SpriteSheet* m_SpriteSheet;

};

