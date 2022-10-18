#pragma once
#include "Framework.h"


class GameObject
{
public:
	GameObject(fw::Mesh* mesh, fw::vec2 scale, fw::vec2 pos, float angle);
	~GameObject();

	void Update(float deltaTime);
	void Draw();

protected:
	fw::vec2 m_Position = { 0.0f , 0.0f };
	fw::vec2 m_Scale = { 1.0f , 1.0f };
	fw::Mesh* m_Mesh = nullptr;
	fw::ShaderProgram* m_Shader = nullptr;
	float m_Angle = 1.0f;
};

