#pragma once
#include "Math/vec2.h"


	class Mesh;
	class Texture;
	class ShaderProgram;

	class ScoreDisplay
	{
	public:
		ScoreDisplay();
		~ScoreDisplay();

		virtual void Draw();

		void SetScore(int score);

	protected:

		fw::vec2 m_Position = { 9.0f , 9.0f };
		fw::vec2 m_Scale = { 0.5f , 0.5f };
		fw::vec2 m_uvScale = { 256.0f, 128.0f };
		fw::vec2 m_uvOffset = { 256.0f, 128.0f };
		fw::ShaderProgram* m_Shader = nullptr;
		std::map<std::string, fw::Mesh*> m_Meshes;
		std::map<std::string, fw::Texture*> m_Textures;
		float m_Angle = 0.0f;
		int m_Score = 0;

	};

