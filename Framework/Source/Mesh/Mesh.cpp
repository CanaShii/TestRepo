#include "CoreHeaders.h"
#include "Mesh.h"
#include "Utility/ShaderProgram.h"
#include "Math/vec2.h"
#include "Mesh/Texture.h"
#include "../../Libraries/imgui/imgui.h"


fw::Mesh::Mesh(std::vector<VertexFormat>& vertex, PrimitiveTypes mode)
{
    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, vertex.size() * sizeof(VertexFormat), &vertex[0], GL_STATIC_DRAW);

    m_Mode = mode;
    m_Format = vertex;
    m_NumOfObjects = (int)vertex.size();
}

fw::Mesh::~Mesh()
{
    glDeleteBuffers(1, &m_VBO);
}

void fw::Mesh::SetupUniform2f(ShaderProgram* shader, const char* name, vec2& value)
{
    GLint location = glGetUniformLocation(shader->GetProgram(), name);
    glUniform2f(location, value.X, value.Y);
    
}

void fw::Mesh::SetupUniform1f(ShaderProgram* shader, const char* name, float& value)
{
    GLint location = glGetUniformLocation(shader->GetProgram(), name);
    glUniform1f(location, value);

}

void fw::Mesh::drawMesh(ShaderProgram* shader, fw::Texture* texture, vec2 scale, float angle, vec2 pos, float aRatio, vec2 uvScale, vec2 uvOffset)
{
    glUseProgram(shader->GetProgram());

   
    // Program our uniforms.

    SetupUniform1f(shader, "u_Angle", angle);
    SetupUniform1f(shader, "u_AspectRatio", aRatio);
    SetupUniform2f(shader, "u_Scale", scale);
    SetupUniform2f(shader, "u_Offset", pos);
    SetupUniform2f(shader, "u_uvScale", vec2(uvScale.X / 256.0f, uvScale.Y / 128.0f)); // / 256.0f / 128.0f
    SetupUniform2f(shader, "u_uvOffset", vec2(uvOffset.X / 256.0f, uvOffset.Y / 128.0f));
    SetupUniform2f(shader, "u_CameraPosition", vec2(0.0f, 0.0f));
    SetupUniform2f(shader, "u_ProjectionScale", vec2(0.1f, 0.1f));

    int textureUnitNumber = 0;
    glActiveTexture(GL_TEXTURE0 + textureUnitNumber);
    glBindTexture(GL_TEXTURE_2D, texture->GetTextureID());
    GLint u_ColorTexture = glGetUniformLocation(shader->GetProgram(), "u_ColorTexture");
    glUniform1i(u_ColorTexture, textureUnitNumber);

    // Draw our mesh.
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

    GLint a_Position = glGetAttribLocation(shader->GetProgram(), "a_Position");
    glEnableVertexAttribArray(a_Position);
    glVertexAttribPointer(a_Position, 2, GL_FLOAT, false, 20, 0);

    GLint a_Color = glGetAttribLocation(shader->GetProgram(), "a_Color");
    glEnableVertexAttribArray(a_Color);
    glVertexAttribPointer(a_Color, 4, GL_UNSIGNED_BYTE, true, 20, (void*)8);

    GLint a_UV = glGetAttribLocation(shader->GetProgram(), "a_UV");
    glEnableVertexAttribArray(a_UV);
    glVertexAttribPointer(a_UV, 2, GL_FLOAT, false, sizeof(VertexFormat), (void*)offsetof(VertexFormat, uv));


    if (m_Mode == PrimitiveTypes::GLLINES)
    {
        glDrawArrays(GL_LINES, 0, m_Format.size());
    }
    else if (m_Mode == PrimitiveTypes::GLPOINTS)
    {
        glDrawArrays(GL_POINTS, 0, m_Format.size());
    }
    else if (m_Mode == PrimitiveTypes::GLTRIANGLE)
    {
        glDrawArrays(GL_TRIANGLES, 0, m_Format.size());
    }
    else if (m_Mode == PrimitiveTypes::GLTRIANGLE_FAN)
    {
        glDrawArrays(GL_TRIANGLE_FAN, 0, m_Format.size());
    }
      
    
}

