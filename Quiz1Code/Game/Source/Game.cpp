#include "Framework.h"
#include "Game.h"
#include "VirtualController.h"

struct VertexFormat
{
    float x, y;
    vec2 uv;
    unsigned char b, a;
};

Game::Game(fw::FWCore& core) : m_Framework(core)
{
    VertexFormat m_Box[5] = {
    { -0.5f, -0.5f, vec2(0,0), 0, 255 },
    { 0.5f, -0.5f, vec2(1,0), 0, 255 },
    { 0.5f, 0.5f, vec2(1,1), 0, 255 },
    { -0.5f, 0.5f, vec2(0,1), 0, 255 },
    { -0.5f, -0.5f, vec2(0,0),0, 255 },
    };

    m_pImGuiManager = new fw::ImGuiManager(&core);

    // Initialize our mesh.
     
    glGenBuffers( 1, &m_VBO );
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );
    glBufferData( GL_ARRAY_BUFFER, 5 * sizeof(VertexFormat), &m_Box[0], GL_STATIC_DRAW );
    
    
    // Load the basic shader.
    m_pBasicShader = new fw::ShaderProgram( "Data/Shaders/Basic.vert", "Data/Shaders/Basic.frag" );

    for( int i=0; i<4; i++ )
    {
        m_pControllers[i] = new VirtualController();
    }
}

Game::~Game()
{
    for( int i=0; i<4; i++ )
    {
        delete m_pControllers[i];
    }

    delete m_pBasicShader;

    delete m_pImGuiManager;
}

void Game::StartFrame(float deltaTime)
{
    m_pImGuiManager->StartFrame( deltaTime );
    ImGui::ShowDemoWindow();

    m_pEventManager->ProcessEvents();
}

void Game::OnEvent(fw::Event* pEvent)
{
    m_pControllers[0]->OnEvent( pEvent );
}

void Game::Update(float deltaTime)
{
    if (ImGui::TreeNode("This is a tree node"))
    {
        ImGui::DragFloat("Position X", &m_Pos.x, 0.01f);

        if (ImGui::Button("Reset"))
        {
            m_Pos.x = 0.0f;
        }

        ImGui::ColorEdit3("Color", &m_Color[0]);
        
        ImGui::TreePop();
    }

    if( m_pControllers[0]->IsHeld(VirtualController::Action::Left) )
    {
        m_Pos.x -= deltaTime;
    }

    if( m_pControllers[0]->IsHeld(VirtualController::Action::Right) )
    {
        m_Pos.x += deltaTime;
    }
}

void Game::Draw()
{
    glPointSize( 20 );
    glLineWidth( 20 );
    glClearColor( 0, 0, 0.2f, 1 );
    glClear( GL_COLOR_BUFFER_BIT );

    // Activate our basic shader.
    glUseProgram( m_pBasicShader->GetProgram() );

    // Program our uniforms.
    GLint u_Scale = glGetUniformLocation(m_pBasicShader->GetProgram(), "u_Scale");
    glUniform2f( u_Scale, 0.5f, 0.5f );
    
    GLint u_Offset = glGetUniformLocation(m_pBasicShader->GetProgram(), "u_Offset");
    glUniform1f( u_Offset, m_Pos.x );

    GLint u_Color = glGetUniformLocation(m_pBasicShader->GetProgram(), "u_Color");
    glUniform4f( u_Color, m_Color[0], m_Color[1], m_Color[2], m_Color[3] );

    // Draw our mesh.
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );

    GLint a_Position = glGetAttribLocation(m_pBasicShader->GetProgram(), "a_Position");
    glEnableVertexAttribArray( a_Position );
    glVertexAttribPointer( a_Position, 2, GL_FLOAT, false, 20, (void*)0 );

    GLint a_Color = glGetAttribLocation(m_pBasicShader->GetProgram(), "a_Color");
    glEnableVertexAttribArray( a_Color );
    glVertexAttribPointer( a_Color, 4, GL_UNSIGNED_BYTE, true, 20, (void*)8 );

    GLint a_Uv = glGetAttribLocation(m_pBasicShader->GetProgram(), "a_Uv");
    glEnableVertexAttribArray(a_Uv);
    glVertexAttribPointer(a_Uv, 2, GL_FLOAT, true, 20, (void*)8);

    glDrawArrays(GL_POLYGON, 0, 5 );

    m_pImGuiManager->EndFrame();
}


//attribute vec2 a_Uv;
//attribute vec2 a_BAColor;


//v_Color = vec4(a_Uv, a_BAColor);