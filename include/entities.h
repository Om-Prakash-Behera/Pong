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

    // Accessors
    sf::Vector2f getPosition() const;
    float getRadius() const;
    
    // Collision detection
    bool intersects(const sf::FloatRect& rect) const;
    
    // Move ball
    void move(float dx, float dy);
    void moveTo(float x, float y);

    void draw(sf::RenderWindow& window);
};

class Pong
{
private:
    sf::RectangleShape shape;
public:
    // Initialize players
    Pong(sf::Vector2f position, sf::Vector2f size, sf::Color color);
    
    // Accessor
    sf::FloatRect getGlobalBounds() const;

    // Move pong
    void move(float dy);

    void draw(sf::RenderWindow& window);
};

#endif