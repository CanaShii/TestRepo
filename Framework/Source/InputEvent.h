#pragma once
#include "FWEvent.h"


namespace fw {
    enum class DeviceType { Keyboard, Mouse };
    enum class InputState { Pressed, Released };
class InputEvent : public FWEvent
{
public:
    InputEvent(DeviceType device, InputState state, int id);
    virtual ~InputEvent();

    const char* GetType() override;//(return "InputEvent")
    const char* GetStaticType();
    DeviceType GetDeviceType();
    InputState GetInputState();
    int GetID();
    //vec2 GetPos();

protected:
    DeviceType m_Device;
    InputState m_State;
    int m_ID;
    //vec2 m_Pos;


};
}
