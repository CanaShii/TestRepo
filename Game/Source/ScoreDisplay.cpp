#include "Framework.h"
#include "ScoreDisplay.h"


    ScoreDisplay::ScoreDisplay()
    {
        std::vector<fw::VertexFormat> values = {
        { {-1.1f, -1.15f }, 255, 255, 255, 255, { 0.0f, 0.0f} },
        { { 1.1f, -1.15f }, 255, 255, 255, 255, { 1.0f, 0.0f} },
        { { 1.1f,  1.15f }, 255, 255, 255, 255, { 1.0f, 1.0f} },
        { {-1.1f,  1.15f }, 255, 255, 255, 255, { 0.0f, 1.0f} },
        };
        m_Shader = new fw::ShaderProgram("Data/Shaders/Texture.vert", "Data/Shaders/Texture.frag");

        m_Meshes["Triangle"] = new fw::Mesh(values, fw::PrimitiveTypes::GLTRIANGLE_FAN);

        m_Textures["Zero"] = new fw::Texture("Data/Textures/Zero.png");
        /*m_Textures["One"] = new fw::Texture("Data/Textures/Number1.png");
        m_Textures["Two"] = new fw::Texture("Data/Textures/Number2.png");
        m_Textures["Three"] = new fw::Texture("Data/Textures/Number3.png");
        m_Textures["Four"] = new fw::Texture("Data/Textures/Number4.png");
        m_Textures["Five"] = new fw::Texture("Data/Textures/Number5.png");
        m_Textures["Six"] = new fw::Texture("Data/Textures/Number6.png");
        m_Textures["Seven"] = new fw::Texture("Data/Textures/Number7.png");
        m_Textures["Eight"] = new fw::Texture("Data/Textures/Number8.png");
        m_Textures["Nine"] = new fw::Texture("Data/Textures/Number9.png");*/



    }

    ScoreDisplay::~ScoreDisplay()
    {
        for (auto it : m_Meshes)
        {
            delete it.second;
        }

        for (auto it : m_Textures)
        {
            delete it.second;
        }

        delete m_Shader;
    }

    void ScoreDisplay::Draw()
    {

        m_Meshes["Triangle"]->drawMesh(m_Shader, m_Textures["Zero"], m_Scale, m_Angle, m_Position, 1, m_uvScale, m_uvOffset);


    }

    void ScoreDisplay::SetScore(int score)
    {
        m_Score = score;
    }
