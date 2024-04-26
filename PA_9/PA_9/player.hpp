#pragma once

#include "source.hpp"
#include "Character.hpp"


class Player : public Character
{
private:
	textureNode* initalAttackNode;//for attack frame list
	int numAttackFrames;//how many attack frames there are
	float attackLength;//how long it takes to complete the attacking motion
	float attackCoolDown;//how long between the start of an attack, and the the next attack
	float attackTimer;//timer that manages the time between attack

	sf::RectangleShape weaponHitBox;//hit box for when the hero is attacking



public:

	sf::RectangleShape coolDownBar;// a bar to demonstrate when the player can attack again

	Player(int scale, int width, int height, float initialSpeed);//player constructor
	~Player();


	void interacts(Character& badGuy);//player attacking enemey

	void setWeaponHitBox(void);//set weapon hitbox to the correct side

	void playerAttackManager(float DeltaTime);//takes care of all the behind the scenes attacking information

	void startAttack(void);//let the rest of the data members know the attack is starting

	bool canAttack(void);//return true if player can attack

	bool isAttacking(void);//return true if player is currently attacking
};