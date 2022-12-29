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

        m_Meshes["FirstDigit"] = new fw::Mesh(values, fw::PrimitiveTypes::GLTRIANGLE_FAN);
        m_Meshes["SecondDigit"] = new fw::Mesh(values, fw::PrimitiveTypes::GLTRIANGLE_FAN);
        m_Meshes["ThirdDigit"] = new fw::Mesh(values, fw::PrimitiveTypes::GLTRIANGLE_FAN);
        m_Meshes["FourthDigit"] = new fw::Mesh(values, fw::PrimitiveTypes::GLTRIANGLE_FAN);
        m_Meshes["FifthDigit"] = new fw::Mesh(values, fw::PrimitiveTypes::GLTRIANGLE_FAN);

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

        delete m_Camera;
    }

    void ScoreDisplay::Draw()
    {
        std::string scoreString = std::to_string(m_Score);

        int numDigits = scoreString.length();

        int digitScore = 0;

        for (int i = 0; i < numDigits; i++)
        {
            char digit = scoreString[i];
            int digitNumber = digit - '0';

            if (digitNumber < 0)
            {
                digitNumber *= -1;
            }

            m_Meshes["FirstDigit"]->drawMesh(m_Shader, m_Textures[digitNumber], m_Scale, m_Angle, m_Position + fw::vec2((numDigits - i - 1) * 9, 0), 1, m_uvScale, m_uvOffset, m_Camera, m_jsonSize);
        }
        if (m_Score >= 10 || m_Score <= -10)
        {
            digitScore = m_Score;
            if (digitScore < 0)
            {
                digitScore *= -1;
            }
            while (digitScore >= 10000)
            {
                digitScore -= 10000;
            }
            while (digitScore >= 1000)
            {
                digitScore -= 1000;
            }
            while (digitScore >= 100)
            {
                digitScore -=100;
            }
            m_Meshes["SecondDigit"]->drawMesh(m_Shader, m_Textures[digitScore / 10], m_Scale, m_Angle, m_Position - fw::vec2(1.f, 0.0f), 1, m_uvScale, m_uvOffset, m_Camera, m_jsonSize);
        }
        if (m_Score >= 100 || m_Score <= -100)
        {
            digitScore = m_Score;
            if (digitScore < 0)
            {
                digitScore *= -1;
            }
            while (digitScore >= 10000)
            {
                digitScore -= 10000;
            }
            while (digitScore >= 1000)
            {
                digitScore -= 1000;
            }
            m_Meshes["ThirdDigit"]->drawMesh(m_Shader, m_Textures[digitScore / 100], m_Scale, m_Angle, m_Position - fw::vec2(2.f, 0.0f), 1, m_uvScale, m_uvOffset, m_Camera, m_jsonSize);
        }
        if (m_Score >= 1000 || m_Score <= -1000)
        {
            digitScore = m_Score;
            if (digitScore < 0)
            {
                digitScore *= -1;
            }
            while (digitScore >= 10000)
            {
                digitScore -= 10000;
            }
            m_Meshes["FourthDigit"]->drawMesh(m_Shader, m_Textures[digitScore / 1000], m_Scale, m_Angle, m_Position - fw::vec2(3.f, 0.0f), 1, m_uvScale, m_uvOffset, m_Camera, m_jsonSize);
        }
        if (m_Score >= 10000 || m_Score <= -10000)
        {
            digitScore = m_Score;
            if (digitScore < 0)
            {
                digitScore *= -1;
            }
            m_Meshes["FifthDigit"]->drawMesh(m_Shader, m_Textures[digitScore / 10000], m_Scale, m_Angle, m_Position - fw::vec2(4.f, 0.0f), 1, m_uvScale, m_uvOffset, m_Camera, m_jsonSize);
        }

    }

    void ScoreDisplay::SetScore(int score)
    {
        m_Score = score;
    }
