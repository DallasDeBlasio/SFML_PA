#include "source.hpp"

double getVectorManitude(sf::Vector2f vector)
{
	return sqrt(vector.x * vector.x + vector.y * vector.y);
}

sf::Vector2f getUnitVector(sf::Vector2f vector)
{
	sf::Vector2f returnVector(vector.x/getVectorManitude(vector),vector.y/getVectorManitude(vector));
	return returnVector;
}
