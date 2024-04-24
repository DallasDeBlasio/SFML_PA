#pragma once

#include "Character.hpp"

class Snail : public Character
{
public:
	//snail constructor with pr-eset initial speed
	Snail(int scale, int width, int height);

	//snail constructor with initial speed as a parameter
	Snail(int scale, int width, int height, float initialSpeed);

	//Overridden Snail moveV (moves snail towards whatever target is selected
	void moveV(Character target , float  deltaTime);

	//changes x and y to spawning locations randomly
	void X_and_Y_Spawn_Locations(float& x, float& y);

	//changes x and y to predetermined spawnPoints based on an integer (1-4) passed in
	void X_and_Y_Spawn_Locations(float& x, float& y, int spawnPoint);

	//if snail is touching player, attack player
	void interacts(Player &hero);

};