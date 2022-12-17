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
        m_Textures["One"] = new fw::Texture("Data/Textures/One.png");
        m_Textures["Two"] = new fw::Texture("Data/Textures/Two.png");
        m_Textures["Three"] = new fw::Texture("Data/Textures/Three.png");
        m_Textures["Four"] = new fw::Texture("Data/Textures/Four.png");
        m_Textures["Five"] = new fw::Texture("Data/Textures/Five.png");
        m_Textures["Six"] = new fw::Texture("Data/Textures/Six.png");
        m_Textures["Seven"] = new fw::Texture("Data/Textures/Seven.png");
        m_Textures["Eight"] = new fw::Texture("Data/Textures/Eight.png");
        m_Textures["Nine"] = new fw::Texture("Data/Textures/Nine.png");



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
        m_Meshes["Triangle"]->drawMesh(m_Shader, m_Textures["One"], m_Scale, m_Angle, m_Position - fw::vec2(1 , 0), 1, m_uvScale, m_uvOffset);

    }

    void ScoreDisplay::SetScore(int score)
    {
        m_Score = score;
    }
