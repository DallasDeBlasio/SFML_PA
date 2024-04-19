#pragma once

#include "Character.hpp"

class Snail : public Character
{
public:
	Snail(int scale, int width, int height);
	Snail(int scale, int width, int height, float initialSpeed);


	void moveTowardsTarget(Character target , float  deltaTime);
};