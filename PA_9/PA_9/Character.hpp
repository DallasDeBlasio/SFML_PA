#pragma once

#include "source.hpp"

class Character:public sf::Sprite
{
public:
	Character();//default sprite constructor



	//Character(int newDamage, int newHP, sf::RectangleShape newRectangle, sf::Sprite newSprite);

	//Character(const int& newDamage, const int& newHP, const sf::Vector2f& size, const sf::Vector2f& position, const sf::Vector2f& startIntRect, const sf::Texture texture);

	//void moveCharacter(sf::Vector2f vector);



	//void setDamage(int newDamage);
	//void setHP(int newHP);

	//int getDamage(void);
	//int getHP(void);
	//bool moving;


	sf::Vector2f movementDirection;//points in the direction of movement, should decay back to 0,0 under no outside influence
	float speed;//should be movementSpeed while moving, but should be higher if the character gets moved or launched
	float movmentSpeed;//maximum speed under normal movment
	int mDamage;
	int mHP;

	virtual void move(void);// moves hero speed distance along movementDirection

private:


	
};