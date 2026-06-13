#ifndef STATES_H
#define STATES_H

#include "entities.h"

inline int state = 0; // 0 = Menu, 1 = Play

class Game;

class State
{
public:
    virtual ~State() = default;

    virtual void handleInput() = 0;
    virtual void fixedUpdate(float dt) = 0;
    virtual void update(float dt) = 0;
    virtual void render(sf::RenderWindow& window) = 0;

};

class MenuState : public State
{
public:
    void handleInput() override;
    void fixedUpdate(float dt) override;
    void update(float dt) override;
    void render(sf::RenderWindow& window) override;

};

class PlayState : public State
{
private:
    // Game objects
    Ball ball;
    Pong player1;
    Pong player2;

    // Game logic variables here
    float pongSpeed = 20.f;
    float ballSpeedx = 40.f;
    float ballSpeedy = 40.f;

public:
    // Constructor Initialize player and enemy
    PlayState()
        : ball({400.f, 300.f}, 20.f, sf::Color::White),
          player1({50.f, 250.f}, {25.f, 100.f}, sf::Color::White),
          player2({735.f, 250.f}, {25.f, 100.f}, sf::Color::White)
    {}
    void handleInput() override;
    void fixedUpdate(float dt) override;
    void update(float dt) override;
    void render(sf::RenderWindow& window) override;
};

#endif