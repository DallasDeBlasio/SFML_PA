#include "source.hpp"



int main()
{
    int windowWidth = 960;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowWidth), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    // asa was here


    sf::Texture texture;
    if (!texture.loadFromFile("Assets/map.png"))

    {
        return 0;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::Vector2f origin(0, 0);

    sf::Sprite room1;
    room1.setTexture(texture);
    room1.setScale(10.f, 10.f);
    origin.y = -320.f;
    room1.setPosition(origin);

    //Character(const int& newDamage, const int& newHP, const sf::Vector2f & size, const sf::Vector2f & position, const sf::Vector2f & startIntRect, const sf::Texture texture);

    sf::Texture hero;

    hero.loadFromFile("Assets/tempHero.png");



    int one = 16;
    int two = 9;
    int three = 16;
    int four = 31;

    //48 difference in height 

    sf::Sprite herotest;
    herotest.setTextureRect(sf::IntRect(one+48, two+48, three, four));
    herotest.setTexture(hero);
    herotest.setPosition(0.f, 0.f);
    herotest.setScale(10.f, 10.f);
    sf::FloatRect herotestbounds = herotest.getGlobalBounds();
    sf::RectangleShape herotestboundsDrawable(herotestbounds.getSize());


   // Character todd(15, 30, sf::Vector2f(30, 30), origin, sf::Vector2f(0, 0), hero);
    Character todd(15, 30, sf::Vector2f(100, 100), sf::Vector2f(30, 30), sf::Vector2f(0, 0), hero);
   

    todd.mRectangle.setFillColor(sf::Color::Black);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(room1);
        window.draw(todd.mRectangle);
        window.draw(todd.mSprite);

        window.draw(herotestboundsDrawable);
        window.draw(herotest);



        window.display();




    }
    //loud noises
    return 14;

    //test
}