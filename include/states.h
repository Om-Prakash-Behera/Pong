#ifndef STATES_H
#define STATES_H

#include "entities.h"

inline int state = 1; // 0 = Menu, 1 = Play

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
    sf::Font font;
    sf::Text player1_score_text;
    sf::Text player2_score_text;

    // Game logic variables here
    float pongSpeed = 150.f;
    float ballSpeedx = 100.f;
    float ballSpeedy = 100.f;
    int player1_score = 0;
    int player2_score = 0;
    bool intersecting = false; // To prevent multiple collisions in one frame

public:
    // Constructor Initialize player and enemy
    PlayState();
    void handleInput() override;
    void fixedUpdate(float dt) override;
    void update(float dt) override;
    void render(sf::RenderWindow& window) override;
};

#endif