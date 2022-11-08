#pragma once
#include <vector>
#include "GameCore.h"
#include "DataType.h"

class fw::Mesh;
class GameObject;

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

    fw::ShaderProgram* m_pBasicShader = nullptr;
    std::map<std::string, fw::ShaderProgram*> m_Shaders;
    std::map<std::string, fw::Mesh*> m_Meshes;
    std::map<std::string, fw::Texture*> m_Textures;

    std::vector<GameObject*> m_GameObjects;

    vec2 m_Pos = { 0,0 };
    float m_ElapsedTime = 0.0f;
    float m_Color[4] = { 1, 1, 1, 1 };
};
