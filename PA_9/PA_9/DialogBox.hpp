#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

/// <summary>
/// Generates border/box around text. Use inherited functions from sf::Text to change position of box, change color of text, etc..
/// Must call window.draw(box.getBox) and window.draw(box.getText) before displaying.
/// </summary>
class DialogBox : public sf::Text, sf::RectangleShape   
{
public:

	//DialogBox()
	//{
	//	stringToDisplay = sf::String(); 
	//	text = sf::Text(); 
	//	font = sf::Font(); 
	//	bounds = sf::FloatRect(); 
	//	box = sf::RectangleShape(); 
	//}

	DialogBox()
	{
		font.loadFromFile("Jersey20-Regular.ttf");
		text.setFont(font);
		text.setFillColor(sf::Color::Blue);
		text.setString("Default String blah\n bdskhfdhfsa;lkjdflsd");
		text.setCharacterSize(40);
		text.setPosition(400, 200);


		bounds = text.getLocalBounds();  
		position = text.getPosition();


		box.setPosition((position.x - 9), position.y); 
		box.setSize(sf::Vector2f((bounds.width + 20), (bounds.height + 23)));
		box.setFillColor(sf::Color::Red);

	}
	DialogBox(sf::String stringToDisplay)
	{
		font.loadFromFile("Jersey20-Regular.ttf");
		text.setFont(font);
		text.setFillColor(sf::Color::Blue);
		text.setString(stringToDisplay); 
		text.setCharacterSize(40);
		text.setPosition(400, 200);


		bounds = text.getGlobalBounds(); 

		
		box.setPosition(text.getPosition()); 
		box.setSize(sf::Vector2f(bounds.width, bounds.height));
		box.setFillColor(sf::Color::Red);
		
	}

	sf::RectangleShape getBox()
	{
		return box;
	}
	sf::Text getText()
	{
		return text; 
	}

	void LoadFontFromFile(const std::string &filePath)
	{
		font.loadFromFile(filePath); 
	}


private:

	sf::RectangleShape box;
	sf::FloatRect bounds; 
	sf::String stringToDisplay; 
	sf::Text text;
	sf::Font font;
	sf::Vector2f position;
};