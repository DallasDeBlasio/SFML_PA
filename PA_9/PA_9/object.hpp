#pragma once
#include "source.hpp"
#include "player.hpp"

class Object : public sf::Sprite
{
public:
	Object();
	~Object();
	void spawnTree(sf::Texture Rock);
	void spawnWell1(sf::Texture well);
	void spawnWell2(sf::Texture well);
	void spawnWell3(sf::Texture well);
	void spawnWell4(sf::Texture well);
	bool isColliding(Object& rocky, Character& sprite2);

};