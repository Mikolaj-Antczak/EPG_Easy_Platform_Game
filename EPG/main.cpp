#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>
#include <vector>

#include "Player.h"
#include "TextureManager.h"

void create_platforms(std::vector<std::unique_ptr<sf::Sprite>> &platforms)
{
    auto wall1= std::make_unique<sf::Sprite>();
    wall1->setTexture(*TextureManager::getTexture("wall"));
    wall1->setPosition(0, 500);
    platforms.emplace_back(std::move(wall1));

    auto wall2= std::make_unique<sf::Sprite>();
    wall2->setTexture(*TextureManager::getTexture("wall"));
    wall2->setPosition(200, 500);
    platforms.emplace_back(std::move(wall2));

    auto wall3= std::make_unique<sf::Sprite>();
    wall3->setTexture(*TextureManager::getTexture("wall"));
    wall3->setPosition(400, 500);
    platforms.emplace_back(std::move(wall3));

    auto wall4= std::make_unique<sf::Sprite>();
    wall4->setTexture(*TextureManager::getTexture("wall"));
    wall4->setPosition(600, 500);
    platforms.emplace_back(std::move(wall4));

    auto wall5= std::make_unique<sf::Sprite>();
    wall5->setTexture(*TextureManager::getTexture("wall"));
    wall5->setPosition(400, 400);
    wall5->setScale(0.2, 0.2);
    platforms.emplace_back(std::move(wall5));
}



int main() {
    // Load textures
    TextureManager::loadTexture("guy", "textures/guy.png");
    TextureManager::loadTexture("wall", "textures/wall.png");

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Eeasy Platform Game");

    // Create player
    Player player;
    player.setTexture(*TextureManager::getTexture("guy"));

    // Create platforms
    std::vector<std::unique_ptr<sf::Sprite>> platforms;
    create_platforms(platforms);

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

        for (const auto &s : platforms) {
            sf::FloatRect shape = s->getGlobalBounds();
            if (player.collision(elapsed, shape)) {
                obstacle = s->getGlobalBounds();
            }
        }

        player.gravity(elapsed, obstacle);
        player.animate(elapsed, obstacle);

        // DRAW
        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Draw everything here...
        for (const auto &s : platforms) {
            window.draw(*s);
        }

        // Draw player
        window.draw(player);

        // End the current frame
        window.display();
    }

    return 0;
}
