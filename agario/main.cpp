#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>

int main()
{
    int             ScreenX = 1200;
    int             ScreenY = 800;

    int             mapSizeX = ScreenX * 8;
    int             mapSizeY = ScreenY * 8;

    sf::Time        Fps = sf::seconds(0.f);
    int             tmp = 0;

    float           sizeShape = 20.f;
    float           speedBall = 0.0014f;
    unsigned int    nbPoints = (ScreenX / 10) * (ScreenY / 10);

    bool            isPlaying = true;
    float           sizePoint = 4.f;

    std::vector<sf::CircleShape>    points;

    sf::Clock                       clock;

    sf::RenderWindow                window(sf::VideoMode(ScreenX, ScreenY), "Agario");

    sf::CircleShape                 shape(sizeShape);

    //sf::Text                        fps_str;

    srand(time(NULL));

    shape.setPosition(ScreenX / 2, ScreenY / 2);
    shape.setFillColor(sf::Color::Green);
    shape.setOutlineThickness(6);
    shape.setOutlineColor(sf::Color(250, 150, 100));

    for (unsigned int i = 0; i < nbPoints; ++i)
    {
        points.push_back(sf::CircleShape(sizePoint));
        points[i].setFillColor(sf::Color::Green);
        if (rand() % 2 == 0)
            points[i].setPosition(rand() % mapSizeX, rand() % mapSizeY);
        else if (rand() % 3 == 0)
            points[i].setPosition(rand() % mapSizeX * -1, rand() % mapSizeY);       
        else if (rand() % 5 == 0)
            points[i].setPosition(rand() % mapSizeX, rand() % mapSizeY * -1);
        else if (rand() % 9 == 0)
            points[i].setPosition(rand() % mapSizeX * -1, rand() % mapSizeY * -1);
    }

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        if (isPlaying)
        {
           Fps = clock.restart();
            

            // POSITION MANAGEMENT
            sf::Vector2i localPosition = sf::Mouse::getPosition(window);

            int xDistance = localPosition.x - shape.getPosition().x;
            int yDistance = localPosition.y - shape.getPosition().y;
            float distance  =  sqrt(xDistance * xDistance + yDistance * yDistance);

            if (distance > 1)
            {
                for (unsigned int i = 0; i < nbPoints; ++i)
                    points[i].setPosition(points[i].getPosition().x + (xDistance - sizeShape) * -speedBall, points[i].getPosition().y + (yDistance - sizeShape) * -speedBall);
            
                for (unsigned int i = 0; i < nbPoints; ++i)
                {
                    if ((points[i].getPosition().x <= ScreenX && points[i].getPosition().x >= 0)
                    && (points[i].getPosition().y <= ScreenY && points[i].getPosition().y >= 0))
                    {
                        if ((points[i].getPosition().x >= (shape.getPosition().x - sizeShape) && points[i].getPosition().x <= shape.getPosition().x + sizeShape)
                        && (points[i].getPosition().y >= (shape.getPosition().y - sizeShape) && points[i].getPosition().y <= (shape.getPosition().y - sizeShape)))
                        {
                            points[i].setFillColor(sf::Color::Black);
                            shape.setScale(shape.getScale().x + 0.5f, shape.getScale().y);
                        }
                    }
                }
            }

/*
            // EVENT MANAGEMENT
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                shape.move(x, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                shape.move(0, y);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                shape.move(-x, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                shape.move(0, -y);
*/
        }

        //EVENT NON DESTINES AU JEU
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }

        window.clear();

        for (unsigned int i = 0; i < nbPoints; ++i)
        {
            if ((points[i].getPosition().x <= ScreenX && points[i].getPosition().x >= 0)
                && (points[i].getPosition().y <= ScreenY && points[i].getPosition().y >= 0))
                window.draw(points[i]);
            if (shape.getLocalBounds.intersects(points[i].getLocalBounds()))
            {
                points.erase(points.begin() + i);
            }
        }
        window.draw(shape);
        window.display();
    }

    return (0);
}
