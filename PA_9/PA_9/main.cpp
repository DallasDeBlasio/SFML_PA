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

    //herotest\\\

    Character herotest(3, 16, 31);
    int one = 16;
    int two = 9;

    herotest.fillTextureList(4, 64, 57, true, 48, "Assets/tempHero.png");
    //herotest.firstTexture(4, one + 48, two + 48, true, 48, "Assets/tempHero.png");
    //sf::Texture heroTexture;
    //heroTexture.loadFromFile("Assets/tempHero.png",sf::IntRect(one + 48, two + 48, herotest.width, herotest.height));

    //herotest.setTexture(heroTexture);

    //herotest.set
    //herotest.setTextureRect(sf::IntRect(one + 48, two + 48, herotest.width, herotest.height));//+48 gets to the walking animations
    //herotest.setTexture(heroTexture);
    herotest.setPosition(herotest.width / 2.0f * herotest.mScale, herotest.height / 2.0f * herotest.mScale);

 
    int cycles = 0;//increment for every cycle of the window
    int walkframe = 0;//which frame the animation is in
    while (window.isOpen())
    {

        bool hasWalkFramed = false; //stop walkframe from being incremented twice if multiple keys pressed

        cycles++;

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
        //window.draw(herotest.hitbox);
        window.draw(herotest);// draw hero

        //these are the assumptions I'm making


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

        //if (cycles % 250 == 0)// walk cycle if statement
        //{
        //    if (hasWalkFramed)
        //    {
        //        walkframe++;
        //    }
        //    if (walkframe % 4 == 0)
        //    {
        //        walkframe = 0;
        //    }
        //    //herotest.setTextureRect(sf::IntRect(one + 48 * walkframe, two + 48, herotest.width, herotest.height));
        //    //herotest.setTexture(heroTexture);
        //}

        herotest.moveV();
    }
    return 14;

}