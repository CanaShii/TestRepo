#include "CoreHeaders.h"
#include "Camera.h"
#include "../../Game/Source/DataType.h"

fw::Camera::Camera()
{



}

fw::Camera::~Camera()
{
}

void fw::Camera::SetPosition(vec2 pos)
{
    position = pos;
}

vec2 fw::Camera::GetProjScale()
{
    return projScale;
}

vec2 fw::Camera::GetWinSize()
{
    return winSize;
}
