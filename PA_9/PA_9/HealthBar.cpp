#include "HealthBar.hpp"

HealthBar::HealthBar()
{
	this->mBottomRectangle.setFillColor(sf::Color().White);
	this->mTopRectangle.setFillColor(sf::Color().Red);

	this->mBottomRectangle.setOutlineThickness(2.f);
	this->mBottomRectangle.setOutlineColor(sf::Color().White);

}
