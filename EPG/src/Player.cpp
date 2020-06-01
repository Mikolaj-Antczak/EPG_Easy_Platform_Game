#include "Player.h"

Player::Player()
{
    //ctor
}

Player::~Player()
{
    //dtor
}

void Player::gravity(sf::Time &elapsed, sf::FloatRect obstacle)
{
    sf::FloatRect player = getGlobalBounds();
    player.top += velocity_y_ * elapsed.asSeconds();

    if (player.intersects(obstacle)) {
        velocity_y_ = 0;
        colide = true;
    } else {
        velocity_y_ += gravity_ * elapsed.asSeconds();
    }
}

void Player::animate(sf::Time &elapsed, sf::FloatRect obstacle)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        velocity_y_ = -400;
    }



    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        sf::FloatRect player = getGlobalBounds();
        player.left += velocity_x_ * elapsed.asSeconds();
        if (!player.intersects(obstacle) || colide) {
            move(velocity_x_ * elapsed.asSeconds(), 0);
            colide = false;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        sf::FloatRect player = getGlobalBounds();
        player.left -= velocity_x_ * elapsed.asSeconds();
        if (!player.intersects(obstacle) || colide) {
            move(-velocity_x_ * elapsed.asSeconds(), 0);
            colide = false;
        }
    }

    move(0, velocity_y_ * elapsed.asSeconds());
}

bool Player::collision(sf::Time elapsed, sf::FloatRect obstacle)
{
    sf::FloatRect player = getGlobalBounds();
    player.top += velocity_y_ * elapsed.asSeconds();

    if (player.intersects(obstacle)) {
        return true;
    }
    return false;
}
