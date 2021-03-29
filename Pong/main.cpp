#include "paddle.h"
#include "ball.h"
#include <sstream>
#include <cstdlib>
#include <chrono>
#include <SFML/Graphics.hpp>

int main()
{
    const int windowWidth = 1024;
    const int windowHeight = 768;

    // window thats 1024 x 768, shows up named Pong
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Pong");
        
    int score = 0;
    int lives = 5;
       
    // making paddle object
    Paddle paddle(windowWidth / 2, windowHeight - 20);

    // making ball object
    Ball ball(windowWidth / 2, 1);

    // text object for hud
    sf::Text hud;

    // font for text (custom) found in Pong folder
    sf::Font font;
    font.loadFromFile("game_over.ttf");

    // font to text
    hud.setFont(font);

    // changing text size
    hud.setCharacterSize(75);

    // changing text color
    hud.setFillColor(sf::Color::Black);

    // for fps
    auto tp1 = std::chrono::system_clock::now();
    auto tp2 = std::chrono::system_clock::now();

    // Continues while window isnt closed by user
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // user input through keyboard to left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            paddle.moveLeft();
        }
        // user input through keyboard to right
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            paddle.moveRight();
        }
        // if escape is clicked
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        // check if ball hits bottom
        if (ball.getPosition().top > windowHeight) {
            // reverse the ball direction
            ball.hitBottom();

            // Remove a life
            lives--;

            // Check for zero lives
            if (lives < 1) {
                // reset the score
                score = 0;
                // reset the lives
                lives = 5;
            }
        }

        // check if ball hits top
        if (ball.getPosition().top < 0) {
            ball.reboundPaddleOrTop();

            // Add a point to the players score
            score++;

        }

        // Handle ball hitting sides
        if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth) {
            ball.reboundSides();
        }

        // Has the ball hit the bat?
        if (ball.getPosition().intersects(paddle.getPosition())) {
            // Hit detected so reverse the ball and score a point
            ball.reboundPaddleOrTop();
        }
        ball.update();
        paddle.update();

        // check time
        tp2 = std::chrono::system_clock::now();
        std::chrono::duration<float> elapsedTime = tp2 - tp1;
        tp1 = tp2;
        float fElapsedTime = elapsedTime.count();

        // Update the HUD text
        std::stringstream ss;
        ss << "Score: " << score << "    Lives: " << lives
        << "   FPS: " << 1.0/ fElapsedTime;
        hud.setString(ss.str());

        // clear frame
        window.clear(sf::Color(26, 128, 182, 255));

        window.draw(paddle.getShape());

        window.draw(ball.getShape());

        // Draw our score
        window.draw(hud);

        // Show everything we just drew
        window.display();
    }
    return 0;
}
