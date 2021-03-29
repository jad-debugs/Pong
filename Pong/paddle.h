#pragma once
#include <SFML/Graphics.hpp>

class Paddle
{
private:
    sf::Vector2f position;
    sf::RectangleShape paddleShape;
    float paddleSpeed = 0.25f;
public:
    // constructor protoype
    Paddle(float startX, float startY);

    // prototypes of the functions that get position/shape
    sf::FloatRect getPosition();
    sf::RectangleShape getShape();

    // prototypes of functions that move Paddle
    void moveLeft();
    void moveRight();
    
    // prototype of function that updates all paddle changes
    void update();
};
