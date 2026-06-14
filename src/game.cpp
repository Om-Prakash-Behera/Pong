#include "game.h"

// Initialization

void Game::initVars()
{
    // Initialize game state here
    currentState = &play;
}

void Game::initWindow()
{
    this->window.create(sf::VideoMode({800, 600}), "Pong", sf::Style::Titlebar | sf::Style::Close);
    this->window.setPosition({100, 100});
    this->window.setFramerateLimit(60);
}

// Constructor

Game::Game() 
{
    // Initialize game state
    this->initWindow();
    this->initVars();
}

// Game Loop

void Game::run()
{
    while (this->window.isOpen())
    {
        while (const std::optional event = this->window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                this->window.close();
        }
        switch (state)
        {
            case 0:
                currentState = &menu;
                break;
            case 1:
                currentState = &play;
                break;
            default:
                currentState = &menu;
                break;
        }

        currentState->fixedUpdate(1.f / 60.f);
        currentState->update(1.f / 60.f);

        currentState->render(window);
    }
}