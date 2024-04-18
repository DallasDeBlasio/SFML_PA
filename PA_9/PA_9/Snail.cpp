#include "Snail.hpp"

Snail::Snail(int scale, int width, int height) : Character(scale, width, height)
{

}

void Snail::moveTowardsTarget(Character target)
{
	sf::Vector2f moveToTargetVector(this->getPosition().x - target.getPosition().x, this->getPosition().y - target.getPosition().y);
}
