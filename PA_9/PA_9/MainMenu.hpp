#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "DialogBox.hpp"



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

    /// <summary>
    /// runs main menu plus other windows
    /// </summary>
    //void mainMenuAll()
    //{
    //   // DialogBox box("Hello World");
    //    // DialogBox box;



    //    // window for main menu
    //    sf::RenderWindow menu(sf::VideoMode(960, 720), "Main Menu (use arrow keys)", sf::Style::Default);
    //    MainMenu mainMenu(menu.getSize().x, menu.getSize().y);

    //    // background
    //    sf::RectangleShape menuBackground;
    //    menuBackground.setSize(sf::Vector2f(960, 720));
    //    sf::Texture menuTexture;
    //    menuTexture.loadFromFile("tex_molten_iron_a_256.PNG");
    //    menuBackground.setTexture(&menuTexture);


    //    while (menu.isOpen())
    //    {
    //        sf::Event event;
    //        while (menu.pollEvent(event))
    //        {
    //            if (event.type == sf::Event::Closed)
    //            {
    //                menu.close();
    //            }
    //            if (event.type == sf::Event::KeyPressed)
    //            {
    //                if (event.key.code == sf::Keyboard::Up)
    //                {
    //                    mainMenu.MoveUp();
    //                    break;
    //                }
    //                if (event.key.code == sf::Keyboard::Down)
    //                {
    //                    mainMenu.MoveDown();
    //                    break;
    //                }
    //                if (event.key.code == sf::Keyboard::Return)
    //                {
    //                    sf::RenderWindow Play(sf::VideoMode(960, 720), "SUPER AWESOME GAME");
    //                    sf::RenderWindow Options(sf::VideoMode(960, 720), "OPTIONS");
    //                    sf::RenderWindow About(sf::VideoMode(960, 720), "ABOUT");

    //                    int x = mainMenu.menuPressed();
    //                    if (x == 0)
    //                    {
    //                        while (Play.isOpen())
    //                        {
    //                            // GAME WINDOW --- GAME LOOP HERE 

    //                            sf::Event someEvent;
    //                            while (Play.pollEvent(someEvent))
    //                            {
    //                                if (someEvent.type == sf::Event::Closed)
    //                                {
    //                                    Play.close();
    //                                }
    //                                if (someEvent.type == sf::Event::KeyPressed)
    //                                {
    //                                    if (someEvent.key.code == sf::Keyboard::Escape)
    //                                    {
    //                                        Play.close();
    //                                    }
    //                                }
    //                            }
    //                           // Play.draw(box.getBox());
    //                            //Play.draw(box.getText());
    //                            Play.display();
    //                            Options.close();
    //                            About.close();
    //                            Play.clear();
    //                        }
    //                    }
    //                    if (x == 1)
    //                    {
    //                        while (Options.isOpen())
    //                        {
    //                            sf::Event someEvent;
    //                            // OPTIONS WINDOW
    //                            while (Options.pollEvent(someEvent))
    //                            {
    //                                if (someEvent.type == sf::Event::Closed)
    //                                {
    //                                    Options.close();
    //                                }
    //                                if (someEvent.type == sf::Event::KeyPressed)
    //                                {
    //                                    if (someEvent.key.code == sf::Keyboard::Escape)
    //                                    {
    //                                        Options.close();
    //                                    }
    //                                }
    //                            }
    //                            Play.close();
    //                            Options.clear();
    //                            About.close();
    //                            Play.display();
    //                        }
    //                    }
    //                    if (x == 2)
    //                    {
    //                        while (About.isOpen())
    //                        {
    //                            sf::Event someEvent;
    //                            // ABOUT WINDOW
    //                            while (About.pollEvent(someEvent))
    //                            {
    //                                if (someEvent.type == sf::Event::Closed)
    //                                {
    //                                    About.close();
    //                                }
    //                                if (someEvent.type == sf::Event::KeyPressed)
    //                                {
    //                                    if (someEvent.key.code == sf::Keyboard::Escape)
    //                                    {
    //                                        About.close();
    //                                    }
    //                                }
    //                            }
    //                            Play.close();
    //                            Options.close();
    //                            About.clear();
    //                            About.display();
    //                        }
    //                    }
    //                    if (x == 3)
    //                    {
    //                        menu.close();
    //                        break;
    //                    }
    //                }
    //            }
    //            menu.clear();
    //            menu.draw(menuBackground);
    //            mainMenu.draw(menu);
    //            menu.display();
    //        }
    //    }
    //}

    void runPlayWindow() 
    { 
        sf::RenderWindow Play(sf::VideoMode(960, 720), "SNAIL GAME SNAIL GAME");
        DialogBox box("hello world\n>_<\nnext row\nanother row", sf::Vector2f(400,400));



        std::cout << "Opened runPlayWindow" << std::endl; 

        while (Play.isOpen())
        {
            sf::Event someEvent;
            while (Play.pollEvent(someEvent))
            {
                if (someEvent.type == sf::Event::Closed)
                {
                    Play.close();
                    std::cout << "Closed runPlayWindow" << std::endl;
                }
                if (someEvent.type == sf::Event::KeyPressed)
                {
                    if (someEvent.key.code == sf::Keyboard::Escape)
                    {
                        Play.close();
                        std::cout << "Closed runPlayWindow" << std::endl;
                    }
                }
            }

            // GAME WINDOW --- GAME LOOP HERE 


            Play.draw(box.getBox());
            Play.draw(box.getText());

            //temp
            Play.draw(box.getOriginPoint());

            Play.display();
            Play.clear();
        }
    }
    void runOptionsWindow()
    {
        sf::RenderWindow Options(sf::VideoMode(960, 720), "Options Window");

        std::cout << "Opened runOptionsWindow" << std::endl;

        while (Options.isOpen()) 
        {
            sf::Event someEvent;
            while (Options.pollEvent(someEvent))
            {
                if (someEvent.type == sf::Event::Closed)
                {
                    Options.close();
                    std::cout << "Closed runOptionsWindow" << std::endl;
                }
                if (someEvent.type == sf::Event::KeyPressed)
                {
                    if (someEvent.key.code == sf::Keyboard::Escape)
                    {
                        Options.close();
                        std::cout << "Closed runOptionsWindow" << std::endl;
                    }
                }
            }
            Options.display();
            Options.clear();
        }
    }
    void runAboutWindow()
    {
        sf::RenderWindow About(sf::VideoMode(960, 720), "About window");

        std::cout << "Opened runAboutWindow" << std::endl;

        while (About.isOpen()) 
        {
            sf::Event someEvent;
            while (About.pollEvent(someEvent))
            {
                if (someEvent.type == sf::Event::Closed)
                {
                    About.close();
                    std::cout << "Closed runAboutWindow" << std::endl;
                }
                if (someEvent.type == sf::Event::KeyPressed)
                {
                    if (someEvent.key.code == sf::Keyboard::Escape)
                    {
                        About.close();
                        std::cout << "Closed runAboutWindow" << std::endl;
                    }
                }
            }
            About.display();
            About.clear();
        }
    }

	
    void mainMenuWindow()
    {
        // window for main menu
        sf::RenderWindow menu(sf::VideoMode(960, 720), "Main Menu (use arrow keys)", sf::Style::Default); 
        MainMenu mainMenu(menu.getSize().x, menu.getSize().y);

        // background
        sf::RectangleShape menuBackground;
        menuBackground.setSize(sf::Vector2f(960, 720));
        sf::Texture menuTexture;
        menuTexture.loadFromFile("tex_molten_iron_a_256.PNG");
        menuBackground.setTexture(&menuTexture);

        int x = 0;

        std::cout << "Opened mainMenuWindow" << std::endl;

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
                         x = mainMenu.menuPressed();
                        // Play selected. open play window 
                        if (x == 0)
                        {
                            runPlayWindow(); 
                            //menu.close();
                        }
                        if (x == 1)
                        {
                            runOptionsWindow();
                        }
                        if (x == 2)
                        {
                            runAboutWindow();
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

private:

	int menuSelected;
	sf::Font font;

	// shows 4 different menu options to screen
	sf::Text menu[4];

   
};