#pragma once
#include "MainMenu.hpp"
#include <iostream>
class TestCases
{
public:
	TestCases()
	{

	}

	// READ ME
	// make sure your test functions return bool. Connor will take care of diplaying messages to the screen 

	void runTestCases()
	{

	}

	/// <summary>
	/// tests MoveUp() function
	/// </summary>
	/// <param name=""></param>
	/// <returns>true or false</returns>
	bool testMoveUp(void)
	{		
		MainMenu test(500, 500);
		test.setMenuSelected(1);
		test.MoveUp();
		sf::Text testText = test.getMenu(test.menuPressed());

		if (test.menuPressed() == 0)
		{
			if (testText.getFillColor() == sf::Color::Red)
			{
				std::cout << "testMoveUp: true" << std::endl; 
				return true;
			}
		}
		std::cout << "testMoveUp: false" << std::endl;
		return false;
	}

	/// <summary>
	/// tests MoveDown() function
	/// </summary>
	/// <param name=""></param>
	/// <returns>true or false</returns>
	bool testMoveDown(void)
	{
		MainMenu test(500, 500);
		test.setMenuSelected(1);
		test.MoveDown();

		sf::Text testText = test.getMenu(test.menuPressed());

		if (test.menuPressed() == 2)
		{
			if (testText.getFillColor() == sf::Color::Red)
			{
				std::cout << "testMoveDown: true" << std::endl;
				return true;
			}
		}
		std::cout << "testMoveDown: false" << std::endl;
		return false;
	}

private:


};