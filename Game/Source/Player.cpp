#include "Player.h"
#include <SpriteSheet.h>
#include "VirtualController.h"
#include <Framework.h>


Player::Player(fw::Mesh* mesh, fw::ShaderProgram* shader, fw::Texture* texture, fw::vec2 scale, fw::vec2 pos, float angle, fw::Camera* camera)
    : GameObject(mesh, shader, texture, scale, pos, angle, camera)

{
    m_SpriteSheet = new fw::SpriteSheet;
    for (int i = 0; i < 4; i++)
    {
        m_pControllers[i] = new VirtualController();
    }
    m_uvOffset = m_SpriteSheet->GetOffset("LinkWalkDown1");
    m_uvScale = m_SpriteSheet->GetScale("LinkWalkDown1");
    m_jsonSize = m_SpriteSheet->GetJsonSize();
}

Player::~Player()
{
    for (int i = 0; i < 4; i++)
    {
        delete m_pControllers[i];
    }

    delete m_SpriteSheet;
}

void Player::OnEvent(fw::FWEvent* event)
{
    m_pControllers[0]->OnEvent(event);
}

vec2 Player::GetPosition()
{
    return m_Position;
}

void Player::Update(float deltaTime)
{
    if (m_timer < deltaTime)
    {
        if (m_fixer == 0 || m_timer > deltaTime)
        {
            m_timer = deltaTime + 0.000250;
        }
    }
    if (m_pControllers[0]->IsHeld(VirtualController::Action::Left))
    {

       m_Position.X -= deltaTime + 0.0005;
       if (deltaTime > m_timer || m_fixer == 1)
       {
          
           m_uvOffset = m_SpriteSheet->GetOffset("LinkWalkLeft2");
           m_uvScale = m_SpriteSheet->GetScale("LinkWalkLeft2");
           m_fixer = 0;
       }
       else
       {
           m_uvOffset = m_SpriteSheet->GetOffset("LinkWalkLeft1");
           m_uvScale = m_SpriteSheet->GetScale("LinkWalkLeft1");
           m_fixer++;
       }
    }
    
    if (m_pControllers[0]->IsHeld(VirtualController::Action::Right))
    {
        m_Position.X += deltaTime + 0.0005;
        if (deltaTime > m_timer || m_fixer == 1)
        {
            m_uvOffset = m_SpriteSheet->GetOffset("LinkWalkRight2");
            m_uvScale = m_SpriteSheet->GetScale("LinkWalkRight2");
            m_fixer = 0;
        }
        else
        {
            m_uvOffset = m_SpriteSheet->GetOffset("LinkWalkRight1");
            m_uvScale = m_SpriteSheet->GetScale("LinkWalkRight1");
            m_fixer ++;
        }
    }
    if (m_pControllers[0]->IsHeld(VirtualController::Action::Up))
    {
        m_Position.Y += deltaTime + 0.0005;
        if (deltaTime > m_timer || m_fixer == 1)
        {
            m_uvOffset = m_SpriteSheet->GetOffset("LinkWalkUp2");
            m_uvScale = m_SpriteSheet->GetScale("LinkWalkUp2");
            m_fixer = 0;
        }
        else
        {
            m_uvOffset = m_SpriteSheet->GetOffset("LinkWalkUp1");
            m_uvScale = m_SpriteSheet->GetScale("LinkWalkUp1");
            m_fixer++;
        }
        
    }

    if (m_pControllers[0]->IsHeld(VirtualController::Action::Down))
    {
        m_Position.Y -= deltaTime + 0.0005;
        if (deltaTime > m_timer || m_fixer == 1)
        {
            m_uvOffset = m_SpriteSheet->GetOffset("LinkWalkDown2");
            m_uvScale = m_SpriteSheet->GetScale("LinkWalkDown2");
            m_fixer = 0;
        }
        else
        {
            m_uvOffset = m_SpriteSheet->GetOffset("LinkWalkDown1");
            m_uvScale = m_SpriteSheet->GetScale("LinkWalkDown1");
            m_fixer++;
        }
    }
}
