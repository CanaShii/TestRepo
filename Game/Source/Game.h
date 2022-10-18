#pragma once
#include "../../build/GameObject.h"
#include <vector>

class Game : public fw::GameCore
{
public:
    Game(fw::FWCore& core);
    virtual ~Game();

    virtual void StartFrame(float deltaTime) override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;

protected:
    fw::FWCore& m_Framework;
    fw::ImGuiManager* m_pImGuiManager = nullptr;

    GameObject* m_GameObject;

     

    //GLuint m_VBO = 0;

    //fw::ShaderProgram* m_pBasicShader = nullptr;
    fw::ShaderProgram* m_pSecondShader = nullptr;

    float m_PosX = 0.0f;
    float m_ElapsedTime = 0.0f;
};
