#include "Framework.h"
#include "Game.h"

int WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
    fw::FWCore Core;

    Core.Init(800 , 800);

    Game* pGame = new Game;
    Core.Run(pGame);
    delete pGame;

    Core.Shutdown();

    return 0;
}