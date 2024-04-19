#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "MainMenu.hpp"
#include "DialogBox.hpp"

int main()
{

	sf::RenderWindow window(sf::VideoMode(960, 720), "Main Menu (use arrow keys)", sf::Style::Default); 
	MainMenu mainMenu(window.getSize().x, window.getSize().y); 

	mainMenu.mainMenuWindow();
	return 0;
}
