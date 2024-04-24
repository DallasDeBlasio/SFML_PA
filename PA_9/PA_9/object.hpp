#pragma once
#include "source.hpp"

class Object : public sf::Sprite
{
public:
	Object();
	~Object();
	void spawnTree(sf::Texture Rock);
	bool isColliding(const sf::Sprite& sprite1, const sf::Sprite& sprite2);
};