#pragma once

#include "source.hpp"
#include "textureNode.hpp"
#include "HealthBar.hpp"
//#include "player.hpp"

class Player;
class Snail;

class Character:public sf::Sprite
{
protected:
	int maxHP;
	int currentHP;//character dies when this reaches 0
	int mDamage;//damage the character does to others
	float movmentSpeed;//maximum speed under normal movment //dont change
	float speed;//should be movementSpeed while moving, but should be higher if the character gets moved or launched
	int facing; //which direction the character is facing, -1 for left 1 for right
	int mScale;//a size multiplier for desplaying height and width
	int width;
	int height;
	int walkFrame;//increments everytime moveV is called, after it reaches the desired number gets set back to 0 and switches to next walk frame

	textureNode* currentWalkFrame;//holds the linked list 


public:
	//default character constructor
	Character();

	Character(int scale, int width, int height);//default sprite constructor
	Character(int scale, int width, int height , float initialSpeed);//default sprite constructor

	int getCurrentHP(void);
	float getMovementSpeed(void);

	bool isInvincible(void);//returns true if invincible

	void setSpeed(float newSpeed);
	void makeInvincible(void);//makes invincibilityTime 

	void takeDamage(int Damage);//subtracts damage from current hp

	sf::RectangleShape hitbox;
	sf::Vector2f movementDirection;//points in the direction of movement, should decay back to 0,0 under no outside influence
	HealthBar mHealthBar;//character's health bar



	virtual void moveV(float  deltaTime);// moves chracater speed distance along movementDirection
	virtual void moveV(Character target, float  deltaTime); //calls moveV

	void invincibilityManager(float DeltaTime);//takes care of all invincibiliy backwork

	// true for horizontal spacing, false for verticle
	// gap is the gap between same position in frames
	//creates a singlyly linked list in the place of a textureNode
	//creates a circularly linked list by default
	void fillTextureList(textureNode*& startFrame, int numFrames, float XCoordinateFirstFrame, float YCoordinateFirstFrame, bool horizontal, int gap, const char* filename);//firstTexture
	
	// true for horizontal spacing, false for verticle
	// gap is the gap between same position in frames
	//creates a singlyly linked list in the place of a textureNode
	//allows for the changing of the textures height and width
	//bool loop determines whether the list is circularly linked
	void fillTextureList(textureNode*& startFrame, int numFrames, float XCoordinateFirstFrame, float YCoordinateFirstFrame, float width, float height, bool horizontal, int gap, const char* filename, bool loop);//firstTexture

	virtual void interacts(Player &hero);//interaction between this character and a player// by default just prints if there was intersection
	virtual void interacts(Snail& hero);//interaction between this character and a snail// by default just prints if there was intersection

	//changes x and y to the position that would place the character's upper left corner at 0,0
	virtual void X_and_Y_Spawn_Locations(float& x, float& y);

	//changes x and y to the position that would place the character's upper left corner at 0,0//spawnPoint is ignored
	virtual void X_and_Y_Spawn_Locations(float& x, float& y, int spawnPoint);



private:



	//turns the character around when unit Vector points in the direction the character is not facing
	void shouldITurnAround(sf::Vector2f directionVector);

	//changes the characters texture to the next walk frame
	void nextWalkFrame(void);

	//work in tandem to decay speed and the movement vector such that if an outside force moves the character, they eventually set themselves back to default
	void decayMovment(float  deltaTime);
	void decaySpeed(float  deltaTime);

	float invinciblityTime;// = 0.f;//0 if not invincible
	float lengthOfInvincibility;//maximum invisibility time
};