#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>
#include <vector>

#include "Player.h"
#include "TextureManager.h"

void create_platforms(std::vector<std::unique_ptr<sf::Sprite>> &platforms)
{
    auto floor = std::make_unique<sf::Sprite>();
    floor->setTexture(*TextureManager::getTexture("wall"));
    floor->setTextureRect({0, 0, 800, 100});
    floor->setPosition(0, 500);
    platforms.emplace_back(std::move(floor));

    auto platform1 = std::make_unique<sf::Sprite>();
    platform1->setTexture(*TextureManager::getTexture("wall"));
    platform1->setTextureRect({0, 0, 100, 27});
    platform1->setPosition(200, 370);
    platforms.emplace_back(std::move(platform1));

    auto platform2 = std::make_unique<sf::Sprite>();
    platform2->setTexture(*TextureManager::getTexture("wall"));
    platform2->setTextureRect({0, 0, 100, 27});
    platform2->setPosition(300, 240);
    platforms.emplace_back(std::move(platform2));
}

void create_items(std::vector<std::unique_ptr<sf::Sprite>> &healing_items)
{
    auto heart = std::make_unique<sf::Sprite>();
    heart->setTexture(*TextureManager::getTexture("heart"));
    heart->setPosition(320, 180);
    healing_items.emplace_back(std::move(heart));
}

void create_interface(std::vector<std::unique_ptr<sf::Sprite>> &interface)
{
    auto life = std::make_unique<sf::Sprite>();
    life->setTexture(*TextureManager::getTexture("heart"));
    life->setPosition(10, 530);
    interface.emplace_back(std::move(life));
}

int main() {
    // Load textures
    TextureManager::loadTexture("guy", "textures/guy.png");
    TextureManager::loadTexture("heart", "textures/heart.png");
    TextureManager::loadTexture("half_heart", "textures/half_heart.png");
    TextureManager::loadTexture("wall", "textures/wall.png");
    // Set wall to be repeated texture
    TextureManager::getTexture("wall")->setRepeated(true);

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Eeasy Platform Game");

    // Create player
    Player player;
    player.setTexture(*TextureManager::getTexture("guy"));

    // Create platforms
    std::vector<std::unique_ptr<sf::Sprite>> platforms;
    create_platforms(platforms);

    std::vector<std::unique_ptr<sf::Sprite>> healing_items;
    create_items(healing_items);

    std::vector<std::unique_ptr<sf::Sprite>> interface;
    create_interface(interface);

    // Create clock
    sf::Clock clock;

    // Set frame rate limit
    window.setFramerateLimit(60);



    // run the program as long as the window is open
    while (window.isOpen()) {
        // EVENTS
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // LOGIC
        sf::Time elapsed = clock.restart();
        sf::FloatRect obstacle(800, 600 ,0 ,0);
        sf::FloatRect player_bounds = player.getGlobalBounds();

        for (const auto &s : platforms) {
            sf::FloatRect shape = s->getGlobalBounds();
            if (player.collision(elapsed, shape)) {
                obstacle = s->getGlobalBounds();
            }
        }

        player.gravity(elapsed, obstacle);
        player.animate(elapsed, obstacle);

        if (!healing_items.empty()) {
            for (int i = 0; i < healing_items.size(); i++) {
                sf::FloatRect item_bounds = healing_items[i]->getGlobalBounds();
                if (item_bounds.intersects(player_bounds)) {
                    player.addHp(50);
                    healing_items.erase(healing_items.begin() + i);
                }
            }
        }

        if (player.getHp() <= 50) {
            interface[0]->setTexture(*TextureManager::getTexture("half_heart"));
        } else {
            interface[0]->setTexture(*TextureManager::getTexture("heart"));
        }



        // DRAW
        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Draw everything here...
        for (const auto &s : platforms) {
            window.draw(*s);
        }

        if(!healing_items.empty()){
            for (const auto &s : healing_items) {
                window.draw(*s);
            }
        }
        
        window.draw(*interface[0]);

        // Draw player
        window.draw(player);

        // End the current frame
        window.display();
    }

    return 0;
}
