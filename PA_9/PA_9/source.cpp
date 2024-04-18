#include "source.hpp"

double getVectorManitude(sf::Vector2f vector)
{
	return sqrt(vector.x * vector.x + vector.y * vector.y);
}

sf::Vector2f getUnitVector(sf::Vector2f vector)
{
	sf::Vector2f returnVector;
	if (getVectorManitude(vector) != 0)
	{
		returnVector.x = vector.x / getVectorManitude(vector);
		returnVector.y = vector.y / getVectorManitude(vector);
	}
	else
	{
		returnVector.x = 0;
		returnVector.y = 0;
	}
	return returnVector;
}
