#include "Character.hpp"

//Character::Character(int newDamage, int newHP, sf::RectangleShape newRectangle, sf::Sprite newSprite)
//{
//	this->mDamage = newDamage;
//	this->mHP = newHP;
//	this->mRectangle = newRectangle;
//	this->mSprite = newSprite;
//}
//
//Character::Character(const int& newDamage, const int& newHP, const sf::Vector2f& size, const sf::Vector2f& position, const sf::Vector2f & startIntRect, const sf::Texture texture)
//{
//	this->mDamage = newDamage;
//	this->mHP = newHP;
//	this->mRectangle.setSize(size);
//	this->mRectangle.setPosition(position);
//	this->mSprite.setTextureRect(sf::IntRect(startIntRect.x, startIntRect.y, startIntRect.x + size.x, startIntRect.y + size.y));
//	this->mSprite.setPosition(position);
//	this->mSprite.setTexture(texture);
//}
//
//void Character::moveCharacter(sf::Vector2f vector)
//{
//	this->mRectangle.move(vector);
//	this->mSprite.move(vector);
//}
//
//void Character::setDamage(int newDamage)
//{
//	this->mDamage = newDamage;
//}
//
//void Character::setHP(int newHP)
//{
//	this->mHP = newHP;
//}
//
//int Character::getDamage(void)
//{
//	return this->mDamage;
//}
//
//int Character::getHP(void)
//{
//	return this->mHP;
//}

Character::Character():Sprite()
{
	this->speed = 0.2;
	this->mHP = 30;
	this->mDamage = 0;
	this->movmentSpeed = 0.2;
	this->walkFrame = 0;
	this->facing = 1;
	this->mScale = 1;
	this->height = 50;
	this->width = 50;

	this->movementDirection = sf::Vector2f(0.f, 0.f);
	//this.
}

Character::Character(int scale,int width, int height)
{
	this->speed = 0.2;
	this->mHP = 30;
	this->mDamage = 0;
	this->movmentSpeed = 0.2;
	this->walkFrame = 0;
	this->facing = 1;
	this->mScale = scale;
	this->width = width;
	this->height = height;
	this->setScale(this->mScale, this->mScale);

	this->movementDirection = sf::Vector2f(0.f, 0.f);
	//this.
}

void Character::moveV(void)
{
	sf::Vector2f unitVector(getUnitVector(this->movementDirection));
	sf::Vector2f speed_in_direction_unitVector = unitVector * this->speed;
	this->move(speed_in_direction_unitVector);
	if (unitVector.x > 0 && this->facing == -1)
	{
		this->scale(-1.f, 1.f);
		this->facing = 1;
	}
	else if (unitVector.x < 0 && this->facing == 1)
	{
		this->scale(-1.f, 1.f);
		this->facing = -1;

	}
	decayMovment();
	//    herotest.scale(-1.f, 1.f);
//    herotest.move(-heroWidth * heroScale, 0.f);
}

void Character::decayMovment(void)
{
	if (this->movementDirection.x > 1)
	{
		this->movementDirection.x -= 0.95;//this->movementSpeed
	}
	else if (this->movementDirection.y < -1)
	{
		this->movementDirection.x += 0.95;//this->movmentSpeed;
	}
	else
	{
		this->movementDirection.x = 0;
	}

	if (this->movementDirection.y > 1)
	{
		this->movementDirection.y -= 0.95;//this->movmentSpeed;
	}
	else if (this->movementDirection.y < -1)
	{
		this->movementDirection.y += 0.95;//this->movmentSpeed;
	}
	else
	{
		this->movementDirection.y = 0;
	}
}
