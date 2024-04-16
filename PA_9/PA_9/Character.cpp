#include "Character.hpp"

Character::Character(int newDamage, int newHP, sf::RectangleShape newRectangle, sf::Sprite newSprite)
{
	this->mDamage = newDamage;
	this->mHP = newHP;
	this->mRectangle = newRectangle;
	this->mSprite = newSprite;
}

void Character::moveCharacter(sf::Vector2f vector)
{
	this->mRectangle.move(vector);
	this->mSprite.move(vector);
}

void Character::setDamage(int newDamage)
{
	this->mDamage = newDamage;
}

void Character::setHP(int newHP)
{
	this->mHP = newHP;
}

int Character::getDamage(void)
{
	return this->mDamage;
}

int Character::getHP(void)
{
	return this->mHP;
}
