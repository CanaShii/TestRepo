#include "Framework.h"
#include "Game.h"
#include "GameObject.h"
#include <vector>

Game::Game(fw::FWCore& core) : m_Framework(core)
{
    m_pImGuiManager = new fw::ImGuiManager(&core);

    vec2 P1 = { -1.0f, -1.0f };
    vec2 P2 = { 1.0f, -1.0f };
    vec2 P3 = { 0.0F, 1.0F };
    std::vector<fw::VertexFormat> Player = {
       { P1 , 255, 0, 0, 0 },
       { P2 , 255, 0, 0, 0 },
       { P3 , 255, 0, 0, 0 }, 
    };

    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(fw::VertexFormat), Player.data(), GL_STATIC_DRAW);

    //m_PlayerMesh = new fw::Mesh(Player, fw::PrimitiveTypes::GLTRIANGLE);

    //m_GameObjects.push_back(new GameObject(m_PlayerMesh, fw::vec2{ 1.0f , 1.0f }, fw::vec2{ 1.0f , 1.0f }, 0.0f));
    
    // Load the basic shader.
   // m_pBasicShader = new fw::ShaderProgram("Data/Shaders/Basic.vert", "Data/Shaders/Basic.frag");

    vec2 E1 = { -0.5f, 0.0f };
    vec2 E2 = { 0.0f, 0.0f };
    vec2 E3 = { 0.5F, 0.5F };
    vec2 E4 = { 1.0F, -0.25F };
    vec2 E5 = { -1.0F, 0.5F };

    std::vector<fw::VertexFormat> Enemies = {
       { E1 , 255, 0, 0, 0 },
       { E2 , 255, 0, 0, 0 },
       { E3 , 255, 0, 0, 0 },
       { E4 , 255, 0, 0, 0 },
       { E5 , 255, 0, 0, 0 },
    };

    m_PlayerMesh = new fw::Mesh(Player, fw::PrimitiveTypes::GLTRIANGLE);

    m_GameObjects.push_back(new GameObject(m_PlayerMesh, fw::vec2{ 1.0f , 1.0f }, fw::vec2{ 1.0f , 1.0f }, 0.0f));
    //m_GameObjects.push_back(new GameObject(m_PlayerMesh, fw::vec2{ 1.5f , 1.5f }, fw::vec2{ 1.0f , 1.0f }, 20.0f));


   // m_EnemyMesh = new fw::Mesh(Player, fw::PrimitiveTypes::GLLINES);

    //for (int i = 0; i < 3; i++)
    //{
       // m_GameObjects.push_back(new GameObject(m_EnemyMesh, fw::vec2{ 1.0f , 1.0f }, fw::vec2{ 0.0f , 0.5f + (i + 1) }, 0.0f));
    //}
   
    



}

Game::~Game()
{
    delete m_pBasicShader;

    //delete m_pSecondShader;
    for (auto GameObjects: m_GameObjects)
    {
        delete GameObjects;
    }

    delete m_pImGuiManager;
    delete m_PlayerMesh;
    delete m_EnemyMesh;
}

void Game::StartFrame(float deltaTime)
{
    m_pImGuiManager->StartFrame( deltaTime );

    m_pEventManager->ProcessEvents();

    ImGui::ShowDemoWindow();
}

void Game::Update(float deltaTime)
{
    if (ImGui::TreeNode("This is a tree node"))
    {
        ImGui::DragFloat("Position X", &m_Pos.X, 0.01f);

        if (ImGui::Button("Reset"))
        {
            m_Pos.X = 0.0f;
        }

        ImGui::ColorEdit3("Color", &m_Color[0]);

        ImGui::TreePop();
    }

    ImGui::DragFloat( "Position X", &m_Pos.X, 0.01f );

    m_ElapsedTime += deltaTime;

    glViewport(0, 0, m_Framework.GetWindowWidth(), m_Framework.GetWindowHeight());

    if (ImGui::Button("Reset"))
    {
        m_Pos.X = 0.0f;
    }
}

void Game::Draw()
{
    glPointSize(20);
    glClearColor(0, 0, 0.2f, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    for (auto GameObjects : m_GameObjects)
    {
        GameObjects->Draw();
    }
    

    m_pImGuiManager->EndFrame();
}

void Game::OnEvent(fw::FWEvent* event)
{
}
