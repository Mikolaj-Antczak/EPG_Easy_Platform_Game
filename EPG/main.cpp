#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>
#include <vector>

#include "Player.h"
#include "TextureManager.h"
#include "Platforms.h"

sf::Texture loadTexture(std::string path_to_file)
{
    sf::Texture texture;
    if (!texture.loadFromFile(path_to_file)) {
        std::cerr << "Could not load texture" << std::endl;
    }
    return texture;
}

void create_platforms(std::vector<sf::Sprite> &platforms)
{
    auto wall1= std::make_unique<sf::Sprite>();
    wall1->setTexture(*TextureManager::getTexture("wall"));
    wall1->setPosition(0, 400);
    platforms.emplace_back(std::move(wall1));

    auto wall2= std::make_unique<sf::Sprite>();
    wall2->setTexture(*TextureManager::getTexture("wall"));
    wall2->setPosition(200, 400);
    platforms.emplace_back(std::move(wall2));

    auto wall3= std::make_unique<sf::Sprite>();
    wall3->setTexture(*TextureManager::getTexture("wall"));
    wall3->setPosition(400, 400);
    platforms.emplace_back(std::move(wall3));

    auto wall4= std::make_unique<sf::Sprite>();
    wall4->setTexture(*TextureManager::getTexture("wall"));
    wall4->setPosition(600, 400);
    platforms.emplace_back(std::move(wall4));
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
    std::vector<sf::Sprite> platforms;
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

        for (const auto &s : platforms) {
            sf::FloatRect platform_bounds = (*s)->getGlobalBounds();
            player.animate(elapsed, platform_bounds);
            player.gravity(elapsed, platform_bounds);
        }

        // DRAW
        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Draw everything here...
        for (const auto &s : platforms) {
            window.draw(*s);
        }

        /*window.draw(wall1);
        window.draw(wall2);
        window.draw(wall3);
        window.draw(wall4);*/

        // Draw player
        window.draw(player);

        // End the current frame
        window.display();
    }

    return 0;
}
