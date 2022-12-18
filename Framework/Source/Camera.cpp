#include "CoreHeaders.h"
#include "Camera.h"
#include "../../Game/Source/DataType.h"

namespace fw
{
    Camera::Camera() 
    {

    }

    Camera::~Camera()
    {
    }

    void Camera::SetPosition(vec2 pos)
    {
        position = pos;
    }

    vec2 Camera::GetProjScale()
    {
        return projScale;
    }

    vec2 Camera::GetWinSize()
    {
        return winSize;
    }

    vec2 Camera::GetCamPosition()
    {
        
        return position;
    }
}