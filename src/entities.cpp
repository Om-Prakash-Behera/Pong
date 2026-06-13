#include "entities.h"

// Ball

// Constructor
Ball::Ball(sf::Vector2f position, float radius, sf::Color color)
{
    this->shape.setRadius(radius);
    this->shape.setFillColor(color);
    this->shape.setPosition(position);
}

// Motion
void Ball::move(float dx, float dy)
{
    this->shape.move({dx, dy});
}

// Rendering
void Ball::draw(sf::RenderWindow& window)
{
    window.draw(this->shape);
}

// Pong

// Constructor
Pong::Pong(sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
    this->shape.setSize(size);
    this->shape.setFillColor(color);
    this->shape.setPosition(position);
}

// Motion
void Pong::move(float dy)
{
    if (this->shape.getPosition().y + dy < 0 || this->shape.getPosition().y + this->shape.getSize().y + dy > 600)
        return;
    this->shape.move({0.f, dy});
}
// Rendering
void Pong::draw(sf::RenderWindow& window)
{
    window.draw(this->shape);
}