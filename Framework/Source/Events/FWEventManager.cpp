#include "CoreHeaders.h"
#include "FWEventManager.h"
#include "GameCore.h"
#include "Events/FWEvent.h"

namespace fw {

    

  
    FWEventManager::FWEventManager(GameCore* pGame)
        : m_pGame(pGame)
    {
    }

    FWEventManager::~FWEventManager()
    {
        while (!m_Events.empty())
        {
            FWEvent* pEvent = m_Events.front();
            m_Events.pop();

            delete pEvent;
        }
    }

    void FWEventManager::AddEvent(FWEvent* pEvent)
    {
        m_Events.push(pEvent);
    }

    void FWEventManager::ProcessEvents()
    {
        while (!m_Events.empty())
        {
            FWEvent* pEvent = m_Events.front();
            m_Events.pop();

            m_pGame->OnEvent(pEvent);

            delete pEvent;
        }
    }
}
