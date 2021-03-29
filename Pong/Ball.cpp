#include "ball.h"
const int ACCL = 6;
// constructor
Ball::Ball(float startX, float startY)
{
    position.x = startX;
    position.y = startY;

    ballShape.setSize(sf::Vector2f(10, 10));
    ballShape.setPosition(position);
}

// other functions prototyped in ball.h
sf::FloatRect Ball::getPosition()
{
    return ballShape.getGlobalBounds();
}

sf::RectangleShape Ball::getShape()
{
    return ballShape;
}

float Ball::getXVelocity()
{
    return xVelocity;
}

void Ball::reboundSides()
{
    xVelocity = -xVelocity;
}

void Ball::reboundPaddleOrTop()
{
    position.y -= (yVelocity * ACCL);
    yVelocity = -yVelocity;
}

void Ball::hitBottom()
{
    position.y = 1;
    position.x = 500;
}

void Ball::update()
{
    // Update the ball position variables
    position.y += yVelocity;
    position.x += xVelocity;

    // update final ball pos
    ballShape.setPosition(position);
}
