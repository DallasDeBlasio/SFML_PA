#include "object.hpp"

Object::Object()
{

}

Object::~Object()
{

}

void Object::spawnTree(sf::Texture Rock)
{
	this->setTexture(Rock);
	this->setPosition((rand() % (1920 - 198)) + 33, (rand() % (1080 - 198)) + 33);
	this->setScale(1.1, 0.9);
}

bool Object::isColliding(const sf::Sprite& sprite1, const sf::Sprite& sprite2)
{
	return sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds());
}




