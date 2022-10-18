#include "Mesh.h"
#include "Utility//ShaderProgram.h"
#include "../Libraries/imgui/imgui.h"


fw::Mesh::Mesh(std::vector<VertexFormat>& vertex, PrimitiveTypes mode)
{
    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(VertexFormat), &vertex, GL_STATIC_DRAW);

    m_Mode = mode;
    m_Format = vertex;
    //m_NumOfObjects = vertex.size();
}

fw::Mesh::~Mesh()
{
    
}

void fw::Mesh::drawMesh(ShaderProgram* shader,vec2 scale,float angle, vec2 pos)
{
    glUseProgram(shader->GetProgram());

   
    // Program our uniforms.
    GLint u_Scale = glGetUniformLocation(shader->GetProgram(), "u_Scale");
    glUniform2f(u_Scale, scale.X, scale.Y);

    GLint u_Offset = glGetUniformLocation(shader->GetProgram(), "u_Offset");
    glUniform2f(u_Offset, pos.X, pos.Y);

    GLint u_Rotation = glGetUniformLocation(shader->GetProgram(), "u_Rotation");
    glUniform1f(u_Rotation, angle);

    GLint u_Color = glGetUniformLocation(shader->GetProgram(), "u_Color");
    glUniform4f(u_Color, 0.5f, 1.0f, 0.0f, 1.0f);

    GLint u_Resolution = glGetUniformLocation(shader->GetProgram(), "u_Resolution");
    glUniform2f(u_Resolution, ImGui::GetWindowWidth(), ImGui::GetWindowHeight());

    GLint iGlobalTime = glGetUniformLocation(shader->GetProgram(), "iGlobalTime");
    glUniform1f(iGlobalTime, 0.0f);

    GLint iDate = glGetUniformLocation(shader->GetProgram(), "iDate");
    glUniform4f(iDate, 2022.0f, 10.0f, 04.0f, 0.0f);

    GLint iResolution = glGetUniformLocation(shader->GetProgram(), "iResolution");
    glUniform3f(iResolution, ImGui::GetWindowWidth(), ImGui::GetWindowHeight(), 1.0f);

    // Draw our mesh.
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

    GLint a_Position = glGetAttribLocation(shader->GetProgram(), "a_Position");
    glEnableVertexAttribArray(a_Position);
    glVertexAttribPointer(a_Position, 2, GL_FLOAT, false, 12, 0);

    GLint a_Color = glGetAttribLocation(shader->GetProgram(), "a_Color");
    glEnableVertexAttribArray(a_Color);
    glVertexAttribPointer(a_Color, 4, GL_UNSIGNED_BYTE, true, 12, (void*)8);


    if (m_Mode == PrimitiveTypes::GLLINES)
    {
        glDrawArrays(GL_LINE_LOOP, 0, m_Format.size());
    }
    else if (m_Mode == PrimitiveTypes::GLPOINTS)
    {
        glDrawArrays(GL_POINTS, 0, m_Format.size());
    }
    else if (m_Mode == PrimitiveTypes::GLTRIANGLE)
    {
        glDrawArrays(GL_TRIANGLES, 0, m_Format.size());
    }
    
}

