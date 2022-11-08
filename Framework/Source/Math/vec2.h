#pragma once
#include "GameCore.h"
#include "CoreHeaders.h"

namespace fw
{

class vec2
{
public:
    vec2()                   { X = 0; Y = 0; }
    vec2(float nx, float ny) { X = nx; Y = ny; }

    //void Add(float nx, float ny) { X += nx; Y += ny; }
    void Set(float nx, float ny) { X = nx; Y = ny; }

    vec2 operator+(const vec2& o) const { return vec2(X + o.X, Y + o.Y); }
    vec2 operator-(const vec2& o) const { return vec2(X - o.X, Y - o.Y); }
    vec2 operator*(const vec2& o) const { return vec2(X * o.X, Y * o.Y); }
    vec2 operator/(const vec2& o) const { return vec2(X / o.X, Y / o.Y); }

    vec2 operator+(float o) const { return vec2(X + o, Y + o); }
    vec2 operator-(float o) const { return vec2(X - o, Y - o); }
    vec2 operator*(float o) const { return vec2(X * o, Y * o); }
    vec2 operator/(float o) const { return vec2(X / o, Y / o); }

    vec2& operator+=(const vec2& o) { X += o.X; Y += o.Y; return *this; }
    vec2& operator-=(const vec2& o) { X -= o.X; Y -= o.Y; return *this; }
    vec2& operator*=(const vec2& o) { X *= o.X; Y *= o.Y; return *this; }
    vec2& operator/=(const vec2& o) { X /= o.X; Y /= o.Y; return *this; }

    vec2 operator-() const { return vec2(-X, -Y); }



    static void test();

    float Length() const
    {
        return sqrtf(X * X + Y * Y);
    }

    float DisctanceTo(const vec2& o) const
    {
        return (o - *this).Length();
    }

    vec2 GetNormalized()
    {
        return ( (*this) / Length());
    }

    void Normalize()
    {
        (*this) = GetNormalized();
    }

public:
    float X, Y; 
};

}