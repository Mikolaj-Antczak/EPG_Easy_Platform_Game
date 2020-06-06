#pragma once

#include <SFML/Graphics.hpp>

class Enemy : public sf::Sprite
{
public:
    Enemy();
    ~Enemy();
    
private:
    int hp_ = 20;

};

