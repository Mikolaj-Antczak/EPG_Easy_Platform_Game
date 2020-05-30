#include "Player.h"

Player::Player()
{
    //ctor
}

Player::~Player()
{
    //dtor
}

void Player::gravity(sf::Time elapsed, sf::FloatRect wall)
{
    sf::FloatRect shape = getGlobalBounds();

    if (shape.top + shape.height < 600 && !shape.intersects(wall)) {
        speed_y_ += gravity_ * elapsed.asSeconds();
    } else {
        speed_y_ = 0;
    }
}

void Player::animate(sf::Time elapsed, sf::FloatRect wall)
{
    sf::FloatRect shape = getGlobalBounds();


    //Movement X
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        move(speed_x_ * elapsed.asSeconds(), 0);
        if (shape.intersects(wall)) {
            setPosition(wall.left - shape.width - 1, shape.top);
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        move(-speed_x_ * elapsed.asSeconds(), 0);
        if (shape.intersects(wall)) {
            setPosition(wall.left + wall.width + 1, shape.top);
        }
    }

    // Movement Y
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (shape.top + shape.height == 600 || shape.top + shape.height >= wall.top - 1)) {
        speed_y_ = -400;
    }

    move(0, elapsed.asSeconds() * speed_y_);
    if (shape.intersects(wall)) {
        move(0, -shape.top - shape.height + wall.top - 0.1);
    }

    if (shape.top + shape.height > 600) {
        move(0, -(shape.top + shape.height - 600));
    }
}




