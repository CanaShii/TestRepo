#include "Framework.h"
#include "Game.h"

struct VertexFormat
{
    float x, y;
    unsigned char r, g, b, a;
};

Game::Game(fw::FWCore& core) : m_Framework(core)
{
    m_pImGuiManager = new fw::ImGuiManager(&core);

    // Initialize our mesh.
    VertexFormat values[6] = {
        { 0.5f, 0.5f, 255, 255, 255, 255 },
        { -1.0f, -0.5f, 255, 255, 255, 255 },
        { 1.5F, -0.5F, 255,255,255,255}
        
    };
    glGenBuffers( 1, &m_VBO );
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );
    glBufferData( GL_ARRAY_BUFFER, 3 * sizeof(VertexFormat), &values[0], GL_STATIC_DRAW );

    // Load the basic shader.
    m_pBasicShader = new fw::ShaderProgram( "Data/Shaders/Basic.vert", "Data/Shaders/City.frag" );
    m_pSecondShader = new fw::ShaderProgram("Data/Shaders/Basic.vert", "Data/Shaders/Angels.frag");
}

Game::~Game()
{
    delete m_pBasicShader;

    //delete m_pSecondShader;

    delete m_pImGuiManager;
}

void Game::StartFrame(float deltaTime)
{
    m_pImGuiManager->StartFrame( deltaTime );

    m_pEventManager->ProcessEvents();

    ImGui::ShowDemoWindow();
}

void Game::Update(float deltaTime)
{
    ImGui::DragFloat( "Position X", &m_PosX, 0.01f );

    m_ElapsedTime += deltaTime;

    glViewport(0, 0, m_Framework.GetWindowWidth(), m_Framework.GetWindowHeight());

    if (ImGui::Button("Reset"))
    {
        m_PosX = 0.0f;
    }
}

void Game::Draw()
{
    glPointSize( 20 );
    glClearColor( 0, 0, 0.2f, 1 );
    glClear( GL_COLOR_BUFFER_BIT );

    // Activate our basic shader.
    glUseProgram( m_pBasicShader->GetProgram() );
    
    // Program our uniforms.
    GLint u_Scale = glGetUniformLocation(m_pBasicShader->GetProgram(), "u_Scale");
    glUniform2f( u_Scale, 0.5f, 0.5f );
    
    GLint u_Offset = glGetUniformLocation(m_pBasicShader->GetProgram(), "u_Offset");
    glUniform1f( u_Offset, m_PosX );

    GLint u_Color = glGetUniformLocation(m_pBasicShader->GetProgram(), "u_Color");
    glUniform4f(u_Color, 0.5f, 1.0f, 0.0f, 1.0f);

    GLint u_Resolution = glGetUniformLocation(m_pBasicShader->GetProgram(), "u_Resolution");
    glUniform2f(u_Resolution, m_Framework.GetWindowWidth(), m_Framework.GetWindowHeight());

    GLint iGlobalTime = glGetUniformLocation(m_pBasicShader->GetProgram(), "iGlobalTime");
    glUniform1f(iGlobalTime,m_ElapsedTime);

    GLint iDate = glGetUniformLocation(m_pBasicShader->GetProgram(), "iDate");
    glUniform4f(iDate,2022.0f, 10.0f,04.0f, m_ElapsedTime);

    GLint iResolution = glGetUniformLocation(m_pBasicShader->GetProgram(), "iResolution");
    glUniform3f(iResolution, m_Framework.GetWindowWidth(), m_Framework.GetWindowHeight(), 1.0f);

    

    // Draw our mesh.
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );

    GLint a_Position = glGetAttribLocation(m_pBasicShader->GetProgram(), "a_Position");
    glEnableVertexAttribArray( a_Position );
    glVertexAttribPointer( a_Position, 3, GL_FLOAT, false, 12, (void*)0 );

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glUniform1f(u_Offset, 1.0f);
    
    glDrawArrays( GL_TRIANGLES, 0, 3 );
    

    m_pImGuiManager->EndFrame();
}
