#pragma once
#include <queue>

namespace fw {

    class FWEvent;
    class GameCore;

    class FWEventManager
    {
    public:
        FWEventManager(GameCore* pGame);
        virtual ~FWEventManager();

        void AddEvent(FWEvent* pEvent);
        void ProcessEvents();

    protected:
        GameCore* m_pGame = nullptr;
        std::queue<FWEvent*> m_Events;
    };

}