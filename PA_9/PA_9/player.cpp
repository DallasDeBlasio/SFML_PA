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

	//setting weapon hitbox
	this->weaponHitBox.setSize(sf::Vector2f(width * this->mScale, height * 2/3 * this->mScale));
	this->weaponHitBox.setOrigin(sf::Vector2f(this->weaponHitBox.getSize().x / 2, this->weaponHitBox.getSize().y / 2));
	
	//setting color,size,origin, and position of cooldownbar
	this->coolDownBar.setFillColor(sf::Color().White);
	this->coolDownBar.setSize(sf::Vector2f(width * scale, 6.f));
	this->coolDownBar.setOrigin(sf::Vector2f(width * scale / 2, 6.f / 2));
	this->coolDownBar.setPosition(sf::Vector2f(this->getPosition().x, this->getPosition().y - height * scale / 2)); 
}

void Player::interacts(Character& badGuy)
{
	if (badGuy.invinciblityTime == 0 && this->weaponHitBox.getGlobalBounds().intersects(badGuy.getGlobalBounds()))
	{
		sf::Vector2f bounceDirection(badGuy.getPosition().x - this->getPosition().x, badGuy.getPosition().y - this->getPosition().y);
		float bounceSpeed = getVectorManitude(bounceDirection);
		sf::Vector2f unitBounceDirection = getUnitVector(bounceDirection);
		badGuy.movementDirection = unitBounceDirection * 0.4f;
		badGuy.speed = 700;
		badGuy.currentHP -= this->mDamage;
		badGuy.invinciblityTime = 0.01f;
	}
}

void Player::setWeaponHitBox(void)
{
	if (this->facing == -1)
	{
		this->weaponHitBox.setPosition(this->getPosition().x - this->width - this->weaponHitBox.getSize().x, this->getPosition().y);
	}
	if (this->facing == 1)
	{
		this->weaponHitBox.setPosition(this->getPosition().x + this->width + this->weaponHitBox.getSize().x, this->getPosition().y);
	}
}

void Player::playerAttackManager(float DeltaTime)
{
	if (!this->canAttack())//if the hero cannot attack
	{
		this->attackTimer += DeltaTime;//.asSeconds();
		this->coolDownBar.setScale(sf::Vector2f(this->attackTimer / this->attackLength / 2, 1.f));
		this->coolDownBar.setPosition(sf::Vector2f(this->getPosition().x, this->getPosition().y + this->height * 1.75));

		if (this->attackTimer > this->attackCoolDown)
		{
			this->attackTimer = 0;
		}
	}


	if (this->attacking)
	{
		if (this->attackTimer > this->attackLength) //if the player is done with the attacking animation
		{
			this->attacking = false;
			this->setTexture(this->currentWalkFrame->frame, true);//set back to walking frames
		}
		else
		{
			textureNode* pCurAttack = this->initalAttackNode;
			this->setWeaponHitBox();

			if (0.1 < this->attackTimer)
			{
				pCurAttack = pCurAttack->pNext;
			}
			if (0.15 < this->attackTimer)
			{
				pCurAttack = pCurAttack->pNext;
			}
			this->setTexture(pCurAttack->frame, true);//start attack frame
		}
	}
	else
	{
		this->weaponHitBox.setPosition(sf::Vector2f(1920 + this->weaponHitBox.getSize().x, 1080 + this->weaponHitBox.getSize().y));
	}
}

void Player::startAttack(void)
{

}

bool Player::canAttack(void)
{
	bool canAttack = true;
	if (this->attackTimer != 0)
	{
		canAttack = false;
	}
	return canAttack;
}

bool Player::isAttacking(void)
{
	bool canAttack = false;
	if (this->attackTimer < this->attackLength)
	{
		canAttack = true;
	}
	return canAttack;
}
