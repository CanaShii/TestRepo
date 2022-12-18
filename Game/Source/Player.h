#pragma once
#include "GameObject.h"


class fw::SpriteSheet;
class fw::Camera;
class VirtualController;

class Player : public GameObject
{

public:
	Player(fw::Mesh* mesh, fw::ShaderProgram* shader, fw::Texture* texture, fw::vec2 scale, fw::vec2 pos, float angle, fw::Camera* camera);
	~Player();
	
	virtual void Update(float deltaTime) override;
	virtual void Player::OnEvent(fw::FWEvent* event);

	vec2 GetPosition(); //<-For Camera

protected:
	
	VirtualController* m_pControllers[4] = { nullptr };
	fw::SpriteSheet* m_SpriteSheet;
	float m_timer = 0;
};

