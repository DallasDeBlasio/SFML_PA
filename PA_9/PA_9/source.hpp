#pragma once

//C : \Panic\SFML - 2.6.1\include //general
//C:\Panic\SFML - 2.6.1\lib //not general


//Dallas DeBlasio C++ general: C:\Users\dalla\OneDrive\Desktop\CPTS 121\SFML-2.6.1\include
//Dallas DeBlasio linker: C:\Users\dalla\OneDrive\Desktop\CPTS 121\SFML-2.6.1\lib


//Connor c++ general: C:\Users\cchas\OneDrive\Desktop\cpts122\SFML-2.6.1-windows-vc17-64-bit\SFML-2.6.1\include
//connor linker: C:\Users\cchas\OneDrive\Desktop\cpts122\SFML-2.6.1-windows-vc17-64-bit\SFML-2.6.1\lib

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
//#include <Windows.h>

//Vector Utility
float getVectorManitude(sf::Vector2f vector);
sf::Vector2f getUnitVector(sf::Vector2f vector);

//extern int windowWidth = 960;
//
//extern float standardMovement = 1000;


//things i'd like to see change, how not to hardcode window size in seperate functions


//what we need to do that I'm skipping
//{
//destructors, copy constructor, and equals operator for any class with allocated memory

//}