#pragma once

#include <SFML/Graphics.hpp>

class Player : public sf::Sprite
{
    public:
        Player();
        virtual ~Player();
        void gravity(sf::Time elapsed);
        void animate(sf::Time elapsed);
        void change_gun();

    protected:

    private:
        int health_ = 100;
        int speed_x_ = 200;
        int speed_y_ = 0;
        int gravity_ = 600;
        int gun_ = 0;
};

