#pragma once
#include "Events/FWEventManager.h"

namespace fw {
    

    class FWEvent;
    class FWEventManager;

    class GameCore
    {
    public:
        GameCore();
        virtual ~GameCore();

        virtual void StartFrame(float deltaTime) = 0;
        virtual void OnEvent(FWEvent* pEvent) = 0;
        virtual void Update(float deltaTime) = 0;
        virtual void Draw() = 0;

        FWEventManager* GetEventManager() { return m_pEventManager; }

    protected:
        FWEventManager* m_pEventManager = nullptr;
    };


} 
