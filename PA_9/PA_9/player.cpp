#include "player.hpp"
#include "Snail.hpp"

int windowLength = 1080;
int windowWidth = 1920;

Player::Player(int scale, int width, int height, float initialSpeed): Character(scale, width, height, initialSpeed)
{
	this->initalAttackNode = nullptr;//for attack frame list
	this->numAttackFrames = 3;//how many attack frames there are
	this->attackLength = 0.5;//how long it takes to complete the attacking motion
	this->attackCoolDown = 1.5;//how long between the start of an attack, and the the next attack
	this->attackTimer = 0;//timer that manages the time between attack
	//this->attacking = false;//whether the hero is in the attacking animation

	//setting weapon hitbox
	this->weaponHitBox.setSize(sf::Vector2f(width * this->mScale, height * 2/3 * this->mScale));
	this->weaponHitBox.setOrigin(sf::Vector2f(this->weaponHitBox.getSize().x / 2, this->weaponHitBox.getSize().y / 2));
	
	//setting color,size,origin, and position of cooldownbar
	this->coolDownBar.setFillColor(sf::Color().White);
	this->coolDownBar.setSize(sf::Vector2f(width * scale, 6.f));
	this->coolDownBar.setOrigin(sf::Vector2f(width * scale / 2, 6.f / 2));
	this->coolDownBar.setPosition(sf::Vector2f(this->getPosition().x, this->getPosition().y - height * scale / 2)); 

	//setting the hero walking textures to walk frame node
	this->fillTextureList(this->currentWalkFrame, 4, 16, 57, true, 48, "Assets/tempHero.png");
	//set player to center of screen
	this->setPosition(windowWidth / 2.f + this->width / 2.0f * this->mScale, windowLength / 2.f + this->height / 2.0f * this->mScale);
	//setting the player texture to the first frame
	this->setTexture(this->currentWalkFrame->frame);
	//fill attacknode with hero attacking animation
	this->fillTextureList(this->initalAttackNode, 3, 16, 297, this->width * 2, this->height, true, 48, "Assets/tempHero.png", false);
}

Player::~Player()
{
	if (this->initalAttackNode != nullptr)
	{
		delete this->initalAttackNode;
	}
}

void Player::interacts(Character& badGuy)
{
	//if enemy is not invincible && weaponHitBox intesects enemy
	if (!badGuy.isInvincible() && this->weaponHitBox.getGlobalBounds().intersects(badGuy.getGlobalBounds()))
	{
		sf::Vector2f bounceDirection(badGuy.getPosition().x - this->getPosition().x, badGuy.getPosition().y - this->getPosition().y);//vector from hero to bad guy//will launch in this direction
		sf::Vector2f unitBounceDirection = getUnitVector(bounceDirection);//unit vector in direction bounce direction
		badGuy.movementDirection = unitBounceDirection * 0.4f;//set movement diretion for enemy
		badGuy.setSpeed(700);
		badGuy.takeDamage(this->mDamage);//reduce enemy health
		badGuy.makeInvincible();
	}
}

void Player::setWeaponHitBox(void)//set weapon hitbox to the correct side
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

void Player::playerAttackManager(float DeltaTime)//takes care of all the behind the scenes attacking information
{
	if (!this->canAttack())//if the hero cannot attack
	{
		this->attackTimer += DeltaTime;//add time to attack timer

		//set cooldownbar data
		this->coolDownBar.setScale(sf::Vector2f(this->attackTimer / this->attackLength / 2, 1.f));
		this->coolDownBar.setPosition(sf::Vector2f(this->getPosition().x, this->getPosition().y + this->height * 1.75));

		if (this->attackTimer > this->attackCoolDown)//if the cooldown has passed reset attackTimer
		{
			this->attackTimer = 0;
		}
	}


	if (this->isAttacking())//if is attacking
	{
			textureNode* pCurAttack = this->initalAttackNode;//pCur is the animation frame that will be drawn
			this->setWeaponHitBox();

			if (0.1 < this->attackTimer)//switch to second frame
			{
				pCurAttack = pCurAttack->pNext;
			}
			if (0.15 < this->attackTimer)//switch to third frame
			{
				pCurAttack = pCurAttack->pNext;
			}
			this->setTexture(pCurAttack->frame, true);//set attack frame
	}
	else
	{
		//if not attacking set weapon hitbox outside of map
		this->weaponHitBox.setPosition(sf::Vector2f(1920 + this->weaponHitBox.getSize().x, 1080 + this->weaponHitBox.getSize().y));
	}
}

void Player::startAttack(void)//let the rest of the data members know the attack is starting
{
	if (this->canAttack())//if can attack
	{
		this->attackTimer = 0.001;
	}
}

bool Player::canAttack(void)//return true if player can attack
{
	bool canAttack = true;
	if (this->attackTimer != 0)
	{
		canAttack = false;
	}
	return canAttack;
}

bool Player::isAttacking(void)//return true if player is currently attacking
{
	bool isAttacking = false;
	if (this->attackTimer < this->attackLength && this->attackTimer != 0)
	{
		isAttacking = true;
	}
	return isAttacking;
}
