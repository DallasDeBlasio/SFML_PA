#pragma once
#include "source.hpp"
//#include <SFML/Graphics.hpp>
//#include <iostream>
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
        float runTime = 0;
        float runTimeFinal = 0;
      //  std::string temp;
       // temp = runTime; 
        std::string temp = std::to_string(runTime);  

        sf::Text run;
        run.setString(temp); 
        sf::Font runFont;
        runFont.loadFromFile("DiaryOfAn8BitMage-lYDD.ttf");
        run.setFillColor(sf::Color::Red);
        run.setCharacterSize(50);
        run.setPosition(830, 10);
        run.setFont(runFont);

        srand((unsigned int)time(NULL));
        sf::RenderWindow Play(sf::VideoMode(1920, 1080), "SNAIL GAME SNAIL GAME");
       // DialogBox box("hello world\n>_<\nnext row\nanother row", sf::Vector2f(400,400));
        Play.clear();
        std::cout << "Opened runPlayWindow" << std::endl; 


        // start screen
        DialogBox startBox("Run From the Snails!!!", sf::Vector2f(550,60), 100);
        startBox.LoadFontFromFile("Creepster-Regular.ttf"); 
        //startBox.LoadFontFromFile("DiaryOfAn8BitMage-lYDD.ttf");


        //startBox.setTextSize(20);
        //int x = 0;
     /*   int R = 55;
        int B = 225;
        int G = 100;*/
        sf::Color textColor(55,225,100); 
        startBox.setTextColor(textColor);   
        startBox.setBoxColor(sf::Color::Transparent);



        //sf::Texture boxTexture;
        //boxTexture.loadFromFile("Wood Floor.png");
        //startBox.changeTexture(&boxTexture);

        //DialogBox startBox2("Run From the Snails!", sf::Vector2f(515, 510), 100);
        //startBox2.LoadFontFromFile("Creepster-Regular.ttf");
        ////startBox.LoadFontFromFile("DiaryOfAn8BitMage-lYDD.ttf");

        ////startBox.setTextSize(20);
        //sf::Color textColor2(101, 255, 0);
        //startBox2.setTextColor(textColor2);
        //startBox2.setBoxColor(sf::Color::Transparent);

        int windowLength = 1080;
        int windowWidth = 1920;

        sf::Texture mapTexture;
        mapTexture.loadFromFile("Assets/level1.png");
        sf::Sprite room1;
        room1.setTexture(mapTexture);
        room1.setScale(0.385f, 0.385f);
        room1.setPosition(sf::Vector2f(0.f, 0.f));//offset on map Texture to fill the window with room1

        Player herotest(3, 16, 31, 0.2);
        herotest.fillTextureList(herotest.currentFrame, 4, 16, 57, true, 48, "Assets/tempHero.png");
        herotest.setPosition(windowWidth / 2.f + herotest.width / 2.0f * herotest.mScale, windowLength / 2.f + herotest.height / 2.0f * herotest.mScale);
        herotest.setTexture(herotest.currentFrame->frame);
        herotest.fillTextureList(herotest.initalAttackNode, 3, 16, 297, herotest.width * 2, herotest.height, true, 48, "Assets/tempHero.png", false);
        //herotest.fillTextureList(herotest.initalAttackNode, 3, 16 * 2, 297, herotest.width, herotest.height, true, 48, "Assets/tempHero.png");


       // herotest.initalAttackNode = new textureNode();
        //herotest.initalAttackNode->frame.loadFromFile("Assets/tempHero.png", sf::IntRect(16+48, 297, 32, 31));

        sf::Texture newtexture;
        newtexture.loadFromFile("Assets/tempHero.png", sf::IntRect(16 + 48, 297, 16 * 2, 31));
        sf::Sprite poop;
        poop.setTexture(newtexture);
        poop.setPosition(100, 100);

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

        //Object spawnner;
        //spawnner.setTexture(well);
        //spawnner.setPosition(0, 0);
        //spawnner.scale(3, 3);

        ////sf::Texture well1;
        ////well1.loadFromFile("Assets/map.png", sf::IntRect(833, 544, 30, 33));
        //sf::Sprite spawnner1;
        //spawnner1.setTexture(well);
        //spawnner1.setPosition(1920 - 30*3, 0);
        //spawnner1.scale(3, 3);

        ////sf::Texture well2;
        ////well2.loadFromFile("Assets/map.png", sf::IntRect(833, 544, 30, 33));
        //sf::Sprite spawnner2;
        //spawnner2.setTexture(well);
        //spawnner2.setPosition(1920 - 30 * 3, 1080-33*3);
        //spawnner2.scale(3, 3);

        ////sf::Texture well3;
        ////well3.loadFromFile("Assets/map.png", sf::IntRect(833, 544, 30, 33));
        //sf::Sprite spawnner3;
        //spawnner3.setTexture(well);
        //spawnner3.setPosition(0, 1080 - 33 * 3);
        //spawnner3.scale(3, 3);

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
      


        //Snail bert(2, 32, 20);
        //bert.fillTextureList(bert.currentFrame, 3, 0, 72, true, 32, "Assets/snail.png");
        //bert.setPosition(bert.width / 2.0f * bert.mScale, bert.height / 2.0f * bert.mScale);
        //bert.setTexture(bert.currentFrame->frame);

        //Snail kurt(2, 32, 20, 0.15);
        //kurt.fillTextureList(kurt.currentFrame, 3, 0, 72, true, 32, "Assets/snail.png");
        //kurt.setPosition(windowWidth - kurt.width / 2.0f * kurt.mScale, windowLength - kurt.height / 2.0f * kurt.mScale);
        //kurt.setTexture(kurt.currentFrame->frame);

        int walkframe = 0;//which frame the animation is in


    //
        sf::Clock timer;//credit martin
        sf::Time DeltaTime;//credit martin
        //DeltaTime.
        //float attackCoolDown = 0;


        characterList CharacterList;
        bool spawnEnemy = true;
        float enemySpawnTimer = 0.f;

        while (Play.isOpen())
        {
            runTime = DeltaTime.asSeconds() + runTime;

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

            if (herotest.currentHP <= 0)
            {
                std::cout << "Player Died!" << std::endl;
                break;
            }

        timer.restart();
        
        bool hasWalkFramed = false; //stop walkframe from being incremented twice if multiple keys pressed


        //wipe previous screen
        Play.clear();
        
        Play.draw(room1);//draw first room
        Play.draw(rocky);
        Play.draw(rocky2);
        Play.draw(rocky3);
        Play.draw(poop);
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
        

        if (runTime < 5)
        {
            Play.draw(startBox.getBox());
            Play.draw(startBox.getText());
        }
       // Play.draw(startBox2.getBox());
       // Play.draw(startBox2.getText());

        //Play.draw(herotest.hitbox);
        //herotest.weaponHitBox.setFillColor(sf::Color::Black);
        //Play.draw(herotest.weaponHitBox);
        if(herotest.currentHP> 0)
        {
            //Play.draw(herotest.hitbox);
            Play.draw(herotest);// draw hero
            Play.draw(herotest.mHealthBar.mBottomRectangle);

            Play.draw(herotest.mHealthBar.mTopRectangle);
            if (herotest.attackTimer != 0)
            {
                Play.draw(herotest.coolDownBar);
            }
        }
        //if(bert.currentHP >0)
        //{
        //    Play.draw(bert);
        //    Play.draw(bert.mHealthBar.mBottomRectangle);

        //    Play.draw(bert.mHealthBar.mTopRectangle); 

        //}

        //Play.draw(kurt);
        //Merge-Me-Daddy

        //Play.draw(poop);
        //Play.draw(CharacterList.pHead.)



        CharacterNode* pCur = CharacterList.pHead;

        rocky.isColliding(rocky, herotest);
        rocky2.isColliding(rocky2, herotest);
        rocky3.isColliding(rocky3, herotest);
        spawnner.isColliding(spawnner, herotest);
        spawnner1.isColliding(spawnner1, herotest);
        spawnner2.isColliding(spawnner2, herotest);
        spawnner3.isColliding(spawnner3, herotest);

        while (pCur != nullptr)
        {
            rocky.isColliding(rocky, *(pCur->mCharacter));
            rocky2.isColliding(rocky2, *(pCur->mCharacter));
            rocky3.isColliding(rocky3, *(pCur->mCharacter));

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
            {
                pCur->mCharacter->currentHP = 0;
            }

            if (pCur->mCharacter->currentHP == 0)
            {
                CharacterNode* deleteMe = pCur;
                pCur = pCur->pNext;
                CharacterList.deleteCharacter(deleteMe->mCharacter);
            }
            else
            {
            Play.draw(*(pCur->mCharacter));
            Play.draw(pCur->mCharacter->mHealthBar.mBottomRectangle);
            Play.draw(pCur->mCharacter->mHealthBar.mTopRectangle);


            pCur->mCharacter->moveV(herotest,DeltaTime.asSeconds());
            pCur->mCharacter->interacts(herotest);
            herotest.interacts(*(pCur->mCharacter));

            if (pCur->mCharacter->invinciblityTime > 0.f)
            {
                if (pCur->mCharacter->invinciblityTime > 0.25f)
                {
                    pCur->mCharacter->invinciblityTime = 0.f;
                }
                else
                {
                    pCur->mCharacter->invinciblityTime += DeltaTime.asSeconds();
                }
            }


            
            pCur = pCur->pNext;

            }
           


        }
        //Play.draw(herotest.weaponHitBox);

        Play.display();//display drawings

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !herotest.attacking)//if s pressed
        {
            hasWalkFramed = true;
            herotest.movementDirection.y += 0.1 * DeltaTime.asSeconds();
            //herotest.setTexture(herotest.currentFrame->pNext->frame);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !herotest.attacking)
        {
            hasWalkFramed = true;
            herotest.movementDirection.x += 0.1 * DeltaTime.asSeconds();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !herotest.attacking)
        {
            hasWalkFramed = true;
            herotest.movementDirection.x -= 0.1 * DeltaTime.asSeconds();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !herotest.attacking)
        {
            hasWalkFramed = true;
            herotest.movementDirection.y -= 0.1 * DeltaTime.asSeconds();
        }
        

        if (herotest.attackTimer != 0)
        {
            herotest.attackTimer += DeltaTime.asSeconds();
            herotest.coolDownBar.setScale(sf::Vector2f(herotest.attackTimer / herotest.attackLength / 2, 1.f)); 
            herotest.coolDownBar.setPosition(sf::Vector2f(herotest.getPosition().x, herotest.getPosition().y + herotest.height * 1.75));

            if (herotest.attackTimer > herotest.attackCoolDown)
            {
                herotest.attackTimer = 0;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if (herotest.attackTimer == 0)
            {
                herotest.attacking = true;
                herotest.setTexture(herotest.initalAttackNode->frame, true);
                herotest.setWeaponHitBox();
                

                herotest.attackTimer = 0.001;
            }
        }





        if (herotest.attacking)
        {
            if (herotest.attackTimer == 0 || herotest.attackTimer > herotest.attackLength)
            {
                herotest.attacking = false;
                herotest.setTexture(herotest.currentFrame->frame, true);
            }
            else
            {

                float i = 0;
                i = (float)herotest.attackLength / (float)herotest.numAttackFrames / 6;
                textureNode* pCurAttack = herotest.initalAttackNode;
                if (0.1 < herotest.attackTimer)
                {
                    pCurAttack = pCurAttack->pNext;
                    herotest.setTexture(pCurAttack->frame, true);
                }
                if (0.15 < herotest.attackTimer)
                {
                    pCurAttack = pCurAttack->pNext;
                    herotest.setTexture(pCurAttack->frame, true);
                }

            }
        }
        else
        {
            herotest.weaponHitBox.setPosition(sf::Vector2f(windowWidth + herotest.weaponHitBox.getSize().x, windowLength + herotest.weaponHitBox.getSize().y));
        }

       // kurt.moveV(herotest, DeltaTime.asSeconds());
        
       // bert.moveV(herotest, DeltaTime.asSeconds());

        if(!herotest.attacking)
        {
            herotest.moveV(DeltaTime.asSeconds());
        }

        DeltaTime = timer.getElapsedTime();

        //herotest.interacts(bert);

        //bert.interacts(herotest);



 /*       if (bert.invinciblityTime > 0.f)
        {
            if (bert.invinciblityTime > 0.25f)
            {
                bert.invinciblityTime = 0.f;
            }
            else
            {
                bert.invinciblityTime += DeltaTime.asSeconds();
            }
        }*/

        if (herotest.invinciblityTime > 0.f)
        {
            if (herotest.invinciblityTime > 0.25f)
            {
                herotest.invinciblityTime = 0.f;
            }
            else
            {
                herotest.invinciblityTime += DeltaTime.asSeconds();
            }
        }


        //        Snail kurt(2, 32, 20, 0.15);

        if (spawnEnemy)
        {
            float snailSpeed = (rand() % 19    + 1) / 100.f;
            Character* pNewCharacter = new Snail(2, 32, 20, snailSpeed);
            //pNewCharacter.
            spawnEnemy = false;
            CharacterList.insertAtFront(pNewCharacter);
            float x = 0;//pNewCharacter->width * pNewCharacter->mScale / 2.f;
            float y = 0;//pNewCharacter->height * pNewCharacter->mScale / 2.f;
            pNewCharacter->X_and_Y_Spawn_Locations(x, y);
            pNewCharacter->setPosition(x,y);
            pNewCharacter->speed = 750;
            //pNewCharacter->movmentSpeed(700);


        }
        else
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

        
        //std::cout << herotest.movmentSpeed << std::endl;
   




        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        //{
        //    herotest.movementDirection.y = 0;
        //    herotest.movementDirection.x = -125;
        //    herotest.speed = 2000;
        //}
        
        //std::cout << herotest.movementDirection.x << ", " << herotest.movementDirection.y <<herotest.movementDirection.y << std::endl;
        //std::cout << herotest.speed << std::endl << std::endl;
        //st
            //Play.draw(box.getBox());
            //Play.draw(box.getText());

            ////temp
            //Play.draw(box.getOriginPoint());

            //Play.clear();
        }

   /*     sf::Color deathScreenColor(55, 55, 55);
        sf::RectangleShape deathScreen;
        deathScreen.setSize(sf::Vector2f(1920, 1080));
        deathScreen.setFillColor(deathScreenColor); */

        sf::Text deathScreen;
        sf::Font deathFont;
        deathFont.loadFromFile("Creepster-Regular.ttf");
        deathScreen.setFillColor(sf::Color::Red); 
        deathScreen.setFont(deathFont);
        deathScreen.setCharacterSize(200);
        deathScreen.setPosition(650, 300);
        deathScreen.setString("You Died");

        sf::Text blob;
        sf::Font blobFont;
        blobFont.loadFromFile("Creepster-Regular.ttf");
        blob.setFillColor(sf::Color::Red);
        blob.setFont(deathFont);
        blob.setCharacterSize(40);
        blob.setPosition(770, 550);
        blob.setString("Press Escape to continue");
     
        sf::Event deathEvent; 
        
       // while (Play.pollEvent(deathEvent)) 
        while (1 == 1)
        {
            while (!Play.pollEvent(deathEvent))
            {
                Play.draw(deathScreen);
                Play.draw(blob);
                Play.display();

                //if (deathEvent.key.code == sf::Event::KeyPressed) 
                //{
                //    break;
                ////}
            }
            if (deathEvent.key.code == sf::Keyboard::Escape) 
            { 
                break;
            }
        }
      // std::this_thread::sleep_for(std::chrono::seconds(1));
        Play.close(); 
        std::cout << "Closed runPlayWindow" << std::endl;
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