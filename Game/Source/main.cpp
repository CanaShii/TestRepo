#include "Framework.h"
#include "Game.h"

int WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
    {
        fw::FWCore core;

        core.Init(1280, 720);

        Game game(core);
        core.Run(&game);

        core.Shutdown();
    }
    return 0;
}
