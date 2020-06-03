#include "Item.h"

Item::Item()
{
    //ctor
}

Item::~Item()
{
    //dtor
}

void Item::colision(sf::FloatRect player)
{
    sf::FloatRect item = getGlobalBounds();

    if (item.intersects(player)) {

    }
}
