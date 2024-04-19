#pragma once

#include "Character.hpp"

class Snail : public Character
{
public:
	Snail(int scale, int width, int height);

	void moveTowardsTarget(Character target);
};