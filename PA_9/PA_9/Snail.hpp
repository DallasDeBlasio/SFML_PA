#pragma once

#include "Character.hpp"

class Snail : public Character
{
public:
	Snail(int scale, int width, int height);
	Snail(int scale, int width, int height, float initialSpeed);


	void moveV(Character target , float  deltaTime);
	void X_and_Y_Spawn_Locations(float& x, float& y);
	void X_and_Y_Spawn_Locations(float& x, float& y, int spawnPoint);

	void interacts(Player &hero);

};