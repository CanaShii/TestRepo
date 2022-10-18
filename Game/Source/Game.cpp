#include "Framework.h"
#include "Game.h"

Game::Game(fw::FWCore& core) : m_Framework(core)
{
    m_pImGuiManager = new fw::ImGuiManager(&core);

    fw::vec2 Point1;
    Point1.SetPos(0.5f, 0.5f);
    fw::vec2 Point2;
    Point2.SetPos(-1.0f, -0.5f);
    fw::vec2 Point3;
    Point3.SetPos(1.5F, -0.5F);
    VertexFormat Points[3] = {
       { Point1 , 255, 255, 255, 255 },
        { Point2 , 255, 255, 255, 255 },
        { Point3 , 255,255,255,255} 
    };
    
    
    // Load the basic shader.
    
   // m_pSecondShader = new fw::ShaderProgram("Data/Shaders/Basic.vert", "Data/Shaders/Angels.frag");
}

Game::~Game()
{
    //delete m_pBasicShader;

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
   
    

    //m_pImGuiManager->EndFrame();
}
