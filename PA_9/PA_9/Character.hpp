#pragma once

#include "source.hpp"

class Character:public sf::Sprite
{
public:
	Character();//default sprite constructor

	Character(int scale, int width, int height);//default sprite constructor

	sf::Vector2f movementDirection;//points in the direction of movement, should decay back to 0,0 under no outside influence
	float speed;//should be movementSpeed while moving, but should be higher if the character gets moved or launched
	float movmentSpeed;//maximum speed under normal movment //dont change
	int mDamage;
	int mHP;
	//int walkFrame;
	int width;
	int height;

	virtual void moveV(void);// moves hero speed distance along movementDirection
	void decayMovment(void);

	int facing; //-1 = left, 1 = right
	int mScale;

	sf::RectangleShape hitbox;

private:


	
};