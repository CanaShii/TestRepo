#pragma once
#include <vector>
#include "GameCore.h"
#include "DataType.h"

class fw::Mesh;
class VirtualController;
class GameObject;
class Player;
class ScoreDisplay;
class fw::Camera;
class TileMap;

class Game : public fw::GameCore
{
public:
    Game(fw::FWCore& core);
    virtual ~Game();

    virtual void StartFrame(float deltaTime) override;
    virtual void Game::OnEvent(fw::FWEvent* event) override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;

protected:
    fw::FWCore& m_Framework;
    fw::ImGuiManager* m_pImGuiManager = nullptr;
    VirtualController* m_pControllers[4] = { nullptr };

    fw::ShaderProgram* m_pBasicShader = nullptr;
    std::map<std::string, fw::ShaderProgram*> m_Shaders;
    std::map<std::string, fw::Mesh*> m_Meshes;
    std::map<std::string, fw::Texture*> m_Textures;

    std::vector<GameObject*> m_GameObjects;

    Player* m_Player = nullptr;
    ScoreDisplay* m_Score = nullptr;
    fw::Camera* m_Camera = nullptr;
    TileMap* m_TileMap = nullptr;

    float m_ElapsedTime = 0.0f;
    float m_Color[4] = { 1, 1, 1, 1 };
};
