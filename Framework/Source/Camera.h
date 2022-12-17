#pragma once
#include <Math/vec2.h>


namespace fw
{

	class Camera
	{
	public:
		Camera();
		~Camera();
		 
		void SetPosition(vec2 pos);
		vec2 GetProjScale();
		vec2 GetWinSize();

	protected:
		vec2 position;
		vec2 projScale;
		vec2 winSize;
	};



}