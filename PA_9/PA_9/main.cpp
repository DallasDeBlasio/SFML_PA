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

    sf::Vector2f origin(0, 0);

    sf::Sprite room1;
    room1.setTexture(texture);
    room1.setScale(10.f, 10.f);
    origin.y = -320.f;
    room1.setPosition(origin);

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
        window.display();




    }
    //loud noises
    return 0;

    //test
}