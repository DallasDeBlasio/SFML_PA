#pragma once
#include "MainMenu.hpp"
#include <iostream>
#include "Character.hpp"

class TestCases
{
public:
	TestCases()
	{

	}

	// READ ME
	// make sure your test functions return bool. Connor will take care of diplaying messages to the screen 


	/// <summary>
	/// tests MoveUp() function
	/// </summary>
	/// <param name=""></param>
	/// <returns>true or false</returns>
//bool testMoveUp(void)
//{		
//	MainMenu test(500, 500);
//	test.setMenuSelected(1);
//	test.MoveUp();
//	sf::Text testText = test.getMenu(test.menuPressed());

//	if (test.menuPressed() == 0)
//	{
//		if (testText.getFillColor() == sf::Color::Red)
//		{
//			std::cout << "testMoveUp: true" << std::endl; 
//			return true;
//		}
//	}
//	std::cout << "testMoveUp: false" << std::endl;
//	return false;
//}

	/// <summary>
	/// tests MoveDown() function
	/// </summary>
	/// <param name=""></param>
	/// <returns>true or false</returns>
//bool testMoveDown(void)
//{
//	MainMenu test(500, 500);
//	test.setMenuSelected(1);
//	test.MoveDown();
//
//	sf::Text testText = test.getMenu(test.menuPressed());
//
//	if (test.menuPressed() == 2)
//	{
//		if (testText.getFillColor() == sf::Color::Red)
//		{
//			std::cout << "testMoveDown: true" << std::endl;
//			return true;
//		}
//	}
//	std::cout << "testMoveDown: false" << std::endl;
//	return false;
//}


	bool testCharacterVectorMovement(void)
	{
		bool succeeded = false;
		Character testCharacter(1,2,2,0.001); //0.001 multiplied by speed factor should create a speed of 2
		testCharacter.setPosition(sf::Vector2f(0, 0));
		//testCharacter.movmentSpeed = 2;
		testCharacter.movementDirection = sf::Vector2f(1, 0);
		testCharacter.moveV(1);
		//std::cout << testCharacter.getPosition().x << std::endl;
		testCharacter.movementDirection = sf::Vector2f(0, 1);
		testCharacter.moveV(1);
		testCharacter.movementDirection = sf::Vector2f(1, 1);
		testCharacter.moveV(1);
		//std::cout << testCharacter.getPosition().x << std::endl;
		//std::cout << 2 + sqrt(2) << std::endl;
		float x = testCharacter.getPosition().x;
		float y = testCharacter.getPosition().y;
		float expected_X = 2 + sqrt(2);
		float expected_Y = 2 + sqrt(2);

		if (x == expected_X && y == expected_Y)//should travel 2 + sqrt(2) in both the x and y direction
		{
			succeeded = true;
			std::cout << "Yeah";
		}
		return succeeded;
	}

private:


};