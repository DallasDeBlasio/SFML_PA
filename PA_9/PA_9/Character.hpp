#pragma once

#include "source.hpp"
#include "textureNode.hpp"
#include "HealthBar.hpp"
//#include "player.hpp"

class Player;
class Snail;

class Character:public sf::Sprite
{
public:
	Character();//default sprite constructor

	Character(int scale, int width, int height);//default sprite constructor
	Character(int scale, int width, int height , float initialSpeed);//default sprite constructor


	sf::Vector2f movementDirection;//points in the direction of movement, should decay back to 0,0 under no outside influence
	float speed;//should be movementSpeed while moving, but should be higher if the character gets moved or launched
	float movmentSpeed;//maximum speed under normal movment //dont change
	int mDamage;
	int maxHP;
	int currentHP;
	int walkFrame;
	int width;
	int height;

	float invinciblityTime;// = 0.f;//0 if not invincible

	virtual void moveV(float  deltaTime);// moves hero speed distance along movementDirection
	virtual void moveV(Character target, float  deltaTime);

	void fillTextureList(textureNode*& startFrame, int numFrames, float XCoordinateFirstFrame, float YCoordinateFirstFrame, bool horizontal, int gap, const char* filename);//firstTexture
	void fillTextureList(textureNode*& startFrame, int numFrames, float XCoordinateFirstFrame, float YCoordinateFirstFrame, float width, float height, bool horizontal, int gap, const char* filename, bool loop);//firstTexture

	

	//virtual void moveV(float  deltaTime);// moves hero speed distance along movementDirection
	
	virtual void interacts(Player &hero);
	virtual void interacts(Snail& hero);


	int facing; //-1 = left, 1 = right
	int mScale;

	sf::RectangleShape hitbox;

	textureNode* currentFrame;

	HealthBar mHealthBar;

	virtual void X_and_Y_Spawn_Locations(float& x, float& y);
	virtual void X_and_Y_Spawn_Locations(float& x, float& y, int spawnPoint);

private:

	//if directionVector is the opposite of facing, flip sprite
	void shouldITurnAround(sf::Vector2f directionVector);
	void nextWalkFrame(void);

	//work in tandem to decay speed and the movement vector such that if an outside force moves the character, they eventually re
	void decayMovment(float  deltaTime);
	void decaySpeed(float  deltaTime);

	
};