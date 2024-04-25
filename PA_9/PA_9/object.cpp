#include "object.hpp"

//constructor
Object::Object()
{

}

//destructor
Object::~Object()
{

}

//spawns the rock but says tree i dont wanna talk about it
void Object::spawnTree(sf::Texture Rock)
{
	this->setTexture(Rock);
	this->setPosition((rand() % (1920 - 198)) + 33, (rand() % (1080 - 198)) + 33);
	this->setScale(.9, 0.7);
	this->setOrigin(9, 7);
}

//spawns all 4 wells
void Object::spawnWell1(sf::Texture well)
{
	this->setTexture(well);
	this->setPosition(0,0);
	this->setScale(3, 3);
}

void Object::spawnWell2(sf::Texture well)
{
	this->setTexture(well);
	this->setPosition(1920 - 30 * 3, 0);
	this->setScale(3, 3);
}

void Object::spawnWell3(sf::Texture well)
{
	this->setTexture(well);
	this->setPosition(1920 - 30 * 3, 1080 - 33 * 3);
	this->setScale(3, 3);
}

void Object::spawnWell4(sf::Texture well)
{
	this->setTexture(well);
	this->setPosition(0, 1080 - 33 * 3);
	this->setScale(3, 3);
}

//very important function for detecting collisions
bool Object::isColliding(Object& rocky, Character& herotest)
{
	if (rocky.getGlobalBounds().intersects(herotest.getGlobalBounds()))
	{
		sf::Vector2f bounceDirection(herotest.getPosition().x - rocky.getPosition().x, herotest.getPosition().y - rocky.getPosition().y);
		float bounceSpeed = getVectorManitude(bounceDirection);
		sf::Vector2f unitBounceDirection = getUnitVector(bounceDirection);
		herotest.movementDirection = unitBounceDirection * .1f;
		herotest.setSpeed(40);
		return true;
	}
}
