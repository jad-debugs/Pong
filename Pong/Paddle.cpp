#include "paddle.h"

// constructor
Paddle::Paddle(float startX, float startY)
{
    position.x = startX;
    position.y = startY;

    paddleShape.setSize(sf::Vector2f(50, 5));
    paddleShape.setPosition(position);
}

// other 5 functions found in paddle.h
sf::FloatRect Paddle::getPosition()
{
    return paddleShape.getGlobalBounds();
}

sf::RectangleShape Paddle::getShape()
{
    return paddleShape;
}

void Paddle::moveLeft()
{
    position.x -= paddleSpeed;
}

void Paddle::moveRight()
{
    position.x += paddleSpeed;
}

void Paddle::update()
{
    paddleShape.setPosition(position);
}
