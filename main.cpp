/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: bulat
 *
 * Created on 29 октября 2021 г., 1:19
 */

float player_x_pos = 0;
float player_y_pos = 0;

#include <SFML/Graphics.hpp>
#include <cmath>

int mouse_x_pos = 0;
int mouse_y_pos = 0;

int main(int argc, char** argv) {
    sf::RenderWindow window(sf::VideoMode(1680, 1050), "Game",sf::Style::Fullscreen);

    sf::Texture player_texture;
    if (!player_texture.loadFromFile("player.png")) {
    }
    sf::Sprite player(player_texture, sf::IntRect(0, 0, 43, 64));
    player.setOrigin(16, 32);
    player.setPosition(player_x_pos, player_y_pos);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time elaps = clock.restart();
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
            if (event.type == sf::Event::MouseMoved) {
                mouse_x_pos = sf::Mouse::getPosition().x;
                mouse_y_pos = sf::Mouse::getPosition().y;
            }

        }
        window.clear(sf::Color(0, 0, 0));
        player.setPosition(player_x_pos, player_y_pos);
        player.setRotation(atan2(mouse_y_pos - player.getPosition().y, mouse_x_pos - player.getPosition().x)*(180 / M_PI));
        window.draw(player);
        
        window.display();
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player_y_pos -= 100*elaps.asSeconds();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player_x_pos -= 100*elaps.asSeconds();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player_y_pos += 100*elaps.asSeconds();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player_x_pos += 100*elaps.asSeconds();
        }
    }
    return 0;
}