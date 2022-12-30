#include "Framework.h"
#include "TileMap.h"
#include <fstream>

TileMap::TileMap(fw::Camera* camera) :
	m_Camera(camera)
{
	std::vector<fw::VertexFormat> values = {
		{ {-1.1f, -1.15f }, 255, 255, 255, 255, { 0.0f, 0.0f} },
		{ { 1.1f, -1.15f }, 255, 255, 255, 255, { 1.0f, 0.0f} },
		{ { 1.1f,  1.15f }, 255, 255, 255, 255, { 1.0f, 1.0f} },
		{ {-1.1f,  1.15f }, 255, 255, 255, 255, { 0.0f, 1.0f} },
	};

	m_Shader = new fw::ShaderProgram("Data/Shaders/Texture.vert", "Data/Shaders/Texture.frag");

	m_TileTypes["Grass"] = static_cast<int>(TileType::Grass);
	m_TileProperties["Grass"] = new TileProperties[static_cast<int>(TileType::NumTypes)];
	m_TileProperties["Grass"]->m_pSprite = new fw::Mesh(values, fw::PrimitiveTypes::GLTRIANGLE_FAN);
	m_TileProperties["Grass"]->m_pTexture = new fw::Texture("Data/Textures/Grass.png");
	m_TileProperties["Grass"]->m_Walkable = true;

	m_TileTypes["Sand"] = static_cast<int>(TileType::Sand);
	m_TileProperties["Sand"] = new TileProperties[static_cast<int>(TileType::NumTypes)];
	m_TileProperties["Sand"]->m_pSprite = new fw::Mesh(values, fw::PrimitiveTypes::GLTRIANGLE_FAN);
	m_TileProperties["Sand"]->m_pTexture = new fw::Texture("Data/Textures/Sand.png");
	m_TileProperties["Sand"]->m_Walkable = true;

	m_TileTypes["Brick"] = static_cast<int>(TileType::Brick);
	m_TileProperties["Brick"] = new TileProperties[static_cast<int>(TileType::NumTypes)];
	m_TileProperties["Brick"]->m_pSprite = new fw::Mesh(values, fw::PrimitiveTypes::GLTRIANGLE_FAN);
	m_TileProperties["Brick"]->m_pTexture = new fw::Texture("Data/Textures/Brick.png");
	m_TileProperties["Brick"]->m_Walkable = true;
}

TileMap::~TileMap()
{
	for (auto it : m_TileProperties)
	{
		delete it.second;
	}
}

void TileMap::Draw()
{
	std::vector<unsigned char> m_Layout =
	{
		0, 0, 0 ,0 ,0 ,0 ,0,
		0, 0, 0 ,0 ,0 ,0 ,0,
		0, 0, 2 ,1 ,2 ,0 ,0,
		0, 0, 1 ,2 ,1 ,0 ,0,
		0, 0, 2 ,1 ,2 ,0 ,0,
		0, 0, 0 ,0 ,0 ,0 ,0,
		0, 0 ,0 ,0 ,0, 0, 0,
	};
	int TilesDrawn = 0;
	int RowsDrawn = 0;
	fw::vec2 PosFix = fw::vec2(0.0f, 0.0f);
	for (int i = 0; i < m_Layout.size(); i++)
	{
		if (TilesDrawn < 49)
		{
			if (TilesDrawn == 7)
			{
				PosFix = fw::vec2(0.0f, -2.0f);
			}
			if (TilesDrawn == 14)
			{
				PosFix = fw::vec2(0.0f, -4.0f);
			}
			if (TilesDrawn == 21)
			{
				PosFix = fw::vec2(0.0f, -6.0f);
			}
			if (TilesDrawn == 28)
			{
				PosFix = fw::vec2(0.0f, -8.0f);
			}
			if (TilesDrawn == 35)
			{
				PosFix = fw::vec2(0.0f, -10.0f);
			}
			if (TilesDrawn == 42)
			{
				PosFix = fw::vec2(0.0f, -12.0f);
			}
			if (m_Layout[i] == m_TileTypes["Grass"])
			{
				PosFix += fw::vec2(1.0f, 0.0f);
				m_TileProperties["Grass"]->m_pSprite->drawMesh(m_Shader, m_TileProperties["Grass"]->m_pTexture, m_Scale, m_Angle, m_Position + PosFix, 1, m_uvScale, m_uvOffset, m_Camera, m_jsonSize);
				TilesDrawn++;
			}
			else if (m_Layout[i] == m_TileTypes["Sand"])
			{
				PosFix += fw::vec2(1.0f, 0.0f);
				m_TileProperties["Sand"]->m_pSprite->drawMesh(m_Shader, m_TileProperties["Sand"]->m_pTexture, m_Scale, m_Angle, m_Position + PosFix, 1, m_uvScale, m_uvOffset, m_Camera, m_jsonSize);
				TilesDrawn++;
			}
			else if (m_Layout[i] == m_TileTypes["Brick"])
			{
				PosFix += fw::vec2(1.0f, 0.0f);
				m_TileProperties["Brick"]->m_pSprite->drawMesh(m_Shader, m_TileProperties["Brick"]->m_pTexture, m_Scale, m_Angle, m_Position + PosFix, 1, m_uvScale, m_uvOffset, m_Camera, m_jsonSize);
				TilesDrawn++;
			}
		}
	}
}
