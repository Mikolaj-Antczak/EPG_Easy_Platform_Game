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
    shape.top += speed_y_ * elapsed.asSeconds();

    if (shape.top + shape.height < 600 && !shape.intersects(wall)) {
        speed_y_ += gravity_ * elapsed.asSeconds();
    } else {
        speed_y_ = 0;
    }
}

void Player::animate(sf::Time elapsed, sf::FloatRect wall)
{
    sf::FloatRect shape = getGlobalBounds();
    int colide = 0;


    //Movement X
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        shape.left += speed_x_ * elapsed.asSeconds();
        if (!shape.intersects(wall)) {
            move(speed_x_ * elapsed.asSeconds(), 0);
        } else {
            colide = 1;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        shape.left += -speed_x_ * elapsed.asSeconds();
        if (!shape.intersects(wall)) {
            move(-speed_x_ * elapsed.asSeconds(), 0);
        } else {
            colide = 1;
        }
    }


    // Movement Y
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (shape.top + shape.height >= 599 || (shape.top + shape.height >= wall.top - 1 && shape.top + shape.height <= wall.top + 1
                                                                                             && shape.left + shape.width > wall.left && shape.left < wall.left + wall.width))) {
        speed_y_ = -500;
    }

    shape.top += speed_y_ * elapsed.asSeconds();
    if (!shape.intersects(wall) || colide) {
        move(0, elapsed.asSeconds() * speed_y_);
    }

    if (shape.top + shape.height > 600) {
        move(0, -(shape.top + shape.height - 600));
    }
}




