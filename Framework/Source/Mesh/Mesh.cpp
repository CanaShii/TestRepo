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

void fw::Mesh::drawMesh(ShaderProgram* shader, fw::Texture* texture, vec2 scale, float angle, vec2 pos, float aRatio)
{
    glUseProgram(shader->GetProgram());

   
    // Program our uniforms.
    GLint u_Scale = glGetUniformLocation(shader->GetProgram(), "u_Scale");
    glUniform2f(u_Scale, scale.X, scale.Y);

    GLint u_Offset = glGetUniformLocation(shader->GetProgram(), "u_Offset");
    glUniform2f(u_Offset, pos.X, pos.Y);

    GLint u_Angle = glGetUniformLocation(shader->GetProgram(), "u_Angle");
    glUniform1f(u_Angle, angle);

    GLint u_Color = glGetUniformLocation(shader->GetProgram(), "u_Color");
    glUniform4f(u_Color, 255, 255, 255, 255);

    GLint u_Resolution = glGetUniformLocation(shader->GetProgram(), "u_Resolution");
    glUniform2f(u_Resolution, ImGui::GetWindowWidth(), ImGui::GetWindowHeight());

    GLint u_AspectRatio = glGetUniformLocation(shader->GetProgram(), "u_AspectRatio");
    glUniform1f(u_AspectRatio, aRatio);

    //GLint iGlobalTime = glGetUniformLocation(shader->GetProgram(), "iGlobalTime");
    //glUniform1f(iGlobalTime, 0.0f);

    //GLint iDate = glGetUniformLocation(shader->GetProgram(), "iDate");
    //glUniform4f(iDate, 2022.0f, 10.0f, 04.0f, 0.0f);

    //GLint iResolution = glGetUniformLocation(shader->GetProgram(), "iResolution");
    //glUniform3f(iResolution, ImGui::GetWindowWidth(), ImGui::GetWindowHeight(), 1.0f);

    GLint u_uvScale = glGetUniformLocation(shader->GetProgram(), "u_uvScale");
    GLint u_uvOffset = glGetUniformLocation(shader->GetProgram(), "u_uvOffset");

    glUniform2f(u_uvScale, 16/256.0f, 16/128.0f);
    glUniform2f(u_uvOffset, 51/256.0f, 61/128.0f);

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
    }
    else if (m_Mode == PrimitiveTypes::GLTRIANGLE)
    {
        glDrawArrays(GL_TRIANGLES, 0, m_Format.size());
    }
        glDrawArrays(GL_POINTS, 0, m_Format.size());
    
}

