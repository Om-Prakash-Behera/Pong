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
PlayState::PlayState()
    : ball({400.f, 300.f}, 20.f, sf::Color::White),
      player1({50.f, 250.f}, {25.f, 100.f}, sf::Color::White),
      player2({735.f, 250.f}, {25.f, 100.f}, sf::Color::White),
      font(RESOURCES_PATH "VT323.ttf"),
      player1_score_text(font, "0", 50),
      player2_score_text(font, "0", 50)
{
    int resolution = 100;
    player1_score_text.setCharacterSize(resolution);
    player2_score_text.setCharacterSize(resolution);

    player1_score_text.setScale({50.f / resolution, 30.f / resolution});
    player2_score_text.setScale({50.f / resolution, 30.f / resolution});

    player1_score_text.setPosition({350.f, 10.f});
    player2_score_text.setPosition({450.f, 10.f});

    player1_score_text.setFillColor(sf::Color::Red);
    player2_score_text.setFillColor(sf::Color::Red);

    
}

void PlayState::handleInput()
{
    
}

void PlayState::fixedUpdate(float dt)
{
    // Movement for player 1
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        this->player1.move(-this->pongSpeed * dt);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        this->player1.move(this->pongSpeed * dt);
    
    // Movement for Player 2
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        this->player2.move(-this->pongSpeed * dt);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        this->player2.move(this->pongSpeed * dt);

    // Check if ball out of bounds
    if (this->ball.getPosition().y - this->ball.getRadius() < 0 || this->ball.getPosition().y + this->ball.getRadius() > 600)
    {
        this->ballSpeedy = -this->ballSpeedy;

        // Increase speed on each bounce

        if (ballSpeedx > 0)
            ballSpeedx += 5.f;
        else
            ballSpeedx -= 5.f;            
    }

    // Movement for Ball
    this->ball.move(this->ballSpeedx * dt, this->ballSpeedy * dt);

    // Check if ball hit a player
    if ((this->ball.intersects(this->player1.getGlobalBounds()) || this->ball.intersects(this->player2.getGlobalBounds())))
    {
        if (!intersecting)
        {
            this->ballSpeedx = -this->ballSpeedx;
            intersecting = true;

            // Increase speed on each bounce
            if (ballSpeedy > 0)
                ballSpeedy += 5.f;
            else
                ballSpeedy -= 5.f;

        }
    }
    else
    {
        intersecting = false;
    }
    

    // Check if ball hit a player's side
    if (this->ball.getPosition().x - this->ball.getRadius() < 0)
    {
        // Reset Ball speed and pos
        ballSpeedx = 100.f * (rand() % 2 == 0 ? 1 : -1); // Randomize initial direction
        ballSpeedy = 100.f * (rand() % 2 == 0 ? 1 : -1);
        this->ball.moveTo(400, 300);
        player2_score++;
    }
    else if (this->ball.getPosition().x + this->ball.getRadius() > 800)
    {
        // Reset Ball speed and pos
        ballSpeedx = 100.f * (rand() % 2 == 0 ? 1 : -1); // Randomize initial direction
        ballSpeedy = 100.f * (rand() % 2 == 0 ? 1 : -1);
        this->ball.moveTo(400, 300);        
        player1_score++;
    }
}

void PlayState::update(float dt)
{
    player1_score_text.setString(std::to_string(player1_score));
    player2_score_text.setString(std::to_string(player2_score));


    if (player1_score == 3 || player2_score == 3)
    {
        state = 0; // Go back to menu state

        // Reset vars
        player1_score = 0;
        player2_score = 0;
        pongSpeed = 150.f;
        ballSpeedx = 100.f;
        ballSpeedy = 100.f;
        intersecting = false;
    }
}

void PlayState::render(sf::RenderWindow& window)
{
    window.clear();   // Clear window

    // Draw stuff here
    this->ball.draw(window);
    this->player1.draw(window);
    this->player2.draw(window);
    
    window.draw(this->player1_score_text);
    window.draw(this->player2_score_text);

    window.display(); // Display window

}   
