#pragma once

class Game : public fw::GameCore
{
public:
    Game();
    virtual ~Game();

    virtual void StartFrame() override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;
    
    

protected:
    GLuint m_VBO = 0;
    fw::ShaderProgram* m_pBasicShader;
    float m_UniformXValue;
    float m_UniformYValue;
};
