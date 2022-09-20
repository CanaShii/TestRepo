#include "Framework.h"
#include "Game.h"

Game::Game() 
{
    // Initialize our mesh.
    float values[6] = { -0.5f, -0.5f, 0.0f, 0.5f, 0.5f, -0.5f };
    glGenBuffers( 1, &m_VBO );
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );
    glBufferData( GL_ARRAY_BUFFER, 2 * 2 * sizeof(float), &values[0], GL_STATIC_DRAW );
    m_pBasicShader = new fw::ShaderProgram("Data/Shaders/Basic.vert", "Data/Shaders/Basic.frag");
    m_UniformXValue = 0.0f;
    m_UniformYValue = 0.0f;
}

Game::~Game()
{
}

void Game::StartFrame()
{
}

void Game::Update(float deltaTime)
{
    if (GetKeyState('D') & 0x8000)
    {
        m_UniformXValue += 0.01F;
    }
    if (GetKeyState('A') & 0x8000)
    {
        m_UniformXValue -= 0.01F;
    }
    if (GetKeyState('W') & 0x8000)
    {
        m_UniformYValue += 0.01F;
    }
    if (GetKeyState('S') & 0x8000)
    {
        m_UniformYValue -= 0.01F;
    }
}

void Game::Draw()
{
    glPointSize( 20 );
    glClearColor( 0, 0, 0.2f, 1 );
    glClear( GL_COLOR_BUFFER_BIT );

    glUseProgram(m_pBasicShader->GetProgram());

    //GLint uOffset = glGetUniformLocation(m_pBasicShader->GetProgram(), "u_Offset");

    glUniform2f(0, m_UniformXValue, m_UniformYValue);
    

    // Draw our mesh.
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );
    glEnableVertexAttribArray( 0 );
    glVertexAttribPointer( 0, 2, GL_FLOAT, false, 8, (void*)0 );
    glDrawArrays( GL_TRIANGLES, 0, 3 );
}
