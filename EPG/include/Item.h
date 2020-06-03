#pragma once

#include <SFML/Graphics.hpp>

class Item : public sf::Sprite
{
    public:
        Item();
        virtual ~Item();
        void colision(sf::FloatRect);

    protected:

    private:
};

