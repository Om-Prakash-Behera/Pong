#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "states.h"

class Game
{
private:
    // Window
    sf::RenderWindow window;

    // Game state
    MenuState menu;
    PlayState play;
    State* currentState;    // Pointer to current state

public:
    Game();
    virtual ~Game() = default;

    // Initializations
    void initVars();
    void initWindow();

    void run();
};

#endif