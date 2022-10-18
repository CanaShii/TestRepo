#pragma once

namespace fw {

    class GameCore;
    class FWEvent;

class FWEventManager
{
public:
     FWEventManager(GameCore* gamecore);
     virtual ~FWEventManager();

     void AddEvent(FWEvent* Event);
     void ProcessEvents();

protected:
    //std::queue<FWEvent*> m_Queue;
    GameCore* m_pGame;



};

}