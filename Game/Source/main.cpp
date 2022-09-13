#include "Framework.h"


<<<<<<< HEAD
int WinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
    fw::FWCore Core;
    Core.Init(600 , 600);
    Core.Run();
    Core.Shutdown();

    

}
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_KEYDOWN:
        
        break;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
=======
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    fw::FWCore Core;
    Core.Init(800 , 800);
    Core.Run();
    Core.Shutdown();

>>>>>>> 5370617a8c3c14a5b2155df3a67e1d80888e2f52
}