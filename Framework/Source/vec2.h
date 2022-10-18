#pragma once
#include "GameCore.h"
#include "CoreHeaders.h"

namespace fw 
{

class vec2
{

public:
	vec2();
	~vec2();

	void SetPos(float X, float Y);
	void SetX(float X);
	void SetY(float Y);
	float X();
	float Y();

protected:
	float m_X;
	float m_Y;
};

}