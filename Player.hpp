#pragma once

#include <SFML/Graphics.hpp>

class Player : public sf::Sprite
{
    public:
        Player();
        virtual ~Player();
        void gravity(sf::Time&, sf::FloatRect);
        void animate(sf::Time&, sf::FloatRect);
        bool collision(sf::Time, sf::FloatRect);
        int getHp();
        void addHp(int);

    protected:

    private:
        float velocity_x_ = 300;
        float velocity_y_ = 0;
        float gravity_ = 1200;
        bool colide_ = false;
        int hp_ = 50;
};

