#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


#define maxMenu 4;

class MainMenu
{
public:
	// constructor
	MainMenu(double width, double height)
	{
		// load font for menu text
		if (!font.loadFromFile("Jersey20-Regular.ttf"))
		{
			std::cout << "Error Loading Font\n";
		}

		// display different menu options to screen

		// play option
		menu[0].setFont(font); 
		menu[0].setFillColor(sf::Color::Blue);
		menu[0].setString("PLAY");
		menu[0].setCharacterSize(70);
		menu[0].setPosition(400, 200);

		// option option
		menu[1].setFont(font); 
		menu[1].setFillColor(sf::Color::Blue);
		menu[1].setString("OPTIONS");
		menu[1].setCharacterSize(70);
		menu[1].setPosition(400, 300);

		// about option
		menu[2].setFont(font);
		menu[2].setFillColor(sf::Color::Blue);
		menu[2].setString("ABOUT");
		menu[2].setCharacterSize(70);
		menu[2].setPosition(400, 400);

		// exit option
		menu[3].setFont(font); 
		menu[3].setFillColor(sf::Color::Blue);
		menu[3].setString("EXIT");
		menu[3].setCharacterSize(70);
		menu[3].setPosition(400, 500);

		menuSelected = -1; 
	}
	~MainMenu()
	{

	}

	void draw(sf::RenderWindow& window)
	{
		for (int index = 0; index < 4; index++)

		{
			window.draw(menu[index]);
		}
	}
	void MoveUp()
	{
		if (menuSelected - 1 >= 0)
		{
			menu[menuSelected].setFillColor(sf::Color::Blue);

			menuSelected--;
			if (menuSelected == -1)
			{
				menuSelected = 2;
			}
			menu[menuSelected].setFillColor(sf::Color::Red);
		}
	}
	void MoveDown()
	{
		if (menuSelected + 1 <= 4)
		{
			menu[menuSelected].setFillColor(sf::Color::Blue);
			menuSelected++;
			if (menuSelected == 4)
			{
				menuSelected = 0;
			}
			menu[menuSelected].setFillColor(sf::Color::Red);
		}
	}

	int menuPressed()
	{
		return menuSelected;
	}

	
private:

	int menuSelected;
	sf::Font font;

	// shows 4 different menu options to screen
	sf::Text menu[4];

};