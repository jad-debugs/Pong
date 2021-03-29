#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
private:
    sf::Vector2f position;

    sf::RectangleShape ballShape;

    float xVelocity = 0.2f;
    float yVelocity = 0.2f;

public:
    // constructor prototype
    Ball(float startX, float startY);

    // prototype of functions that get pos/shape
    sf::FloatRect getPosition();
    sf::RectangleShape getShape();

    // prototype of functions that gets velocity (-> or <-, x axis)
    float getXVelocity();

    // protoype of functions where ball hits objects (wall, paddle, etc.)
    void reboundSides();
    void reboundPaddleOrTop();
    void hitBottom();

    // prototype of function that updates ball
    void update();
};
