#include "Framework.h"


int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    fw::FWCore Core;
    Core.Init(800 , 800);
    Core.Run();
    Core.Shutdown();

}