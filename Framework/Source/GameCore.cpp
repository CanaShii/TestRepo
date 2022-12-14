#include "CoreHeaders.h"
#include "GameCore.h"
#include "Events/FWEventManager.h"

namespace fw {

    GameCore::GameCore()
    {
        m_pEventManager = new FWEventManager(this);
    }

    GameCore::~GameCore()
    {
        delete m_pEventManager;
    }

}


