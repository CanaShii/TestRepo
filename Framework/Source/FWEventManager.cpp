#include "CoreHeaders.h"
#include "FWEventManager.h"
#include "GameCore.h"
#include "FWEvent.h"




fw::FWEventManager::FWEventManager(GameCore* gamecore)
{

}

fw::FWEventManager::~FWEventManager()
{
    while (!m_Events.empty())
    {
        FWEvent* pEvent = m_Events.front();
        m_Events.pop();

        delete pEvent;
    }
}

void fw::FWEventManager::AddEvent(FWEvent* Event)
{
    m_Events.push(Event);
}

void fw::FWEventManager::ProcessEvents()
{
    while (!m_Events.empty())
    {
        FWEvent* pEvent = m_Events.front();
        m_Events.pop();

        m_pGame->OnEvent(pEvent);
        
        delete pEvent;
    }
}
