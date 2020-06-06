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
        colide_ = true;
    } else {
        velocity_y_ += gravity_ * elapsed.asSeconds();
    }
}

void Player::animate(sf::Time &elapsed, sf::FloatRect obstacle)
{
    // Jump
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && collision(elapsed, obstacle)) {
        velocity_y_ = -600;
    }

    // Movement X
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        sf::FloatRect player = getGlobalBounds();
        player.left += velocity_x_ * elapsed.asSeconds();
        if (!player.intersects(obstacle) || colide_) {
            move(velocity_x_ * elapsed.asSeconds(), 0);
            colide_ = false;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        sf::FloatRect player = getGlobalBounds();
        player.left -= velocity_x_ * elapsed.asSeconds();
        if (!player.intersects(obstacle) || colide_) {
            move(-velocity_x_ * elapsed.asSeconds(), 0);
            colide_ = false;
        }
    }

    // Movement Y
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

int Player::getHp()
{
    return hp_;
}

void Player::addHp(int add)
{
    hp_ += add;
}
