#include "Framework.h"


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
}