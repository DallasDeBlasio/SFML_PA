#pragma once

#include "source.hpp"

class Character
{
public:
	Character(int newDamage, int newHP, sf::RectangleShape newRectangle, sf::Sprite newSprite);




	void setDamage(int newDamage);
	void setHP(int newHP);

	int getDamage(void);
	int getHP(void);

	sf::RectangleShape mRectangle; 
	sf::Sprite mSprite; 

private:
	int mDamage;
	int mHP;

	
};