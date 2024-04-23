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
        exit(0);  
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


    bool runPlayWindow() 
    { 

        sf::RenderWindow Play(sf::VideoMode(1920, 1080), "SNAIL GAME SNAIL GAME");
        DialogBox box("hello world\n>_<\nnext row\nanother row", sf::Vector2f(400,400));
        Play.clear();


        

        std::cout << "Opened runPlayWindow" << std::endl; 

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
        sf::Sprite spawnner;
        spawnner.setTexture(well);
        spawnner.setPosition(0, 0);
        spawnner.scale(3, 3);

        sf::Texture well1;
        well1.loadFromFile("Assets/map.png", sf::IntRect(833, 544, 30, 33));
        sf::Sprite spawnner1;
        spawnner1.setTexture(well1);
        spawnner1.setPosition(1920 - 30*3, 0);
        spawnner1.scale(3, 3);

        sf::Texture well2;
        well2.loadFromFile("Assets/map.png", sf::IntRect(833, 544, 30, 33));
        sf::Sprite spawnner2;
        spawnner2.setTexture(well2);
        spawnner2.setPosition(1920 - 30 * 3, 1080-33*3);
        spawnner2.scale(3, 3);

        sf::Texture well3;
        well3.loadFromFile("Assets/map.png", sf::IntRect(833, 544, 30, 33));
        sf::Sprite spawnner3;
        spawnner3.setTexture(well3);
        spawnner3.setPosition(0, 1080 - 33 * 3);
        spawnner3.scale(3, 3);
      


        Snail bert(2, 32, 20);
        //bert.fillTextureList(bert.currentFrame, 3, 0, 72, true, 32, "Assets/snail.png");
        bert.setPosition(bert.width / 2.0f * bert.mScale, bert.height / 2.0f * bert.mScale);
        //bert.setTexture(bert.currentFrame->frame);

        Snail kurt(2, 32, 20, 0.15);
        //kurt.fillTextureList(kurt.currentFrame, 3, 0, 72, true, 32, "Assets/snail.png");
        kurt.setPosition(windowWidth - kurt.width / 2.0f * kurt.mScale, windowLength - kurt.height / 2.0f * kurt.mScale);
        //kurt.setTexture(kurt.currentFrame->frame);

        int walkframe = 0;//which frame the animation is in


    //
        sf::Clock timer;//credit martin
        sf::Time DeltaTime;//credit martin
        //DeltaTime.
        float attackCoolDown = 0;


        characterList CharacterList;
        bool spawnEnemy = true;


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

        //Play.draw(herotest.hitbox);
        //herotest.weaponHitBox.setFillColor(sf::Color::Black);
        //Play.draw(herotest.weaponHitBox);
        if(herotest.currentHP> 0)
        {
            Play.draw(herotest);// draw hero
            Play.draw(herotest.mHealthBar.mBottomRectangle);

            Play.draw(herotest.mHealthBar.mTopRectangle);
        }
        if(bert.currentHP >0)
        {
            Play.draw(bert);
            Play.draw(bert.mHealthBar.mBottomRectangle);

            Play.draw(bert.mHealthBar.mTopRectangle); 

        }

        //Play.draw(kurt);
        Merge-Me-Daddy
        Play.draw(poop);
        Play.draw(spawnner);
        Play.draw(spawnner1);
        Play.draw(spawnner2);
        Play.draw(spawnner3);
        //Play.draw(poop);
        //Play.draw(CharacterList.pHead.)



        CharacterNode* pCur = CharacterList.pHead;

        while (pCur != nullptr)
        {
            //if (pCur->currentHP == 0)
            //{
            //    delete pCur
            //}
            //else
            //{
            Play.draw(*(pCur->mCharacter));
            //pCur->mCharacter->moveV(DeltaTime.asSeconds());
            //pCur->mCharacter.
            //}
            pCur = pCur->pNext;
        }


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
        

        if (attackCoolDown != 0)
        {
            attackCoolDown += DeltaTime.asSeconds();
            if (attackCoolDown > herotest.attackCoolDown)
            {
                attackCoolDown = 0;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if (attackCoolDown == 0)
            {
                herotest.attacking = true;
                herotest.setTexture(herotest.initalAttackNode->frame, true);
                herotest.setWeaponHitBox();
                

                attackCoolDown = 0.001;
            }
        }




        if (herotest.attacking)
        {
            if (attackCoolDown == 0 || attackCoolDown > herotest.attackLength)
            {
                herotest.attacking = false;
                herotest.setTexture(herotest.currentFrame->frame, true);
            }
            else
            {

                float i = 0;
                i = (float)herotest.attackLength / (float)herotest.numAttackFrames / 6;
                textureNode* pCurAttack = herotest.initalAttackNode;
                if (0.1 < attackCoolDown)
                {
                    pCurAttack = pCurAttack->pNext;
                    herotest.setTexture(pCurAttack->frame, true);
                }
                if (0.15 < attackCoolDown)
                {
                    pCurAttack = pCurAttack->pNext;
                    herotest.setTexture(pCurAttack->frame, true);
                }

            }
        }
        else
        {
            herotest.weaponHitBox.setPosition(sf::Vector2f(windowWidth, windowLength));
        }

        kurt.moveTowardsTarget(herotest, DeltaTime.asSeconds());
        
        bert.moveTowardsTarget(herotest, DeltaTime.asSeconds());

        if(!herotest.attacking)
        {
            herotest.moveV(DeltaTime.asSeconds());
        }

        DeltaTime = timer.getElapsedTime();


        if (bert.invinciblityTime == 0 && herotest.weaponHitBox.getGlobalBounds().intersects(bert.getGlobalBounds()))
        {
            sf::Vector2f bounceDirection(bert.getPosition().x - herotest.getPosition().x, bert.getPosition().y - herotest.getPosition().y);
            float bounceSpeed = getVectorManitude(bounceDirection);
            sf::Vector2f unitBounceDirection = getUnitVector(bounceDirection);
            bert.movementDirection = unitBounceDirection * 1000.f;
            bert.speed = 700;
            bert.currentHP -= herotest.mDamage;
            bert.invinciblityTime = 0.01f;   
        }

        if (herotest.invinciblityTime == 0 && bert.getGlobalBounds().intersects(herotest.hitbox.getGlobalBounds()))
        {
            sf::Vector2f bounceDirection(herotest.getPosition().x - bert.getPosition().x, herotest.getPosition().y - bert.getPosition().y);
            float bounceSpeed = getVectorManitude(bounceDirection);
            sf::Vector2f unitBounceDirection = getUnitVector(bounceDirection);
            herotest.movementDirection = unitBounceDirection * 100.f;
            herotest.speed = 700;
            herotest.currentHP -= bert.mDamage;
            herotest.invinciblityTime = 0.01f;

        }


        if (bert.invinciblityTime > 0.f)
        {
            if (bert.invinciblityTime > 0.25f)
            {
                bert.invinciblityTime = 0.f;
            }
            else
            {
                bert.invinciblityTime += DeltaTime.asSeconds();
            }
        }

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
            Character* pNewCharacter = new Snail(2, 32, 20, 0.15);
            //pNewCharacter.
            spawnEnemy = false;
            CharacterList.insertAtFront(pNewCharacter);
            pNewCharacter->setPosition(pNewCharacter->width * pNewCharacter->mScale / 2.f, pNewCharacter->height * pNewCharacter->mScale / 2.f);
            //Play.draw(pNewCharacter);

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
        return true;
    }
    void runTestWindow()
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
        sf::Text option1;
        sf::Font optionsFont;
        if (!optionsFont.loadFromFile("BungeeSpice-Regular.ttf"))
        {
            std::cout << "Error Loading about title Font\n";
        }

        //Options title settings-----------------------------------<<<
        optionsTitle.setCharacterSize(100);
        optionsTitle.setString("TESTING");
        optionsTitle.setPosition(725, 100);
        optionsTitle.setFont(optionsFont);
        //---------------------------------------------------------<<<

        //option1 settings-----------------------------------------<<<
        option1.setCharacterSize(30);
        option1.setString("");
        //---------------------------------------------------------<<<
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



            Options.draw(optionsBackground);
            Options.draw(optionsTitle);
            Options.draw(option1);
            Options.display();
            Options.clear();
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
        aboutText.setString("Made by Dallas DeBlasio, Connor Chase, James Richards-Perhatch, and Asa Fischer,\nwe present SNAIL RUN; our our final project for CptS_122. SNAIL RUN is a birds-eye\nview game where the player fights (or runs) from evil snails who want to\ntake away your vast riches and imortality. ***ill make a better description\nwhen more of the game is done***\n\nCONTROLS:\nMove with (WASD).\nNavigate menu with (WS) or UP and DOWN arrows.\nGo back to MainMenu (Esc)");
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

private:

	int menuSelected;
	sf::Font font;

	// shows 4 different menu options to screen
	sf::Text menu[4];

};