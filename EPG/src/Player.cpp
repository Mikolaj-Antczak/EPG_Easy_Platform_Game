#include "Player.h"

Player::Player()
{
    //ctor
}

Player::~Player()
{
    //dtor
}

void Player::gravity(sf::Time elapsed)
{
    sf::FloatRect shape = getGlobalBounds();

    if (shape.top + shape.height < 600) {
        speed_y_ += gravity_ * elapsed.asSeconds();
    } else {
        speed_y_ = 0;
    }
}

void Player::animate(sf::Time elapsed)
{
    sf::FloatRect shape = getGlobalBounds();

    //Movement X
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        move(speed_x_ * elapsed.asSeconds(), 0);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        move(-speed_x_ * elapsed.asSeconds(), 0);
    }

    // Movement Y
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && shape.top + shape.height == 600) {
        speed_y_ = -400;
    }

    move(0, elapsed.asSeconds() * speed_y_);

    if (shape.top + shape.height > 600) {
        move(0, -(shape.top + shape.height - 600));
    }
}


