#include "states.h"

// MenuState
void MenuState::handleInput()
{
    
}

void MenuState::fixedUpdate(float dt)
{
    
}

void MenuState::update(float dt)
{
    
}

void MenuState::render(sf::RenderWindow& window)
{
    window.clear();   // Clear window

    // Draw stuff here

    window.display(); // Display window

}   

// PlayState
void PlayState::handleInput()
{
    
}

void PlayState::fixedUpdate(float dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        this->player1.move(-this->pongSpeed * dt);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        this->player1.move(this->pongSpeed * dt);
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        this->player2.move(-this->pongSpeed * dt);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        this->player2.move(this->pongSpeed * dt);
}

void PlayState::update(float dt)
{
    
}

void PlayState::render(sf::RenderWindow& window)
{
    window.clear();   // Clear window

    // Draw stuff here
    this->ball.draw(window);
    this->player1.draw(window);
    this->player2.draw(window);

    window.display(); // Display window

}   
