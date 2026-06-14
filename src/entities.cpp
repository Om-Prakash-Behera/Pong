#include "entities.h"

// Ball

// Constructor
Ball::Ball(sf::Vector2f position, float radius, sf::Color color)
{
    this->shape.setOrigin({radius, radius});
    this->shape.setRadius(radius);
    this->shape.setFillColor(color);
    this->shape.setPosition(position);
}

// Accessors
sf::Vector2f Ball::getPosition() const
{
    return this->shape.getPosition();
}

float Ball::getRadius() const
{
    return this->shape.getRadius();
}

// Collision detection
bool Ball::intersects(const sf::FloatRect& rect) const
{
    if (this->shape.getGlobalBounds().findIntersection(rect))
        return true;
    return false;
}
// Motion
void Ball::move(float dx, float dy)
{
    this->shape.move({dx, dy});
}

void Ball::moveTo(float x, float y)
{
    this->shape.setPosition({x, y});
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

// Accessors
sf::FloatRect Pong::getGlobalBounds() const
{
    return this->shape.getGlobalBounds();
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