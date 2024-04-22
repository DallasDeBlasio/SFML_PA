#include "player.hpp"

Player::Player(int scale, int width, int height, float initialSpeed): Character(scale, width, height, initialSpeed)
{
	this->initalAttackNode = nullptr;
	this->numAttackFrames = 3;
	this->attackLength = 0.5;
	this->attackCoolDown = 2;
	this->attacking = false;
	this->weaponHitBox.setSize(sf::Vector2f(width * this->mScale, height * 2/3 * this->mScale));
	this->weaponHitBox.setOrigin(sf::Vector2f(this->weaponHitBox.getSize().x / 2, this->weaponHitBox.getSize().y / 2));
	//this->weaponHitBox.
}

void Player::attackOne(void)
{
	this->setTexture(this->initalAttackNode->frame, true);
}

void Player::setWeaponHitBox(void)
{
	if (this->facing == -1)
	{
		this->weaponHitBox.setPosition(this->getPosition().x - this->width - this->weaponHitBox.getSize().x, this->getPosition().y);
		//this->weaponHitBox.setPosition(this->getPosition().x, this->getPosition().y);
	}
	if (this->facing == 1)
	{
		this->weaponHitBox.setPosition(this->getPosition().x + this->width + this->weaponHitBox.getSize().x, this->getPosition().y);
		//this->weaponHitBox.setPosition(this->getPosition().x, this->getPosition().y);


	}
}
