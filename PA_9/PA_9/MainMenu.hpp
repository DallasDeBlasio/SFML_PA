#pragma once
#include "source.hpp"
//#include <SFML/Graphics.hpp>
//#include <iostream>
#include "DialogBox.hpp"
#include "Character.hpp"
#include "Snail.hpp"

#include <chrono>
#include <thread>
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
        menu[1].setString("TESTING");
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
        std::cout << "destroying main menu" << std::endl;
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

    /// <summary>
    /// returns the menu currently selected
    /// </summary>
    /// <returns>int</returns>
    int menuPressed()
    {
        return menuSelected;
    }


    bool runPlayWindow() 
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
        return true;
    }
    void runTestWindow() // *Note - runTestWindow used to be runOptionsWindow
    {
        sf::RenderWindow Options(sf::VideoMode(1920, 1080), "Options Window");
        std::cout << "Opened runOptionsWindow" << std::endl;

        //background-----------------------------------------------<<<
        sf::RectangleShape optionsBackground;
        optionsBackground.setSize(sf::Vector2f(1920, 1080));
        sf::Texture optionsTexture;
        optionsTexture.loadFromFile("battleback1.png");
        optionsBackground.setTexture(&optionsTexture);
        //---------------------------------------------------------<<<

        sf::Text optionsTitle;
        sf::Text test1;
        sf::Text test2;
        sf::Font optionsFont;
        sf::Text test1Result;
        sf::Text test2Result;

        if (!optionsFont.loadFromFile("BungeeSpice-Regular.ttf"))
        {
            std::cout << "Error Loading testing title Font\n";
        }

        //Options title settings-----------------------------------<<<
        optionsTitle.setCharacterSize(100);
        optionsTitle.setString("TESTING");
        optionsTitle.setPosition(725, 100);
        optionsTitle.setFont(optionsFont);
        //---------------------------------------------------------<<<

        //test1 settings-----------------------------------------<<<
        test1.setCharacterSize(40);
        test1.setString("Testing MoveUp(): ");
        test1.setPosition(500, 300);
        test1.setFont(optionsFont);
        //---------------------------------------------------------<<<
        //Test1 result settings------------------------------------<<<
        test1Result.setCharacterSize(40);
        test1Result.setString("Testing");
        test1Result.setFillColor(sf::Color::Blue);
        test1Result.setPosition(950, 300);
        test1Result.setFont(optionsFont); 
        //---------------------------------------------------------<<<
        //test2 settings-------------------------------------------<<<
        test2.setCharacterSize(40);
        test2.setString("Testing MoveDown(): ");
        test2.setPosition(500, 400);
        test2.setFont(optionsFont);
        //---------------------------------------------------------<<<
        //Test2 result settings------------------------------------<<<
        test2Result.setCharacterSize(40);
        test2Result.setString("Testing");
        test2Result.setFillColor(sf::Color::Blue);
        test2Result.setPosition(1020, 400);
        test2Result.setFont(optionsFont);
        //---------------------------------------------------------<<<

        int x = 0;

        while (Options.isOpen()) 
        {
            sf::Event someEvent;
            while (Options.pollEvent(someEvent))
            {
                if (someEvent.type == sf::Event::Closed)
                {
                    Options.close();
                    std::cout << "Closed runTestingWindow" << std::endl;
                }
                if (someEvent.type == sf::Event::KeyPressed)
                {
                    if (someEvent.key.code == sf::Keyboard::Escape)
                    {
                        Options.close();
                        std::cout << "Closed runTestingWindow" << std::endl;
                    }
                }
            }

          
            Options.draw(optionsBackground);
            Options.draw(optionsTitle);
            Options.draw(test1);
            Options.draw(test1Result);
            Options.draw(test2); 
            Options.draw(test2Result);
            Options.display();
            Options.clear();

            //so the test functions are ran only once
            if (x == 0)
            {
                std::string testingString("Testing");
                std::string testingDot(".");
                for (int i = 0; i < 4; i++)
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    testingString = testingString + testingDot; 

                    test1Result.setString(testingString);
                    test2Result.setString(testingString);

                    Options.draw(optionsBackground);
                    Options.draw(optionsTitle);
                    Options.draw(test1);
                    Options.draw(test1Result);
                    Options.draw(test2);
                    Options.draw(test2Result);
                    Options.display();
                    Options.clear();
                }
                // set result string to passed and color to green
                if (testMoveUp())
                {
                    test1Result.setString("PASSED");
                    test1Result.setFillColor(sf::Color::Green);
                }
                else // set result string to failed and color to red
                {
                    test1Result.setString("FAILED");
                    test1Result.setFillColor(sf::Color::Red);
                }
                if (testMoveDown()) 
                {
                    test2Result.setString("PASSED");
                    test2Result.setFillColor(sf::Color::Green);
                }
                else
                {
                    test2Result.setString("FAILED");
                    test2Result.setFillColor(sf::Color::Red);
                }

                x++;
            }
        }
    }
    void runAboutWindow()
    {
        sf::RenderWindow About(sf::VideoMode(1920, 1080), "About window");
        std::cout << "Opened runAboutWindow" << std::endl;

        sf::RectangleShape aboutBackground;
        aboutBackground.setSize(sf::Vector2f(1920, 1080));
        sf::Texture aboutTexture;
        aboutTexture.loadFromFile("battleback1.png");
        aboutBackground.setTexture(&aboutTexture); 

        //--------------------------------------------------------------------<<<
    // test and font settings for title
        sf::Text aboutTitle;
        sf::Font aboutFont;
        // load font
        if (!aboutFont.loadFromFile("BungeeSpice-Regular.ttf"))  
        {
            std::cout << "Error Loading about title Font\n";
        }
        aboutTitle.setCharacterSize(100);
        aboutTitle.setString("ABOUT");
        aboutTitle.setPosition(775, 100);
        aboutTitle.setFont(aboutFont); 
        //---------------------------------------------------------------------<<<
        // --------------------------------------------------------------------<<<
        // font and text setting for main block of text
        sf::Text aboutText;
        sf::Font aboutTextFont;
        if (!aboutTextFont.loadFromFile("BungeeSpice-Regular.ttf"))
        {
            std::cout << "Error Loading about title Font\n";
        }
        aboutText.setLineSpacing(1.5);
        aboutText.setCharacterSize(30);
        aboutText.setString("Made by Dallas DeBlasio, Connor Chase, James Richards-Perhatch, and Asa Fischer,\nwe present SNAIL RUN; our our final project for CptS_122. SNAIL RUN is a birds-eye\nview game where the player fights (or runs) from evil snails who want to\ntake away your vast riches and imortality.\n\nCONTROLS:\nMove (WASD).\nNavigate menu (WS) or UP and DOWN arrows.\nAttack (space)\nGo back to MainMenu (Esc)");
        aboutText.setPosition(200, 250);
        aboutText.setFont(aboutTextFont); 
        //---------------------------------------------------------------------<<<
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
            About.draw(aboutBackground);
            About.draw(aboutTitle);
            About.draw(aboutText);
            About.display();
            About.clear();
        }
    }

	
    void mainMenuWindow()
    {
        // window for main menu
        sf::RenderWindow menuWindow(sf::VideoMode(1920, 1080), "Main Menu (WASD or arrow keys)", sf::Style::Default); 
        MainMenu mainMenu(menuWindow.getSize().x, menuWindow.getSize().y);

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
        
        int x = 0;

        std::cout << "Opened mainMenuWindow" << std::endl;

        while (menuWindow.isOpen())
        {
            sf::Event event;
            while (menuWindow.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    menuWindow.close();
                    exit(0);
                }
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        mainMenu.MoveUp();
                        break;
                    }
                    if (event.key.code == sf::Keyboard::W)
                    {
                        mainMenu.MoveUp();
                        break;
                    }
                    if (event.key.code == sf::Keyboard::Down)
                    {
                        mainMenu.MoveDown();
                        break;
                    }
                    if (event.key.code == sf::Keyboard::S) 
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
                            runTestWindow(); 

                        }
                        if (x == 2)
                        {
                            runAboutWindow();
                         
                        }
                        if (x == 3)
                        {
                            menuWindow.close();
                            std::cout << "Exiting" << std::endl; 
                            exit(0);
                            break;
                        }
                    }

                }    
                    menuWindow.clear();
                    menuWindow.draw(menuBackground);
                    mainMenu.draw(menuWindow);
                    menuWindow.draw(title);
                    menuWindow.display();
            }
        }
    }

    void setMenuSelected(int newNum)
    {
        menuSelected = newNum;  
    }

    sf::Text getMenu(int num)
    {
        return menu[num];  
    }



private:

	int menuSelected;
	sf::Font font;

	// shows 4 different menu options to screen
	sf::Text menu[4];


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
};