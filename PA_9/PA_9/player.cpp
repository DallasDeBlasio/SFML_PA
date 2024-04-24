#include "player.hpp"
#include "Snail.hpp"

Player::Player(int scale, int width, int height, float initialSpeed): Character(scale, width, height, initialSpeed)
{
	this->initalAttackNode = nullptr;
	this->numAttackFrames = 3;
	this->attackLength = 0.5;
	this->attackCoolDown = 1.5;
	this->attackTimer = 0;
	this->attacking = false;
	this->weaponHitBox.setSize(sf::Vector2f(width * this->mScale, height * 2/3 * this->mScale));
	this->weaponHitBox.setOrigin(sf::Vector2f(this->weaponHitBox.getSize().x / 2, this->weaponHitBox.getSize().y / 2));
	//this->weaponHitBox.
}

void Player::interacts(Character& badGuy)
{
	if (badGuy.invinciblityTime == 0 && this->weaponHitBox.getGlobalBounds().intersects(badGuy.getGlobalBounds()))
	{
		sf::Vector2f bounceDirection(badGuy.getPosition().x - this->getPosition().x, badGuy.getPosition().y - this->getPosition().y);
		float bounceSpeed = getVectorManitude(bounceDirection);
		sf::Vector2f unitBounceDirection = getUnitVector(bounceDirection);
		badGuy.movementDirection = unitBounceDirection * 1250.f;
		badGuy.speed = 700;
		badGuy.currentHP -= this->mDamage;
		badGuy.invinciblityTime = 0.01f;
	}
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
