#pragma once
#include "source.hpp"
#include "DialogBox.hpp"
#include "Character.hpp"
#include "Snail.hpp"
#include "player.hpp"
#include "characterNode.hpp"
#include "characterList.hpp"
#include "object.hpp"

#include <chrono>
#include <thread>
class MainMenu
{
public:
    // constructor
    MainMenu(double width, double height)
    {
        // load font for menu text
        if (!font.loadFromFile("Assets/Jersey20-Regular.ttf"))
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

        // testing option
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
    // moves menu selection up and changes color of selectd option to red
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
    // moves menu selection down and changes color of selectd option to red

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

    // runs the window that the game loop is in. 
    bool runPlayWindow() 
    { 
        // variables used by the program

        int u = 0;
        float runTime = 0;
        float runTimeFinal = 0;
        std::string temp = std::to_string(runTime);  

        sf::Text run;
        run.setString(temp); 
        sf::Font runFont;
        runFont.loadFromFile("Assets/DiaryOfAn8BitMage-lYDD.ttf");
        run.setFillColor(sf::Color::Red);
        run.setCharacterSize(50);
        run.setPosition(830, 10);
        run.setFont(runFont);

        srand((unsigned int)time(NULL));
        sf::RenderWindow Play(sf::VideoMode(1920, 1080), "SNAIL GAME SNAIL GAME");
        Play.clear();
        std::cout << "Opened runPlayWindow" << std::endl; 


        // start screen
        DialogBox startBox("Run From the Snails!!!", sf::Vector2f(550,60), 100);
        startBox.LoadFontFromFile("Assets/Creepster-Regular.ttf"); 

        sf::Color textColor(55,225,100); 
        startBox.setTextColor(textColor);   
        startBox.setBoxColor(sf::Color::Transparent);

        int windowLength = 1080;
        int windowWidth = 1920;

        sf::Texture mapTexture;
        mapTexture.loadFromFile("Assets/level1.png");
        sf::Sprite room1;
        room1.setTexture(mapTexture);
        room1.setScale(0.385f, 0.385f);
        room1.setPosition(sf::Vector2f(0.f, 0.f));//offset on map Texture to fill the window with room1

        Player herotest(3, 16, 31, 0.2);

        //makes all of the wells
        sf::Texture well;
        well.loadFromFile("Assets/map.png", sf::IntRect(833, 544, 30, 33));
        Object spawnner;
        spawnner.spawnWell1(well);
        Object spawnner2;
        spawnner2.spawnWell2(well);
        Object spawnner3;
        spawnner3.spawnWell3(well);
        Object spawnner1;
        spawnner1.spawnWell4(well);
        sf::Texture wellith;
        wellith.loadFromFile("Assets/map.png", sf::IntRect(833, 544, 30, 33));

        //makes all the rocks
        sf::Texture rock;
        rock.loadFromFile("Assets/map.png", sf::IntRect(633, 250, 100, 100));
        Object rocky;
        rocky.spawnTree(rock);
        Object rocky2;
        rocky2.spawnTree(rock);
        Object rocky3;
        rocky3.spawnTree(rock);
        sf::Texture rockith;
        rockith.loadFromFile("Assets/map.png", sf::IntRect(260, 299, 19, 14));
      


        int walkframe = 0;//which frame the animation is in


    //
        //this makes it so that the physics are less dependent on frame rate
        //obviously if the frame rate is super low, then less imputs will be read
        sf::Clock timer;//credit martin
        sf::Time DeltaTime;//credit martin
 

        characterList CharacterList;
        bool spawnEnemy = true;
        float enemySpawnTimer = 0.f;

        // game loop
        while (Play.isOpen())
        {
            // calculate total run time for program
            runTime = DeltaTime.asSeconds() + runTime;

            // detects if game window was closed
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

            if (herotest.getCurrentHP() <= 0)
            {
                std::cout << "Player Died!" << std::endl;
            }

        timer.restart();
        
        bool hasWalkFramed = false; //stop walkframe from being incremented twice if multiple keys pressed


        //wipe previous screen
        Play.clear();
        
        Play.draw(room1);//draw first room

        //draw all the objects that cant be passed through
        Play.draw(rocky);
        Play.draw(rocky2);
        Play.draw(rocky3);
        Play.draw(spawnner);
        Play.draw(spawnner1);
        Play.draw(spawnner2);
        Play.draw(spawnner3);

        //temp = runTime;
        temp = std::to_string(runTime); 
        run.setString(temp);

        Play.draw(run);
        // below play.draw() functions added by connor
         
        int x = runTime; 
        
        // stops drawing the starting text after roughly 5 seconds
        if (runTime < 5)
        {
            Play.draw(startBox.getBox());
            Play.draw(startBox.getText());
        }
       
        Play.draw(herotest);// draw hero
        Play.draw(herotest.mHealthBar.mBottomRectangle);//draw hp bar base
        if(herotest.getCurrentHP() > 0) //if player is alive
        {
            Play.draw(herotest.mHealthBar.mTopRectangle);
        }
        if (!herotest.canAttack())
        {
            Play.draw(herotest.coolDownBar);
        }

        //all the checks for collisions
        rocky.isColliding(rocky, herotest);
        rocky2.isColliding(rocky2, herotest);
        rocky3.isColliding(rocky3, herotest);
        spawnner.isColliding(spawnner, herotest);
        spawnner1.isColliding(spawnner1, herotest);
        spawnner2.isColliding(spawnner2, herotest);
        spawnner3.isColliding(spawnner3, herotest);


        //Traverse Character List
        CharacterNode* pCur = CharacterList.get_pHead();

        while (pCur != nullptr)
        {
            //checks for collisions with the snail
            rocky.isColliding(rocky, *(pCur->mCharacter));
            rocky2.isColliding(rocky2, *(pCur->mCharacter));
            rocky3.isColliding(rocky3, *(pCur->mCharacter));


            if (pCur->mCharacter->getCurrentHP() == 0)//if 0 hp delete character
            {
                CharacterNode* deleteMe = pCur;
                pCur = pCur->pNext;
                CharacterList.deleteCharacter(deleteMe->mCharacter);
            }
            else
            {
            Play.draw(*(pCur->mCharacter));
            if (u == 0)
            {
                Play.draw(pCur->mCharacter->mHealthBar.mBottomRectangle);
                Play.draw(pCur->mCharacter->mHealthBar.mTopRectangle);
            }

            pCur->mCharacter->moveV(herotest,DeltaTime.asSeconds());
            pCur->mCharacter->interacts(herotest);//attack hero if intersects
            herotest.interacts(*(pCur->mCharacter));//get attacked if hero hits character

            pCur->mCharacter->invincibilityManager(DeltaTime.asSeconds());


            
            pCur = pCur->pNext;

            }
           


        }

        Play.display();//display drawings

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !herotest.isAttacking())//read downward input
        {
            if(herotest.movementDirection.y<=0.1 * DeltaTime.asSeconds())
            {
                hasWalkFramed = true;
                herotest.movementDirection.y += 0.1 * DeltaTime.asSeconds();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !herotest.isAttacking())//read right input
        {
            if (herotest.movementDirection.x <= 0.1 * DeltaTime.asSeconds())
            {
                hasWalkFramed = true;
                herotest.movementDirection.x += 0.1 * DeltaTime.asSeconds();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !herotest.isAttacking())//read left input
        {
            if (herotest.movementDirection.x >= -0.1 * DeltaTime.asSeconds())
            {
                hasWalkFramed = true;
                herotest.movementDirection.x -= 0.1 * DeltaTime.asSeconds();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !herotest.isAttacking())//read up input
        {
            if (herotest.movementDirection.y >= -0.1 * DeltaTime.asSeconds())
            {
                hasWalkFramed = true;
                herotest.movementDirection.y -= 0.1 * DeltaTime.asSeconds();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))//start attacking
        {
            herotest.startAttack();
        }

        herotest.playerAttackManager(DeltaTime.asSeconds());//takes care of all the behind the scenes attacking information

        if(!herotest.isAttacking())//move when not attacking
        {
            herotest.moveV(DeltaTime.asSeconds());
        }

        herotest.invincibilityManager(DeltaTime.asSeconds());

        if (spawnEnemy)//spawn enemy
        {
            float snailSpeed = (rand() % 19    + 1) / 100.f;
            Character* pNewCharacter = new Snail(2, 32, 20, snailSpeed);
            spawnEnemy = false;
            CharacterList.insertAtFront(pNewCharacter);
            float x = 0;
            float y = 0;
            pNewCharacter->X_and_Y_Spawn_Locations(x, y);
            pNewCharacter->setPosition(x,y);


        }
        else//spawn an enemy every 10 seconds
        {
            if (enemySpawnTimer > 10)
            {
                spawnEnemy = true;
                enemySpawnTimer = 0.f;
            }
            else
            {
                enemySpawnTimer += DeltaTime.asSeconds();
            }
        }






 
        // used to let the program run 2 or so extra frames after the player dies, otherwise the players health will show non-empty
        if (herotest.getCurrentHP() <= 0)
        {
            u++;
        }
        if (herotest.getCurrentHP() <= 0 && u > 2)
        {
            // set text and font settnig for the death screen text
            // variable are created within the if statement so that they are created only once and dont slow the game down
            sf::Text deathScreen;
            sf::Font deathFont;
            deathFont.loadFromFile("Assets/Creepster-Regular.ttf");
            deathScreen.setFillColor(sf::Color::Red);
            deathScreen.setFont(deathFont);
            deathScreen.setCharacterSize(200);
            deathScreen.setPosition(650, 300);
            deathScreen.setString("You Died");

            sf::Text blob;
            sf::Font blobFont;
            blobFont.loadFromFile("Assets/Creepster-Regular.ttf");
            blob.setFillColor(sf::Color::Red);
            blob.setFont(deathFont);
            blob.setCharacterSize(40);
            blob.setPosition(770, 550);
            blob.setString("Press Escape to continue");

            sf::Event deathEvent;

                Play.draw(deathScreen);
                Play.draw(blob);
                Play.display();

            // program enters an infinite loop to dispaly the death screen until the user hits escape
            // this also stops the game from running when the player dies
                while (1 == 1)
                {
                    while (Play.pollEvent(deathEvent))
                    {
                        if (deathEvent.key.code == sf::Keyboard::Escape)
                        {
                            Play.close();
                            break;
                        }
                    }
                    if (!Play.isOpen())
                    {
                        break;
                    }
                }
        }

        DeltaTime = timer.getElapsedTime();// update time elapsed per while loop cycle
        
        }
        std::cout << "Closed runPlayWindow" << std::endl;
        return true;
    }

    void runTestWindow() // *Note - runTestWindow used to be runOptionsWindow, so some of the names may not fit the context
    {
        sf::RenderWindow Options(sf::VideoMode(1920, 1080), "Options Window");
        std::cout << "Opened runOptionsWindow" << std::endl;

        //background-----------------------------------------------<<<
        sf::RectangleShape optionsBackground;
        optionsBackground.setSize(sf::Vector2f(1920, 1080));
        sf::Texture optionsTexture;
        optionsTexture.loadFromFile("Assets/battleback1.png");
        optionsBackground.setTexture(&optionsTexture);
        //---------------------------------------------------------<<<

        sf::Text optionsTitle;
        sf::Text test1;
        sf::Text test2;
        sf::Text test3;
        sf::Text test4;
        sf::Text test5;

        sf::Font optionsFont;
        sf::Text test1Result;
        sf::Text test2Result;
        sf::Text test3Result;
        sf::Text test4Result;
        sf::Text test5Result;



        if (!optionsFont.loadFromFile("Assets/BungeeSpice-Regular.ttf"))
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
        //test 3 settings------------------------------------------<<<
        test3.setCharacterSize(40);
        test3.setString("testSnailMovePolymorphism(): ");
        test3.setPosition(500, 500);
        test3.setFont(optionsFont);

        test3Result.setCharacterSize(40);
        test3Result.setString("Testing");
        test3Result.setFillColor(sf::Color::Blue); 
        test3Result.setPosition(1283, 500);
        test3Result.setFont(optionsFont); 
        //---------------------------------------------------------<<<
        //test 4 settings------------------------------------------<<<
        test4.setCharacterSize(40);
        test4.setString("testVectorUtility(): ");
        test4.setPosition(500, 600);
        test4.setFont(optionsFont);

        test4Result.setCharacterSize(40);
        test4Result.setString("Testing");
        test4Result.setFillColor(sf::Color::Blue);
        test4Result.setPosition(1030, 600);
        test4Result.setFont(optionsFont);
        //---------------------------------------------------------<<<
        //test 5 settings------------------------------------------<<<
        test5.setCharacterSize(40);
        test5.setString("testCharacterVectorMovement(): ");
        test5.setPosition(500, 700);
        test5.setFont(optionsFont);

        test5Result.setCharacterSize(40);
        test5Result.setString("Testing");
        test5Result.setFillColor(sf::Color::Blue);
        test5Result.setPosition(1325, 700);
        test5Result.setFont(optionsFont);
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
            Options.draw(test3); 
            Options.draw(test3Result); 
            Options.draw(test4);
            Options.draw(test4Result);
            Options.draw(test5);
            Options.draw(test5Result);
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
                    test3Result.setString(testingString);
                    test4Result.setString(testingString);
                    test5Result.setString(testingString);


                    Options.draw(optionsBackground);
                    Options.draw(optionsTitle);
                    Options.draw(test1);
                    Options.draw(test1Result);
                    Options.draw(test2);
                    Options.draw(test2Result);
                    Options.draw(test3);
                    Options.draw(test3Result);
                    Options.draw(test4);
                    Options.draw(test4Result);
                    Options.draw(test5); 
                    Options.draw(test5Result);
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
                if (testSnailMovePolymorphism()) 
                {
                    test3Result.setString("PASSED");
                    test3Result.setFillColor(sf::Color::Green);
                }
                else // set result string to failed and color to red
                {
                    test3Result.setString("FAILED");
                    test3Result.setFillColor(sf::Color::Red);
                }
                if (testVectorUtility()) 
                {
                    test4Result.setString("PASSED");
                    test4Result.setFillColor(sf::Color::Green);
                }
                else // set result string to failed and color to red
                {
                    test4Result.setString("FAILED");
                    test4Result.setFillColor(sf::Color::Red);
                }
                if (testCharacterVectorMovement()) 
                {
                    test5Result.setString("PASSED");
                    test5Result.setFillColor(sf::Color::Green);
                }
                else // set result string to failed and color to red
                {
                    test5Result.setString("FAILED");
                    test5Result.setFillColor(sf::Color::Red);
                }
                x++;
            }
        }
    }
    // runs the window displaying about information
    void runAboutWindow()
    {
        sf::RenderWindow About(sf::VideoMode(1920, 1080), "About window");
        std::cout << "Opened runAboutWindow" << std::endl;

        sf::RectangleShape aboutBackground;
        aboutBackground.setSize(sf::Vector2f(1920, 1080));
        sf::Texture aboutTexture;
        aboutTexture.loadFromFile("Assets/battleback1.png");
        aboutBackground.setTexture(&aboutTexture); 

        //--------------------------------------------------------------------<<<
    // test and font settings for title
        sf::Text aboutTitle;
        sf::Font aboutFont;
        // load font
        if (!aboutFont.loadFromFile("Assets/BungeeSpice-Regular.ttf"))  
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
        if (!aboutTextFont.loadFromFile("Assets/BungeeSpice-Regular.ttf"))
        {
            std::cout << "Error Loading about title Font\n";
        }
        aboutText.setLineSpacing(1.5);
        aboutText.setCharacterSize(30);
        aboutText.setString("Made by Dallas DeBlasio, Connor Chase, James Richards-Perhatch, and Asa Fischer,\nwe present SNAIL RUN; our our final project for CptS_122. SNAIL RUN is a birds-eye\nview game where the player fights (or runs) from evil snails who want to\ntake away your vast riches and imortality.\n\nCONTROLS:\nMove (WASD).\nNavigate menu (WS) or UP and DOWN arrows.\nAttack (space)\nGo back to MainMenu (Esc)");
        aboutText.setPosition(200, 250);
        aboutText.setFont(aboutTextFont); 
        //---------------------------------------------------------------------<<<
        // loops the text to be displayed 
        while (About.isOpen()) 
        {
            sf::Event someEvent;
            // detects when to close the program 
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

	// runs the main menu. from this window, the user can select other windows to open from.
    // other windows always go back to the main menu window
    void mainMenuWindow()
    {
        // window for main menu
        sf::RenderWindow menuWindow(sf::VideoMode(1920, 1080), "Main Menu (WASD or arrow keys)", sf::Style::Default); 
        MainMenu mainMenu(menuWindow.getSize().x, menuWindow.getSize().y);

        // background
        sf::RectangleShape menuBackground;
        menuBackground.setSize(sf::Vector2f(1920, 1080));
        sf::Texture menuTexture;
        menuTexture.loadFromFile("Assets/battleback1.png");
        menuBackground.setTexture(&menuTexture);

        // game title

        sf::Text title;
        sf::Font titleFont;
        if (!titleFont.loadFromFile("Assets/BungeeSpice-Regular.ttf")) 
        {
            std::cout << "Error Loading Title Font\n";
        }
        title.setString("SNAIL RUN");
        title.setPosition(625, 100);
        title.setCharacterSize(120);
        title.setFont(titleFont);
        
        int x = 0;

        std::cout << "Opened mainMenuWindow" << std::endl;
        // calls move up and down to highlight the users selection in red
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
                        // testing selected. open test window
                        if (x == 1)
                        {
                            runTestWindow(); 

                        }
                        // about selected. opens about window 
                        if (x == 2)
                        {
                            runAboutWindow();
                         
                        }
                        // exit selected
                        // exits the program
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

    // sets the menu selection
    void setMenuSelected(int newNum)
    {
        menuSelected = newNum;  
    }

    //returns menu selection
    sf::Text getMenu(int num)
    {
        return menu[num];  
    }



private:

    // the menu selected
	int menuSelected;
    // font used for the menu options
	sf::Font font;

	// shows 4 different menu options to screen
	sf::Text menu[4];


    /// <summary>
/// tests MoveUp() function -- written by connor
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
/// tests MoveDown() function -- written by connor
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

    bool testSnailMovePolymorphism(void)   // -- written by james
    {
        bool succeeded = false;
        Character* testSnail = new Snail(1, 4, 4, 0.001);
        testSnail->setPosition(4, 4);
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

    bool testVectorUtility(void)  //jidhsilfghdfghksjldfghlkjdfhg
    {
        bool succeeded = false;

        if (testUnitVector() && testVectorMagnitude())
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
        sf::Vector2f oneByOneExpectedUnitVector(1.f / sqrt(2), 1.f / sqrt(2));


        sf::Vector2f fourByThreeVector(4, 3);
        sf::Vector2f fourByThreeExpectedUnitVector(4.f / 5.f, 3.f / 5.f);
        if (getUnitVector(oneByOneVector).x == oneByOneExpectedUnitVector.x && getUnitVector(oneByOneVector).y == oneByOneExpectedUnitVector.y && getUnitVector(fourByThreeVector).x == fourByThreeExpectedUnitVector.x && getUnitVector(fourByThreeVector).y == fourByThreeExpectedUnitVector.y)
        {
            succeeded = true;
        }

        return succeeded;
    }

    bool testCharacterVectorMovement(void)  
    {
        bool succeeded = false;
        Character testCharacter(1, 2, 2, 0.001); //0.001 multiplied by speed factor should create a speed of 2
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
};