#pragma once
#include <Math/vec2.h>


namespace fw
{

	struct SpriteDetails
	{
		vec2 uvScale;
		vec2 uvOffset;
	};

	class SpriteSheet
	{
	public:
		SpriteSheet();
		~SpriteSheet();

		vec2 GetScale(std::string s);
		vec2 GetOffset(std::string s);

	protected:
		std::map<std::string, SpriteDetails*> spritedetails;
	};



}