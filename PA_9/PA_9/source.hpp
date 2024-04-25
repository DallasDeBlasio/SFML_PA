#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <iostream>
//#include <Windows.h>

//Vector Utility
float getVectorManitude(sf::Vector2f vector);//get the length of a vector from it's x and y travel
sf::Vector2f getUnitVector(sf::Vector2f vector);//return a vector of length 1 in the direction of provided vector