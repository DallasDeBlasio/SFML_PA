#include "Snail.hpp"

Snail::Snail(int scale, int width, int height) : Character(scale, width, height)
{
	this->speed = 0.1;
}

Snail::Snail(int scale, int width, int height, float initialSpeed) : Character(scale, width, height)
{
	this->speed = initialSpeed;
}

void Snail::moveTowardsTarget(Character target)
{
	sf::Vector2f moveToTargetVector(target.getPosition().x - this->getPosition().x, target.getPosition().y - this->getPosition().y);

	if (abs(moveToTargetVector.x) > abs(moveToTargetVector.y)) // move horozontaly
	{
		if (moveToTargetVector.x > 0) // move right
		{
			this->movementDirection.x += 1;
		}
		else 
		{
			this->movementDirection.x -= 1; // move left
		}
	}
	else // move verticaly
	{
		if (moveToTargetVector.y > 0) // move down
		{
			this->movementDirection.y += 1;
		}
		else
		{
			this->movementDirection.y -= 1; // move up
		}
	}

	this->moveV();

}
