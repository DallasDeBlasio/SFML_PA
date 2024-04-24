#pragma once

#include "source.hpp"
#include "Character.hpp"


class Player : public Character
{
public:
	textureNode* initalAttackNode;
	int numAttackFrames;
	float attackLength;
	float attackCoolDown;
	float attackTimer;
	bool attacking;
	sf::RectangleShape weaponHitBox;
	//textureNode* currentAttackNode;

	sf::RectangleShape coolDownBar;

	Player(int scale, int width, int height, float initialSpeed);



	void interacts(Character& badGuy);


	void attackOne(void);
	void setWeaponHitBox(void);
};