#include "Mesh.h"
#include "../Libraries/imgui/imgui.cpp"


fw::Mesh::Mesh(VertexFormat vertex[], GLenum mode)
{
    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(VertexFormat), vertex, GL_STATIC_DRAW);

    m_Mode = mode;
    m_NumOfObjects = sizeof(vertex);
}

fw::Mesh::~Mesh()
{
    delete m_pBasicShader;
}

void fw::Mesh::drawMesh(fw::ShaderProgram* shader,vec2 scale,float angle, vec2 pos)
{
    glPointSize(20);
    glClearColor(0, 0, 0.2f, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    m_pBasicShader = shader;

    glUseProgram(m_pBasicShader->GetProgram());

    for (int i = 0; i < m_NumOfObjects; i++)
    {
    // Program our uniforms.
    GLint u_Scale = glGetUniformLocation(m_pBasicShader->GetProgram(), "u_Scale");
    glUniform2f(u_Scale, scale.X(), scale.Y());

    GLint u_Offset = glGetUniformLocation(m_pBasicShader->GetProgram(), "u_Offset");
    glUniform1f(u_Offset, pos.X());

    GLint u_Color = glGetUniformLocation(m_pBasicShader->GetProgram(), "u_Color");
    glUniform4f(u_Color, 0.5f, 1.0f, 0.0f, 1.0f);

    GLint u_Resolution = glGetUniformLocation(m_pBasicShader->GetProgram(), "u_Resolution");
    glUniform2f(u_Resolution, ImGui::GetWindowWidth(), ImGui::GetWindowHeight());

    GLint iGlobalTime = glGetUniformLocation(m_pBasicShader->GetProgram(), "iGlobalTime");
    glUniform1f(iGlobalTime, m_ElapsedTime);

    GLint iDate = glGetUniformLocation(m_pBasicShader->GetProgram(), "iDate");
    glUniform4f(iDate, 2022.0f, 10.0f, 04.0f, m_ElapsedTime);

    GLint iResolution = glGetUniformLocation(m_pBasicShader->GetProgram(), "iResolution");
    glUniform3f(iResolution, ImGui::GetWindowWidth(), ImGui::GetWindowHeight(), 1.0f);

    // Draw our mesh.
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

    GLint a_Position = glGetAttribLocation(m_pBasicShader->GetProgram(), "a_Position");
    glEnableVertexAttribArray(a_Position);
    glVertexAttribPointer(a_Position, 3, GL_FLOAT, false, 12, (void*)0);

    glDrawArrays(m_Mode, 0, 3);

    glUniform1f(u_Offset, 1.0f);
    }

    //glDrawArrays(m_Mode, 0, 3);

}

