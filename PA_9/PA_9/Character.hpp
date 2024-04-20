#pragma once

#include "source.hpp"
#include "textureNode.hpp"

class Character:public sf::Sprite
{
public:
	Character();//default sprite constructor

	Character(int scale, int width, int height);//default sprite constructor

	sf::Vector2f movementDirection;//points in the direction of movement, should decay back to 0,0 under no outside influence
	float speed;//should be movementSpeed while moving, but should be higher if the character gets moved or launched
	float movmentSpeed;//maximum speed under normal movment //dont change
	int mDamage;
	int maxHP;
	int walkFrame;
	int width;
	int height;

	virtual void moveV(float  deltaTime);// moves hero speed distance along movementDirection
	void decayMovment(void);
	void fillTextureList(textureNode* startFrame, int numFrames, float XCoordinateFirstFrame, float YCoordinateFirstFrame, bool horizontal, int gap, const char* filename);//firstTexture
	//virtual void moveV(float  deltaTime);// moves hero speed distance along movementDirection


	int facing; //-1 = left, 1 = right
	int mScale;

	sf::RectangleShape hitbox;

	textureNode* currentFrame;

private:

	//if directionVector is the opposite of facing, flip sprite
	void shouldITurnAround(sf::Vector2f directionVector);
	void nextWalkFrame(void);

	
};