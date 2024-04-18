#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "MainMenu.hpp"
#include "DialogBox.hpp"

int main()
{
    //DialogBox box("Hello World");
    DialogBox box;


    // window for main menu
    sf::RenderWindow menu(sf::VideoMode(960, 720), "Main Menu (use arrow keys)", sf::Style::Default);
    MainMenu mainMenu(menu.getSize().x, menu.getSize().y);

    // background
    sf::RectangleShape menuBackground;
    menuBackground.setSize(sf::Vector2f(960, 720));
    sf::Texture menuTexture;
    menuTexture.loadFromFile("tex_molten_iron_a_256.PNG");
    menuBackground.setTexture(&menuTexture); 

    while (menu.isOpen())
    {
        sf::Event event;   
        while (menu.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                menu.close();
            }
            if (event.type == sf::Event::KeyPressed) 
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    mainMenu.MoveUp();
                    break;
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    mainMenu.MoveDown();
                    break;
                }
                if (event.key.code == sf::Keyboard::Return)
                {
                    sf::RenderWindow Play(sf::VideoMode(960, 720), "SUPER AWESOME GAME");
                    sf::RenderWindow Options(sf::VideoMode(960, 720), "OPTIONS");
                    sf::RenderWindow About(sf::VideoMode(960, 720), "ABOUT");

                    int x = mainMenu.menuPressed();
                    if (x == 0)
                    {
                        while (Play.isOpen())
                        {
                            // GAME WINDOW --- GAME LOOP HERE 

                            sf::Event someEvent;
                            while (Play.pollEvent(someEvent))
                            {
                                if (someEvent.type == sf::Event::Closed)
                                {
                                    Play.close();
                                }
                                if (someEvent.type == sf::Event::KeyPressed)
                                {
                                    if (someEvent.key.code == sf::Keyboard::Escape)
                                    {
                                        Play.close();
                                    }
                                }
                            }
                            Play.draw(box.getBox());
                            Play.draw(box.getText());
                            Play.display();
                            Options.close();
                            About.close();
                            Play.clear();
                        }
                    }
                    if (x == 1)
                    {
                        while (Options.isOpen())
                        {
                            sf::Event someEvent; 
                            // OPTIONS WINDOW
                            while (Options.pollEvent(someEvent))
                            {
                                if (someEvent.type == sf::Event::Closed)
                                {
                                    Options.close();
                                }
                                if (someEvent.type == sf::Event::KeyPressed)
                                {
                                    if (someEvent.key.code == sf::Keyboard::Escape)
                                    {
                                        Options.close();
                                    }
                                }
                            }
                            Play.close();
                            Options.clear();
                            About.close();
                            Play.display();
                        }
                    }
                    if (x == 2)
                    {
                        while (About.isOpen())
                        {
                            sf::Event someEvent;
                            // ABOUT WINDOW
                            while (About.pollEvent(someEvent))
                            {
                                if (someEvent.type == sf::Event::Closed)
                                {
                                    About.close();
                                }
                                if (someEvent.type == sf::Event::KeyPressed)
                                {
                                    if (someEvent.key.code == sf::Keyboard::Escape)
                                    {
                                        About.close();
                                    }
                                }
                            }
                            Play.close();
                            Options.close();
                            About.clear();
                            About.display();
                        }
                    }
                    if (x == 3)
                    {
                        menu.close();
                        break;
                    }
                }
            }
            menu.clear();
            menu.draw(menuBackground); 
            mainMenu.draw(menu);
            menu.display(); 
        }
    }
}