#pragma once
#include "source.hpp"
//#include <SFML/Graphics.hpp>
//#include <iostream>
#include "DialogBox.hpp"
#include "Character.hpp"
#include "Snail.hpp"

class MainMenu
{
public:
    // constructor
    MainMenu(double width, double height)
    {
        // load font for menu text
        if (!font.loadFromFile("Jersey20-Regular.ttf"))
        {
            std::cout << "Error Loading Menu Selections Font\n";
        }

     



        // display different menu options to screen

        // play option
        menu[0].setFont(font);
        menu[0].setFillColor(sf::Color::Blue);
        menu[0].setString("PLAY");
        menu[0].setCharacterSize(90);
        menu[0].setPosition(835, 300);

        // option option
        menu[1].setFont(font);
        menu[1].setFillColor(sf::Color::Blue);
        menu[1].setString("OPTIONS");
        menu[1].setCharacterSize(90);
        menu[1].setPosition(835, 400);

        // about option
        menu[2].setFont(font);
        menu[2].setFillColor(sf::Color::Blue);
        menu[2].setString("ABOUT");
        menu[2].setCharacterSize(90);
        menu[2].setPosition(835, 500);

        // exit option
        menu[3].setFont(font);
        menu[3].setFillColor(sf::Color::Blue);
        menu[3].setString("EXIT");
        menu[3].setCharacterSize(90);
        menu[3].setPosition(835, 600);

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


    void runPlayWindow() 
    { 
        sf::RenderWindow Play(sf::VideoMode(1920, 1080), "SNAIL GAME SNAIL GAME");
        DialogBox box("hello world\n>_<\nnext row\nanother row", sf::Vector2f(400,400));



        std::cout << "Opened runPlayWindow" << std::endl; 

        int windowLength = 1080;
        int windowWidth = 1920;

        sf::Texture mapTexture;
        mapTexture.loadFromFile("Assets/map.png");
        sf::Sprite room1;
        room1.setTexture(mapTexture);
        room1.setScale(10.f, 10.f);
        room1.setPosition(sf::Vector2f(0.f, -320.f));//offset on map Texture to fill the window with room1

        Character herotest(3, 16, 31);
        herotest.fillTextureList(4, 16, 57, true, 48, "Assets/tempHero.png");
        herotest.setPosition(windowWidth / 2.f + herotest.width / 2.0f * herotest.mScale, windowLength / 2.f + herotest.height / 2.0f * herotest.mScale);

        Snail bert(2, 32, 20);
        bert.fillTextureList(3, 0, 72, true, 32, "Assets/snail.png");
        bert.setPosition(bert.width / 2.0f * bert.mScale, bert.height / 2.0f * bert.mScale);

        Snail kurt(2, 32, 20, 0.15);
        kurt.fillTextureList(3, 0, 72, true, 32, "Assets/snail.png");
        kurt.setPosition(windowWidth - kurt.width / 2.0f * kurt.mScale, windowLength - kurt.height / 2.0f * kurt.mScale);

        int walkframe = 0;//which frame the animation is in

        //float standardMovement
    //
        sf::Clock timer;//credit martin
        sf::Time DeltaTime;//credit martin
        //DeltaTime.

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


        timer.restart();
        
        bool hasWalkFramed = false; //stop walkframe from being incremented twice if multiple keys pressed


        //wipe previous screen
        Play.clear();

        Play.draw(room1);//draw first room
        Play.draw(herotest);// draw hero
        Play.draw(bert);
        Play.draw(kurt);

        Play.display();//display drawings

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))//if s pressed
        {
            hasWalkFramed = true;
            herotest.movementDirection.y += 1;
            //herotest.setTexture(herotest.currentFrame->pNext->frame);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            hasWalkFramed = true;
            herotest.movementDirection.x += 1;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            hasWalkFramed = true;
            herotest.movementDirection.x -= 1;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            hasWalkFramed = true;
            herotest.movementDirection.y -= 1;
        }

        kurt.moveTowardsTarget(herotest, DeltaTime.asSeconds());
        bert.moveTowardsTarget(herotest, DeltaTime.asSeconds());
        herotest.moveV(DeltaTime.asSeconds());

        DeltaTime = timer.getElapsedTime();
        //std::cout << herotest.movmentSpeed << std::endl;
   

            //Play.draw(box.getBox());
            //Play.draw(box.getText());

            ////temp
            //Play.draw(box.getOriginPoint());

            //Play.display();
            //Play.clear();
        }
    }
    void runOptionsWindow()
    {
        sf::RenderWindow Options(sf::VideoMode(1920, 1080), "Options Window");

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
        sf::RenderWindow About(sf::VideoMode(1920, 1080), "About window");

        std::cout << "Opened runAboutWindow" << std::endl;

        sf::Text aboutTitle;
        sf::Font aboutFont;
        // load font
        if (!aboutFont.loadFromFile("Jersey20-Regular.ttf"))  
        {
            std::cout << "Error Loading about title Font\n";
        }
        aboutTitle.setCharacterSize(80);
        aboutTitle.setString("ABOUT");
        aboutTitle.setPosition(200, 50);
        aboutTitle.setFont(aboutFont); 

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
            About.draw(aboutTitle);
            About.display();
            About.clear();
        }
    }

	
    void mainMenuWindow()
    {
        // window for main menu
        sf::RenderWindow menu(sf::VideoMode(1920, 1080), "Main Menu (use arrow keys)", sf::Style::Default); 
        MainMenu mainMenu(menu.getSize().x, menu.getSize().y);

        // background
        sf::RectangleShape menuBackground;
        menuBackground.setSize(sf::Vector2f(1920, 1080));
        sf::Texture menuTexture;
        menuTexture.loadFromFile("battleback1.png");
        menuBackground.setTexture(&menuTexture);

        // game title

        sf::Text title;
        sf::Font titleFont;
        if (!titleFont.loadFromFile("BungeeSpice-Regular.ttf")) 
        {
            std::cout << "Error Loading Title Font\n";
        }
        title.setString("SNAIL RUN");
        title.setPosition(625, 100);
        title.setCharacterSize(120);
        title.setFont(titleFont);
        

 /*       sf::Sprite title;
        sf::Texture titleTexture;
        titleTexture.loadFromFile("game_title.png");
        title.setTexture(titleTexture);
        title.setPosition(100, 100);*/

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
                    menu.draw(title);

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