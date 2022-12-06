#pragma once
#include <Math/vec2.h>


namespace fw
{

	class Camera
	{
	public:
		Camera();
		~Camera();


	protected:
		vec2 Position;
		vec2 ProjScale;
		vec2 WinSize;
	};



}