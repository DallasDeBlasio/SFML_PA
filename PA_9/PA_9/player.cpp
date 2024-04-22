#include "player.hpp"

Player::Player(int scale, int width, int height, float initialSpeed): Character(scale, width, height, initialSpeed)
{
	this->initalAttackNode = nullptr;
	this->numAttackFrames = 3;
	this->attackLength = 0.5;
	this->attackCoolDown = 2;
	this->attacking = false;
}

void Player::attackOne(void)
{
	this->setTexture(this->initalAttackNode->frame, true);
}
