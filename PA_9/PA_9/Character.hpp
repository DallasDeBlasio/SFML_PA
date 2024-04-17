#pragma once

#include "source.hpp"

class Character:public sf::Sprite
{
public:
	Character();
	//Character(int newDamage, int newHP, sf::RectangleShape newRectangle, sf::Sprite newSprite);

	//Character(const int& newDamage, const int& newHP, const sf::Vector2f& size, const sf::Vector2f& position, const sf::Vector2f& startIntRect, const sf::Texture texture);

	//void moveCharacter(sf::Vector2f vector);



	//void setDamage(int newDamage);
	//void setHP(int newHP);

	//int getDamage(void);
	//int getHP(void);

	float speed;
	int mDamage;
	int mHP;
private:


	
};