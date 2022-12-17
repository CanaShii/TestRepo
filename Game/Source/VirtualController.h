#pragma once
#include <Framework.h>

class VirtualController
{
public:
    enum Action
    {
        Left = 1 << 0,
        Right = 1 << 1,
        Up = 1 << 2,
        Down = 1 << 3,
    };

public:
    VirtualController();
    virtual ~VirtualController();

    void Reset();
    void StartFrame();
    void OnEvent(fw::FWEvent* pEvent);

    bool IsHeld(Action action);
    bool WasNewlyPressed(Action action);
    bool WasNewlyReleased(Action action);

protected:
    unsigned int m_OldValues = 0;
    unsigned int m_Values = 0;
};