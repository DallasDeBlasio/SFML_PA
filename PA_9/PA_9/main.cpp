#include "source.hpp"
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


//
//
//int main()
//{
//    int windowLength = 1080;
//    int windowWidth = 1920;
//
//   //sf::RenderWindow window(sf::VideoMode(windowWidth, windowLength), "SFML works!");
//
//
//    sf::Texture mapTexture;
//    mapTexture.loadFromFile("Assets/map.png");
//    sf::Sprite room1;
//    room1.setTexture(mapTexture);
//    room1.setScale(10.f, 10.f);
//    room1.setPosition(sf::Vector2f(0.f,-320.f));//offset on map Texture to fill the window with room1
//
//
//    Character herotest(3, 16, 31);
//    herotest.fillTextureList(4, 16, 57, true, 48, "Assets/tempHero.png");
//    herotest.setPosition(windowWidth / 2.f + herotest.width / 2.0f * herotest.mScale, windowLength / 2.f + herotest.height / 2.0f * herotest.mScale);
//
//    Snail bert(2, 32, 20);
//    bert.fillTextureList(3, 0, 72, true, 32, "Assets/snail.png");
//    bert.setPosition(bert.width / 2.0f * bert.mScale, bert.height / 2.0f * bert.mScale); 
//
//    Snail kurt(2, 32, 20, 0.15);
//    kurt.fillTextureList(3, 0, 72, true, 32, "Assets/snail.png");
//    kurt.setPosition(windowWidth - kurt.width / 2.0f * kurt.mScale,windowLength - kurt.height / 2.0f * kurt.mScale);
// 
//    int walkframe = 0;//which frame the animation is in
//
//    //float standardMovement
//
//    sf::Clock timer;//credit martin
//    sf::Time DeltaTime;//credit martin
//    //DeltaTime.
//    while (window.isOpen())
//    {
//        timer.restart();
//        
//        bool hasWalkFramed = false; //stop walkframe from being incremented twice if multiple keys pressed
//
//        //close the window
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        //wipe previous screen
//        window.clear();
//
//        window.draw(room1);//draw first room
//        window.draw(herotest);// draw hero
//        window.draw(bert);
//        window.draw(kurt);
//
//        window.display();//display drawings
//
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))//if s pressed
//        {
//            hasWalkFramed = true;
//            herotest.movementDirection.y += 1;
//            //herotest.setTexture(herotest.currentFrame->pNext->frame);
//        }
//
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//        {
//            hasWalkFramed = true;
//            herotest.movementDirection.x += 1;
//        }
//
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//        {
//            hasWalkFramed = true;
//            herotest.movementDirection.x -= 1;
//        }
//
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//        {
//            hasWalkFramed = true;
//            herotest.movementDirection.y -= 1;
//        }
//
//        kurt.moveTowardsTarget(herotest, DeltaTime.asSeconds());
//        bert.moveTowardsTarget(herotest, DeltaTime.asSeconds());
//        herotest.moveV(DeltaTime.asSeconds());
//
//        DeltaTime = timer.getElapsedTime();
//        //std::cout << herotest.movmentSpeed << std::endl;
//    }
//    return 14;
//
//}
