#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

#include "Player.h"

int main() {
    // Load textures
    sf::Texture texture_guy;
    if (!texture_guy.loadFromFile("textures/guy.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }

    sf::Texture texture_wall;
    if (!texture_wall.loadFromFile("textures/wall.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }


    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // create some shapes
    sf::CircleShape circle(100.0);
    circle.setPosition(100.0, 300.0);
    circle.setFillColor(sf::Color(100, 250, 50));

    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color(100, 50, 250));

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(5);
    triangle.setPosition(600.0, 100.0);

    // Create player
    Player player;
    player.setTexture(texture_guy);

    // Create wall
    sf::Sprite wall;
    wall.setTexture(texture_wall);
    wall.setPosition(300, 500);
    //wall.setScale(0.5, 0.1);

    sf::Clock clock;

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

        sf::FloatRect wall_bounds = wall.getGlobalBounds();

        player.animate(elapsed, wall_bounds);
        player.gravity(elapsed, wall_bounds);

        // DRAW
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(wall);
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);
        window.draw(player);

        // end the current frame
        window.display();
    }

    return 0;
}
