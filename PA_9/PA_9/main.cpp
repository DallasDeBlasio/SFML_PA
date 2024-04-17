#include "source.hpp"



int main()
{
    int windowWidth = 960;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowWidth), "SFML works!");
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
    // asa was here
    sf::CircleShape movementVector(10.f);
    movementVector.setFillColor(sf::Color::White);

    sf::Texture mapTexture;
    mapTexture.loadFromFile("Assets/map.png");

 /*   sf::Sprite sprite;
    sprite.setTexture(texture);*/

    //sf::Vector2f origin(0, 0);

    sf::Sprite room1;
    room1.setTexture(mapTexture);
    room1.setScale(10.f, 10.f);
    //origin.y = -320.f;
    room1.setPosition(sf::Vector2f(0.f,-320.f));

    

    //Character(const int& newDamage, const int& newHP, const sf::Vector2f & size, const sf::Vector2f & position, const sf::Vector2f & startIntRect, const sf::Texture texture);

    sf::Texture heroTexture;

    heroTexture.loadFromFile("Assets/tempHero.png");



    int one = 16;
    int two = 9;
    int heroWidth = 16;
    int heroHeight = 31;//

    //48 difference in height 

    Character herotest;
    herotest.setTextureRect(sf::IntRect(one + 48, two + 48, heroWidth, heroHeight));
    herotest.setTexture(heroTexture);
    herotest.setPosition(0.f, 0.f);

    float heroScale = 2.f;
    herotest.setScale(heroScale, heroScale);
    sf::FloatRect herotestbounds = herotest.getGlobalBounds();
    sf::RectangleShape herotestboundsDrawable(herotestbounds.getSize());


   // Character todd(15, 30, sf::Vector2f(30, 30), origin, sf::Vector2f(0, 0), hero);
    //Character todd(15, 30, sf::Vector2f(100, 100), sf::Vector2f(30, 30), sf::Vector2f(0, 0), hero);
   

    //todd.mRectangle.setFillColor(sf::Color::Black);


    int cycles = 0;
    int walkframe = 0;
    while (window.isOpen())
    {
        bool hasWalkFramed = false; //stop walkframe from being incremented twice if multiple keys pressed

        //if (!hasWalkFramed)
        //{
        //    std::cout << walkframe;
        //}

        cycles++;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(room1);
        //window.draw(todd.mRectangle);
        //window.draw(todd.mSprite);

        //window.draw(herotestboundsDrawable);
        window.draw(herotest);
        //while(!sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        //{ }
        //Sleep(1000);//we probably need a walking frames counter



        window.display();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
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
            if (herotest.getPosition().y + heroHeight * heroScale < windowWidth)//times 2 because of scale
            {
                //herotest.move(0.f, 0.1f);
            }

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

            herotest.move();
        }


    }
    //loud noises
    //std::cout << i;
    //std::cout << getUnitVector(sf::Vector2f(1.f, 1.f)).x;
    return 14;

    //test
}