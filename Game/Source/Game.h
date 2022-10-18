#pragma once
#include <vector>
#include "GameCore.h"

class fw::Mesh;
class GameObject;

typedef fw::vec2 vec2;

class Game : public fw::GameCore
{
public:
    Game(fw::FWCore& core);
    virtual ~Game();

    virtual void StartFrame(float deltaTime) override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;

    virtual void Game::OnEvent(fw::FWEvent* event) override;
        

protected:
    fw::FWCore& m_Framework;
    fw::ImGuiManager* m_pImGuiManager = nullptr;

    GLuint m_VBO = 0;

    fw::ShaderProgram* m_pBasicShader = nullptr;
    fw::Mesh* m_PlayerMesh = nullptr;
    fw::Mesh* m_EnemyMesh = nullptr;
    std::vector<GameObject*> m_GameObjects;
    vec2 m_Pos = { 0,0 };
    float m_ElapsedTime = 0.0f;
    float m_Color[4] = { 1, 1, 1, 1 };
};
