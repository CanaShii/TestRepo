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

        m_Camera = new fw::Camera;

        m_Meshes["Triangle"] = new fw::Mesh(values, fw::PrimitiveTypes::GLTRIANGLE_FAN);

        m_Textures[0] = new fw::Texture("Data/Textures/Zero.png");
        m_Textures[1] = new fw::Texture("Data/Textures/One.png");
        m_Textures[2] = new fw::Texture("Data/Textures/Two.png");
        m_Textures[3] = new fw::Texture("Data/Textures/Three.png");
        m_Textures[4] = new fw::Texture("Data/Textures/Four.png");
        m_Textures[5] = new fw::Texture("Data/Textures/Five.png");
        m_Textures[6] = new fw::Texture("Data/Textures/Six.png");
        m_Textures[7] = new fw::Texture("Data/Textures/Seven.png");
        m_Textures[8] = new fw::Texture("Data/Textures/Eight.png");
        m_Textures[9] = new fw::Texture("Data/Textures/Nine.png");



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
        std::string scoreString = std::to_string(m_Score);
       
        int numDigits = scoreString.length();

        int totalWidth = numDigits * 9;

        if (m_Position.X < 0 || m_Position.X + totalWidth > 1280)
        {
            m_Position.X = 1280 - totalWidth;
        }

        for (int i = 0; i < numDigits; i++)
        {

            char digit = scoreString[i];

            int digitNumber = digit - '0';

            m_Position.X += 1 * i;
            if (numDigits > 1)
            {
                if (m_Score >= 10)
                {
                    
                    digitNumber *= 10;
                }

                m_Meshes["Triangle"]->drawMesh(m_Shader, m_Textures[digitNumber /10], m_Scale, m_Angle, m_Position, 1, m_uvScale, m_uvOffset, m_Camera);

                m_Position.X -= 1 * i;
                if (m_Score >= 10)
                {

                    digitNumber %= 10;
                }
                if (digitNumber == 0)
                {
                    digitNumber += 1;
                }
                if (m_Score == 20)
                {
                    digitNumber += 1;
                }
                if (m_Score == 30)
                {
                    digitNumber += 1;
                }
                if (m_Score == 40)
                {
                    digitNumber += 1;
                }
                if (m_Score == 50)
                {
                    digitNumber += 1;
                }
                if (m_Score == 60)
                {
                    digitNumber += 1;
                }
                if (m_Score == 70)
                {
                    digitNumber += 1;
                }
                if (m_Score == 80)
                {
                    digitNumber += 1;
                }
                if (m_Score == 90)
                {
                    digitNumber += 1;
                }

               
            }
            m_Meshes["Triangle"]->drawMesh(m_Shader, m_Textures[digitNumber], m_Scale, m_Angle, m_Position, 1, m_uvScale, m_uvOffset, m_Camera);
            
        }

    }

    void ScoreDisplay::SetScore(int score)
    {
        m_Score = score;
    }
