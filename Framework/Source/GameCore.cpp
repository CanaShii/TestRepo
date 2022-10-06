#include "CoreHeaders.h"
#include "GameCore.h"

fw::GameCore::GameCore()
{
    m_pEventManager = new FWEventManager(this);
}

fw::GameCore::~GameCore()
{
    delete m_pEventManager;
}


fw::FWEventManager* fw::GameCore::GetEventManager()
{
    return m_pEventManager;
}


