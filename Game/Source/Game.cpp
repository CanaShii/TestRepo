#include "Framework.h"
#include <fstream>
#include "Game.h"
#include "GameObject.h"
#include <vector>

using json = nlohmann::json;

Game::Game(fw::FWCore& core) : m_Framework(core)
{
    m_pImGuiManager = new fw::ImGuiManager(&core);

    std::vector<fw::VertexFormat> values = {
        {{2.0f,2.0f}, 0,0,0,0 ,{1,1}},
        {{-2.0f,-2.0f},0,0,0,0 ,{0,0}},
        {{-2.0f,2.0f }, 0, 0, 0, 0, { 0,1}},

                              
        { {-2.0f,-2.0f }, 0, 0, 0, 0, { 0,0 }},
        { {2.0f, -2.0f }, 0, 0, 0, 0, { 1,0 }},
        {{ 2.0f,  2.0f }, 0, 0, 0, 0, { 1,1 }},


    };


    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    //std::string filename = "Zelda.json";

    //std::ifstream f("Zelda.json");
    //json data = json::parse(f);

    //data[filename];

    //data["Size.x"] = 16.0f;
    //data["Size.y"] = 16.0f;
   
    m_Shaders["Basic"] = new fw::ShaderProgram("Data/Shaders/Basic.vert", "Data/Shaders/Basic.frag");

    m_Shaders["Texture"] = new fw::ShaderProgram("Data/Shaders/Texture.vert", "Data/Shaders/Texture.frag");

    m_Meshes["Triangle"] = new fw::Mesh(values, fw::PrimitiveTypes::GLTRIANGLE);

    m_Textures["Default"] = new fw::Texture("Data/Textures/Zelda.png");

    m_GameObjects.push_back(new GameObject(m_Meshes["Triangle"], m_Shaders["Texture"], m_Textures["Default"], vec2(0.5, 0.5), vec2(0, 0), 0));
    
   
    



};

Game::~Game()
{
    delete m_pBasicShader;

    for (GameObject* pObject : m_GameObjects)
    {
        delete pObject;
    }

    for (auto it : m_Meshes)
    {
        delete it.second;
    }

    for (auto it : m_Shaders)
    {
        delete it.second;
    }

    delete m_pImGuiManager;
    
}

void Game::StartFrame(float deltaTime)
{
    m_pImGuiManager->StartFrame(deltaTime);
    ImGui::ShowDemoWindow();

    m_pEventManager->ProcessEvents();
}

void Game::Update(float deltaTime)
{
    for (int i = 0; i < m_GameObjects.size(); i++)
    {
        m_GameObjects[i]->Update(deltaTime);
    }
}

void Game::Draw()
{
    glPointSize(20);
    glClearColor(0, 0, 0.2f, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < m_GameObjects.size(); i++)
    {
        m_GameObjects[i]->Draw();
    }

    m_pImGuiManager->EndFrame();
}

void Game::OnEvent(fw::FWEvent* event)
{
}
