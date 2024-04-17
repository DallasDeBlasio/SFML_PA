#include "Character.hpp"

Character::Character(int newDamage, int newHP, sf::RectangleShape newRectangle, sf::Sprite newSprite)
{
	this->mDamage = newDamage;
	this->mHP = newHP;
	this->mRectangle = newRectangle;
	this->mSprite = newSprite;
}

Character::Character(const int& newDamage, const int& newHP, const sf::Vector2f& size, const sf::Vector2f& position, const sf::Vector2f & startIntRect, const sf::Texture texture)
{
	this->mDamage = newDamage;
	this->mHP = newHP;
	this->mRectangle.setSize(size);
	this->mRectangle.setPosition(position);
	this->mSprite.setTextureRect(sf::IntRect(startIntRect.x, startIntRect.y, startIntRect.x + size.x, startIntRect.y + size.y));
	this->mSprite.setPosition(position);
	this->mSprite.setTexture(texture);
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
