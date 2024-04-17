#include "source.hpp"



int main()
{
    int windowWidth = 960;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowWidth), "SFML works!");

    sf::CircleShape movementVector(15.f);
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
    int heroWidth = 16;
    int heroHeight = 31;//

    //48 difference in height 

    Character herotest;
    herotest.setTextureRect(sf::IntRect(one + 48, two + 48, heroWidth, heroHeight));//+48 gets to the walking animations
    herotest.setTexture(heroTexture);
    herotest.setPosition(0.f, 0.f);

    float heroScale = 2.f;
    herotest.setScale(heroScale, heroScale);


    //hitbox information
    sf::FloatRect herotestbounds = herotest.getGlobalBounds();
    sf::RectangleShape herotestboundsDrawable(herotestbounds.getSize());

 
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
        window.draw(herotest);// draw hero
        window.display();//display drawings

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))//if s pressed
        {
            if (cycles % 250 == 0)// walk cycle if statement
            {
                if (!hasWalkFramed)
                {
                    walkframe++;
                }
                if (walkframe % 4 == 0)
                {
                    walkframe = 0;
                }
                herotest.setTextureRect(sf::IntRect(one + 48 * walkframe, two + 48, heroWidth, heroHeight));
                herotest.setTexture(heroTexture);
                hasWalkFramed = true;

            }



            //if (herotest.getPosition().y + heroHeight * heroScale < windowWidth)//boundry check //times 2 because of scale
            //{
            //    //herotest.move(0.f, 0.1f);
            //}

            herotest.movementDirection.y += 1;
            std::cout << herotest.movementDirection.y<<std::endl;

            herotestbounds = herotest.getGlobalBounds();
            herotestboundsDrawable.setSize(herotestbounds.getSize());
            herotestboundsDrawable.setPosition(herotestbounds.getPosition());

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            //std::cout << "fuck";
            //std::cout << walkframe % 100 << std::endl;
            if (cycles % 250 == 0)
            {
                if (!hasWalkFramed)
                {
                    walkframe++;
                }
                if (walkframe % 4 == 0)
                {
                    walkframe = 0;
                }
                //std::cout << "fuck";
                herotest.setTextureRect(sf::IntRect(one + 48 * walkframe, two + 48, heroWidth, heroHeight));
                herotest.setTexture(heroTexture);
                hasWalkFramed = true;

            }
            if (herotest.getPosition().x + heroWidth * heroScale < windowWidth)//times 2 because of scale

            {
               // herotest.move(0.1f, 0.f);
            }

            herotestbounds = herotest.getGlobalBounds();
            herotestboundsDrawable.setSize(herotestbounds.getSize());
            herotestboundsDrawable.setPosition(herotestbounds.getPosition());

            if (herotest.getScale().x < 0)
            {
                herotest.scale(-1.f, 1.f);
                //herotest.move(-heroWidth * heroScale, 0.f);
            }

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            //std::cout << "fuck";
            //std::cout << walkframe % 100 << std::endl;
            if (cycles % 250 == 0)
            {
                if (!hasWalkFramed)
                {
                    walkframe++;
                }
                if (walkframe % 4 == 0)
                {
                    walkframe = 0;
                }
                //std::cout << "fuck";
                herotest.setTextureRect(sf::IntRect(one + 48 * walkframe, two + 48, heroWidth, heroHeight));
                herotest.setTexture(heroTexture);
                hasWalkFramed = true;

            }
            //std::cout << herotest.getPosition().x << std::endl;
            if(herotest.getPosition().x - heroWidth * heroScale > 0)
            {
                //herotest.move(-0.1f, 0.f);
            }

            herotestbounds = herotest.getGlobalBounds();
            herotestboundsDrawable.setSize(herotestbounds.getSize());
            herotestboundsDrawable.setPosition(herotestbounds.getPosition());

            if (herotest.getScale().x > 0)
            {
                herotest.scale(-1.f, 1.f);
                //herotest.move(heroWidth * heroScale, 0.f);

            }

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            //std::cout << "fuck";
            //std::cout << walkframe % 100 << std::endl;
            if (cycles % 250 == 0)
            {
                if (!hasWalkFramed)
                {
                    walkframe++;
                }
                if (walkframe % 4 == 0)
                {
                    walkframe = 0;
                }
                //std::cout << "fuck";
                herotest.setTextureRect(sf::IntRect(one + 48 * walkframe, two + 48, heroWidth, heroHeight));
                herotest.setTexture(heroTexture);
                hasWalkFramed = true;

            }
            if (herotest.getPosition().y > 0)
            {
                //herotest.move(0.f, -0.1f);
            }

            herotestbounds = herotest.getGlobalBounds();
            herotestboundsDrawable.setSize(herotestbounds.getSize());
            herotestboundsDrawable.setPosition(herotestbounds.getPosition());

            herotest.moveV();
            
        }


    }
    //loud noises
    //std::cout << i;
    //std::cout << getUnitVector(sf::Vector2f(1.f, 1.f)).x;
    return 14;

    //test
}