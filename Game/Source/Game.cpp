#include "Framework.h"
#include <fstream>
#include "Game.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Camera.h"
#include "ScoreDisplay.h"
#include "VirtualController.h"
#include "TileMap.h"
#include <vector>

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

    for (int i = 0; i < 4; i++)
    {
        m_pControllers[i] = new VirtualController();
    }
   
    m_Shaders["Basic"] = new fw::ShaderProgram("Data/Shaders/Basic.vert", "Data/Shaders/Basic.frag");

    m_Shaders["Texture"] = new fw::ShaderProgram("Data/Shaders/Texture.vert", "Data/Shaders/Texture.frag");

    m_Meshes["Triangle"] = new fw::Mesh(values, fw::PrimitiveTypes::GLTRIANGLE);

    m_Textures["Default"] = new fw::Texture("Data/Textures/Zelda.png");

    m_Score = new ScoreDisplay;

    m_Camera = new fw::Camera;

    m_TileMap = new TileMap(m_Camera);

    m_Player = new Player(m_Meshes["Triangle"], m_Shaders["Texture"], m_Textures["Default"], vec2(0.5, 0.5), vec2(2,1), 0, m_Camera);

    m_Enemy = new Enemy(m_Meshes["Triangle"], m_Shaders["Texture"], m_Textures["Default"], vec2(0.5, 0.5), vec2(3, 5), 0, m_Camera);


    m_GameObjects.push_back(new GameObject(m_Meshes["Triangle"], m_Shaders["Texture"], m_Textures["Default"], vec2(0.3, 0.3), vec2(5, 5), 0, m_Camera));
    m_GameObjects.push_back(new GameObject(m_Meshes["Triangle"], m_Shaders["Texture"], m_Textures["Default"], vec2(0.3, 0.3), vec2(5, -5), 0, m_Camera));
    m_GameObjects.push_back(new GameObject(m_Meshes["Triangle"], m_Shaders["Texture"], m_Textures["Default"], vec2(0.3, 0.3), vec2(-5, 5), 0, m_Camera));
    m_GameObjects.push_back(new GameObject(m_Meshes["Triangle"], m_Shaders["Texture"], m_Textures["Default"], vec2(0.3, 0.3), vec2(-5, -5), 0, m_Camera));
    m_GameObjects.push_back(new GameObject(m_Meshes["Triangle"], m_Shaders["Texture"], m_Textures["Default"], vec2(0.3, 0.3), vec2(0, 7), 0, m_Camera));
    m_GameObjects.push_back(new GameObject(m_Meshes["Triangle"], m_Shaders["Texture"], m_Textures["Default"], vec2(0.3, 0.3), vec2(0, -7), 0, m_Camera));
    m_GameObjects.push_back(new GameObject(m_Meshes["Triangle"], m_Shaders["Texture"], m_Textures["Default"], vec2(0.3, 0.3), vec2(7, 0), 0, m_Camera));
    m_GameObjects.push_back(new GameObject(m_Meshes["Triangle"], m_Shaders["Texture"], m_Textures["Default"], vec2(0.3, 0.3), vec2(-7, 0), 0, m_Camera));
};

Game::~Game()
{
    delete m_pBasicShader;

    for (int i = 0; i < 4; i++)
    {
        delete m_pControllers[i];
    }

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

    for (auto it : m_Textures)
    {
        delete it.second;
    }

    delete m_Score;

    delete m_pImGuiManager;

    delete m_Player;

    delete m_Camera;

    delete m_TileMap;
}

void Game::StartFrame(float deltaTime)
{
    m_pImGuiManager->StartFrame(deltaTime);
    ImGui::ShowDemoWindow();

    m_pEventManager->ProcessEvents();
}

void Game::OnEvent(fw::FWEvent* event)
{
    m_pControllers[0]->OnEvent(event);
    m_Player->OnEvent(event);
}

void Game::Update(float deltaTime)
{
    for (int i = 0; i < m_GameObjects.size(); i++)
    {
        m_GameObjects[i]->Update(deltaTime);
    }
    m_Player->Update(deltaTime);
    m_Enemy->Update(deltaTime);
    m_Camera->SetPosition(m_Player->GetPosition());
    m_Score->SetScore(m_Player->GetPosition().X * 1000); //<- Adjust here to see other digits slower
}

void Game::Draw()
{
    glPointSize(20);
    glClearColor(0, 0, 0.2f, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    m_TileMap->Draw();
    for (int i = 0; i < m_GameObjects.size(); i++)
    {
        m_GameObjects[i]->Draw();
    }
    m_Player->Draw();
    m_Enemy->Draw();
    m_Score->Draw();
    m_pImGuiManager->EndFrame();
}


