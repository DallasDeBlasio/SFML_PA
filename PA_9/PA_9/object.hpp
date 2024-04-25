#pragma once
#include "source.hpp"
#include "player.hpp"

class Object : public sf::Sprite
{
public:

	//constructor
	Object();


	//destructor
	~Object();


	//spawns the rock but says tree i dont wanna talk about it
	void spawnTree(sf::Texture Rock);


	//spawns all 4 wells
	void spawnWell1(sf::Texture well);
	void spawnWell2(sf::Texture well);
	void spawnWell3(sf::Texture well);
	void spawnWell4(sf::Texture well);

	//very important function for detecting collisions
	bool isColliding(Object& rocky, Character& sprite2);

};