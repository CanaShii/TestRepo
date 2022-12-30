#pragma once
#include "Math/vec2.h"


class Mesh;
class Texture;
class ShaderProgram;
class fw::Camera;

enum class TileType
{
	Grass, 
	Sand, 
	Brick, 
	NumTypes, 
};

struct TileProperties
{
	fw::Mesh* m_pSprite;
	fw::Texture* m_pTexture;
	bool m_Walkable;
};

class TileMap
{
public:
	TileMap(fw::Camera* camera);
	~TileMap();

	virtual void Draw();

protected:
	std::map < std::string, int> m_TileTypes;
	std::map < std::string, TileProperties*> m_TileProperties;
	fw::ShaderProgram* m_Shader = nullptr;
	fw::vec2 m_Position = { -3.0f , 7.0f };
	fw::vec2 m_Scale = { 1.0f , 1.0f };
	fw::vec2 m_uvScale = { 256.0f, 128.0f };
	fw::vec2 m_uvOffset = { 256.0f, 128.0f };
	fw::vec2 m_jsonSize = { 256.0f , 128.0f }; 
	float m_Angle = 0.0f;

	fw::Camera* m_Camera;
};

