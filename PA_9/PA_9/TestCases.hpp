#pragma once
#include "MainMenu.hpp"
#include <iostream>
#include "Character.hpp" 
#include "Snail.hpp"
#include "player.hpp"

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
		testCharacter.movementDirection = sf::Vector2f(1, 0);
		testCharacter.moveV(1);//should move testCharacter to position (2,0)
		testCharacter.movementDirection = sf::Vector2f(0, 1);
		testCharacter.moveV(1);//should move testCharacter to position (2,2)
		testCharacter.movementDirection = sf::Vector2f(1, 1);
		testCharacter.moveV(1);// should move testCharacter to position (2 + sqrt(2), 2 + sqrt(2))
		float x = testCharacter.getPosition().x;
		float y = testCharacter.getPosition().y;
		float expected_X = 2 + sqrt(2);
		float expected_Y = 2 + sqrt(2);

		if (x == expected_X && y == expected_Y)//should travel 2 + sqrt(2) in both the x and y direction
		{
			succeeded = true;
			//std::cout << "Yeah";
		}
		return succeeded;
	}

	//bool testSnailAttackPolymorphism(void)
	//{
	//	bool succeeded = false;
	//	Character* testSnail = new Snail(1, 4, 4);
	//	testSnail->setPosition(2,2);
	//	Player testPlayer(1, 4, 4, 0.2);
	//	testPlayer.setPosition(2, 2);
	//	bool initialTouching = testSnail->getGlobalBounds().intersects(testPlayer.getGlobalBounds());
	//	//std::cout << testSnail->getGlobalBounds().left << "," << testSnail->getGlobalBounds().left + testSnail->getGlobalBounds().width;
	//	std::cout << testPlayer.getGlobalBounds().width;
	//	testSnail->interacts(testPlayer);
	//	//if (initialTouching)
	//	//{
	//	//	std::cout << "Shit";
	//	//}
	//	bool finalTouching = testSnail->getGlobalBounds().intersects(testPlayer.getGlobalBounds());
	//	if (initialTouching && !initialTouching)
	//	{
	//		succeeded = true;
	//	}
	//	return succeeded;
	//}

		bool testSnailMovePolymorphism(void)
	{
		bool succeeded = false;
		Character* testSnail = new Snail(1, 4, 4 , 0.001);
		testSnail->setPosition(4,4);
		testSnail->movementDirection = sf::Vector2f(0, 0);//movement direction away from player
		Player testPlayer(1, 4, 4, 0.2);
		testPlayer.setPosition(10, 10);

		sf::Vector2f initialDistanceBetweenCharacterAndSnail(testPlayer.getPosition().x - testSnail->getPosition().x, testPlayer.getPosition().y - testSnail->getPosition().y);

		testSnail->moveV(testPlayer, 1);//if the polymorphism fails, then the snail will not move. If it works, the snail will get closer to the player

		sf::Vector2f finalDistanceBetweenCharacterAndSnail(testPlayer.getPosition().x - testSnail->getPosition().x, testPlayer.getPosition().y - testSnail->getPosition().y);

		//if the snail's moveV polymorphism works, inital distance should be larger than final distance since the testsnail should have moved towards the player
		if (getVectorManitude(initialDistanceBetweenCharacterAndSnail) > getVectorManitude(finalDistanceBetweenCharacterAndSnail))
		{
			succeeded = true;
		}

		return succeeded;
	}

		bool testVectorMagnitude(void)
		{
			bool succeeded = false;
			sf::Vector2f oneByOneVector(1, 1);
			float oneByOneExpectedMagnitude = sqrt(2);

			sf::Vector2f vectorWithMagnitdueFive(4, 3);
			float magnitudeFive = 5.f;
			if (getVectorManitude(oneByOneVector) == oneByOneExpectedMagnitude && getVectorManitude(vectorWithMagnitdueFive) == 5.f)
			{
				succeeded = true;
			}

			return succeeded;
		}

		bool testUnitVector(void)
		{
			bool succeeded = false;
			sf::Vector2f oneByOneVector(1, 1);
			sf::Vector2f oneByOneExpectedUnitVector(1.f/sqrt(2), 1.f/sqrt(2));


			sf::Vector2f fourByThreeVector(4, 3);
			sf::Vector2f fourByThreeExpectedUnitVector(4.f/5.f, 3.f / 5.f);
			if (getUnitVector(oneByOneVector).x == oneByOneExpectedUnitVector.x && getUnitVector(oneByOneVector).y == oneByOneExpectedUnitVector.y && getUnitVector(fourByThreeVector).x == fourByThreeExpectedUnitVector.x && getUnitVector(fourByThreeVector).y == fourByThreeExpectedUnitVector.y)
			{
				succeeded = true;
			}

			return succeeded;
		}

		bool testVectorUtility(void)
		{
			bool succeeded = false;

			if (testUnitVector() && testVectorMagnitude())
			{
				succeeded = true;
			}

			return succeeded;
		}

private:


};