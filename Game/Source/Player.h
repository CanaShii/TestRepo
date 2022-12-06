#pragma once
#include "GameObject.h"


class fw::SpriteSheet;

class Player
{

public:
	Player();
	~Player();
	
	virtual void Update(float deltaTime);
protected:
	vec2 uvScale;
	vec2 uvOffset;

	fw::SpriteSheet* SpriteSheet;
};

