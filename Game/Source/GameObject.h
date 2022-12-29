#pragma once

#include "Framework.h"
#include "DataType.h"
#include <Framework.h>

class GameObject
{
public:
    GameObject(fw::Mesh* mesh, fw::ShaderProgram* shader, fw::Texture* texture, fw::vec2 scale, fw::vec2 pos, float angle, fw::Camera* camera);
	virtual ~GameObject();
	
	virtual void Update(float deltaTime);
	virtual void Draw();

	
	

protected:
	fw::vec2 m_Position = { 0.0f , 0.0f };
	fw::vec2 m_Scale = { 0.5f , 0.5f };
	fw::Mesh* m_Mesh = nullptr;
	fw::vec2 m_uvScale = { 8.0f, 10.0f };
	fw::vec2 m_uvOffset = { 0.0f, 1.0f };
	fw::vec2 m_jsonSize = { 256.0f , 128.0f };
	fw::ShaderProgram* m_Shader = nullptr;
	fw::Texture* m_Texture = nullptr;
	fw::Camera* m_Camera = nullptr;
	float m_Angle = 1.0f;
};

