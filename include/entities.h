#ifndef ENTITIES_H
#define ENTITIES_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

class Ball
{
private:
    sf::CircleShape shape;
public:
    // Initialize ball
    Ball(sf::Vector2f position, float radius, sf::Color color);

    // Move ball
    void move(float dx, float dy);

    void draw(sf::RenderWindow& window);
};

class Pong
{
private:
    sf::RectangleShape shape;
public:
    // Initialize players
    Pong(sf::Vector2f position, sf::Vector2f size, sf::Color color);
    
    // Move pong
    void move(float dy);

    void draw(sf::RenderWindow& window);
};

#endif