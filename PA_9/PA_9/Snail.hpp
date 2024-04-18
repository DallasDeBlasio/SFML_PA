#pragma once

#include "Character.hpp"

class Snail : public Character
{
	Snail(int scale, int width, int height);

	void moveTowardsTarget(Character target);
};