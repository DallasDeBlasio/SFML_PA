#pragma once

#include "source.hpp"
#include "Character.hpp"


class Player : public Character
{
public:
	textureNode* initalAttackNode;//for attack frame list
	int numAttackFrames;//how many attack frames there are
	float attackLength;//how long it takes to complete the attacking motion
	float attackCoolDown;//how long between the start of an attack, and the the next attack
	float attackTimer;//timer that manages the time between attack
	bool attacking;//whether the hero is in the attacking animation

	sf::RectangleShape weaponHitBox;//hit box for when the hero is attacking
	sf::RectangleShape coolDownBar;// a bar to demonstrate when the player can attack again

	Player(int scale, int width, int height, float initialSpeed);//player constructor



	void interacts(Character& badGuy);//player attacking enemey

	void setWeaponHitBox(void);

	void heroAttackManager(float DeltaTime);

	void startAttack(void);

	bool canAttack(void);

	bool isAttacking(void);
};