#pragma once

#include <SFML/Graphics.hpp>

class Player : public sf::Sprite
{
    public:
        Player();
        virtual ~Player();
        void gravity(sf::Time elapsed, sf::FloatRect wall);
        void animate(sf::Time elapsed, sf::FloatRect wall);
        void change_gun();
        void colision(int colide);
        void noColision();

    protected:

    private:
        int health_ = 100;
        int speed_x_ = 200;
        int speed_y_ = 0;
        int gravity_ = 800;
        int gun_ = 0;
        int colision_ = 0;
};

