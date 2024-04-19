#include "source.hpp"
#include "Character.hpp"
#include "Snail.hpp"


int main()
{
    int windowWidth = 960;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowWidth), "SFML works!");


    sf::Texture mapTexture;
    mapTexture.loadFromFile("Assets/map.png");
    sf::Sprite room1;
    room1.setTexture(mapTexture);
    room1.setScale(10.f, 10.f);
    room1.setPosition(sf::Vector2f(0.f,-320.f));//offset on map Texture to fill the window with room1


    Character herotest(3, 16, 31);
    herotest.fillTextureList(4, 16, 57, true, 48, "Assets/tempHero.png");
    herotest.setPosition(herotest.width / 2.0f * herotest.mScale, herotest.height / 2.0f * herotest.mScale);

    Snail bert(2, 32, 20);
    bert.fillTextureList(3, 0, 72, true, 32, "Assets/snail.png");
    bert.setPosition(bert.width / 2.0f * bert.mScale, bert.height / 2.0f * bert.mScale); 

    Snail kurt(2, 32, 20);
    kurt.fillTextureList(3, 0, 72, true, 32, "Assets/snail.png");
    kurt.setPosition(960 - kurt.width / 2.0f * kurt.mScale,960 - kurt.height / 2.0f * kurt.mScale);
 
    int walkframe = 0;//which frame the animation is in
    while (window.isOpen())
    {

        bool hasWalkFramed = false; //stop walkframe from being incremented twice if multiple keys pressed

        //close the window
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //wipe previous screen
        window.clear();

        window.draw(room1);//draw first room
        window.draw(herotest);// draw hero
        window.draw(bert);
        window.draw(kurt);

        window.display();//display drawings

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

        kurt.moveTowardsTarget(herotest);
        bert.moveTowardsTarget(herotest);
        herotest.moveV();
    }
    return 15;

}