#pragma once
#include "FWEventManager.h"

namespace fw {
    
class GameCore
{
public:
    GameCore() {}
    virtual ~GameCore() {}

    FWEventManager* GetEventManager();
    
    virtual void StartFrame(float deltaTime) = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Draw() = 0;
protected:
    FWEventManager* m_pEventManager = nullptr;
};

} // namespace fw
