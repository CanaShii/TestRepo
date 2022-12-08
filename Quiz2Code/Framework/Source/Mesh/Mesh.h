#pragma once

#include "Math/Vector.h"

namespace fw {

class ShaderProgram;
class Texture;
class BaseComponent;
class TransformComponent;
class RenderableComponent;


struct VertexFormat
{
    vec2 pos;
    unsigned char r, g, b, a;
    vec2 uv;
};

class Mesh
{
public:
    Mesh(std::vector<VertexFormat>& verts, int primType);
    virtual ~Mesh();

    void Draw(RenderableComponent* pRComponent, TransformComponent* pTComponent, float aspectRatio);

protected:
    GLuint m_VBO;
    int m_NumVerts;
    int m_PrimitiveType;
};

}