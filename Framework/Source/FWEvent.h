#pragma once
#include <string>

namespace fw {

class FWEvent
{
public:
    FWEvent();
    virtual ~FWEvent();

    virtual const char* GetType() = 0; //(return GetStaticType())

};

}

