#pragma once

#include "source.hpp"

class Snail : public Character
{
	Snail(int scale, int width, int height);

	void moveTowardsTarget(Character target);
};