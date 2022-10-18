#include "vec2.h"

fw::vec2::vec2()
{
}

fw::vec2::~vec2()
{
}

void fw::vec2::SetPos(float X, float Y)
{
	m_X = X;
	m_Y = Y;
}

void fw::vec2::SetX(float X)
{
	m_X = X;
}

void fw::vec2::SetY(float Y)
{
	m_Y = Y;
}

float fw::vec2::X()
{
	return m_X;
}

float fw::vec2::Y()
{
	return m_Y;
}
