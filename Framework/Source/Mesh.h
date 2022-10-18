#pragma once
#include "GameCore.h"
#include "CoreHeaders.h"
#include <Framework.h>
#include "vec2.h"


struct VertexFormat
{
	fw::vec2 Pos;
	unsigned char r, g, b, a;
};

namespace fw {
	
class Mesh
{
public:
	Mesh(VertexFormat vertex[], GLenum mode);
	~Mesh();

	void drawMesh(fw::ShaderProgram* shader, vec2 scale, float angle, vec2 pos);

protected:
	fw::ShaderProgram* m_pBasicShader = nullptr;

	float m_ElapsedTime = 0.0f;

	int m_NumOfObjects = 0;

	GLenum m_Mode;

	GLuint m_VBO = 0;

	//fw::FWCore& m_Framework;
};

}