#pragma once

#include "Framework.h"
#include "DataType.h"
#include <Framework.h>

class GameObject
{
public:
    GameObject(fw::Mesh* mesh, fw::ShaderProgram* shader, fw::Texture* texture, fw::vec2 scale, fw::vec2 pos, float angle);
	virtual ~GameObject();
	
	virtual void Update(float deltaTime);
	virtual void Draw();

	
	

protected:
	fw::vec2 m_Position = { 0.0f , 0.0f };
	fw::vec2 m_Scale = { 1.0f , 1.0f };
	fw::Mesh* m_Mesh = nullptr;
	fw::vec2 m_uvScale = { 0.0f, 0.0f };
	fw::vec2 m_uvOffset = { 0.0f, 0.0f };
	fw::ShaderProgram* m_Shader = nullptr;
	fw::Texture* m_Texture = nullptr;
	float m_Angle = 1.0f;
};

