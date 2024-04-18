#include "source.hpp"
#include "Character.hpp"
#include "Snail.hpp"


int main()
{
    int windowWidth = 960;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowWidth), "SFML works!");

    sf::CircleShape movementVector(10.f);
    movementVector.setFillColor(sf::Color::White);

    sf::CircleShape movementUnitVector(7.5f);
    movementUnitVector.setFillColor(sf::Color::Black);

    sf::Texture mapTexture;
    mapTexture.loadFromFile("Assets/map.png");
    sf::Sprite room1;
    room1.setTexture(mapTexture);
    room1.setScale(10.f, 10.f);
    room1.setPosition(sf::Vector2f(0.f,-320.f));//offset on map Texture to fill the window with room1

    


    sf::Texture heroTexture;
    heroTexture.loadFromFile("Assets/tempHero.png");

    //offsets for the first character frame in the heroTexture
    int one = 16;
    int two = 9;


    //48 difference in height 

    Character herotest(3,16,31);
    herotest.setTextureRect(sf::IntRect(one + 48, two + 48, herotest.width, herotest.height));//+48 gets to the walking animations
    herotest.setTexture(heroTexture);
    herotest.setPosition(herotest.width / 2.0f * herotest.mScale, herotest.height / 2.0f * herotest.mScale);
    //herotest.setPosition(0,0);



    //hitbox information
    //sf::FloatRect herotestbounds = herotest.getGlobalBounds();
    //sf::RectangleShape herotestboundsDrawable(herotestbounds.getSize());

 
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
        window.draw(herotest.hitbox);
        window.draw(herotest);// draw hero
        //window.draw(herotest.movementVector);
        //window.draw(movementUnitVector);

        window.display();//display drawings

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))//if s pressed
        {
            hasWalkFramed = true;
            herotest.movementDirection.y += 1;
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

        if (cycles % 250 == 0)// walk cycle if statement
        {
            if (hasWalkFramed)
            {
                walkframe++;
            }
            if (walkframe % 4 == 0)
            {
                walkframe = 0;
            }
            herotest.setTextureRect(sf::IntRect(one + 48 * walkframe, two + 48, herotest.width, herotest.height));
            herotest.setTexture(heroTexture);
        }

        herotest.moveV();
    }
    return 14;

}