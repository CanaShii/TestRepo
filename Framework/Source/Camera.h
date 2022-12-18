#pragma once
#include <Math/vec2.h>


namespace fw
{

	class Camera
	{
	protected:
		vec2 position = vec2(0, 0);
		vec2 projScale = vec2(0.1, 0.1);
		vec2 winSize;
	public:
		Camera();
		~Camera();
		 
		void SetPosition(vec2 pos);
		vec2 GetProjScale();
		vec2 GetWinSize();
		vec2 GetCamPosition();

	};



}