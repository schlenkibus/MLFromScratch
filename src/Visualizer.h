#pragma once
#include <SFML/Graphics.hpp>
#include "Neuron.h"

class NumberRecognition;

class Visualizer {
public:
    Visualizer() : window(sf::VideoMode(800, 600), "ML", sf::Style::Close) {

        image.create(28,28);

        for(int i = 0; i < 16; i++) {
            h1.emplace_back(sf::CircleShape(10, 20));
            h1.back().setOrigin(20, 20);
            h1.back().setPosition(200, i*25);
            h2.emplace_back(sf::CircleShape(10, 20));
            h2.back().setOrigin(20, 20);
            h2.back().setPosition(300, i*25);
        }
        for(int i = 0; i < 10; i++) {
            out.emplace_back(sf::CircleShape(10, 20));
            out.back().setOrigin(20, 20);
            out.back().setPosition(400, i*25);
        }
        texture.create(28,28);
        shape.setSize(sf::Vector2f(28,28));
        shape.setPosition(0,0);
        shape.setScale(5,5);
    }

    sf::Color activationToColor(float activation) {
        auto c = 5 * activation + 100;
        return sf::Color(c,c,c);
    }

    void update(NumberRecognition& r);

    sf::RenderWindow window;
    std::vector<sf::CircleShape> h1;
    std::vector<sf::CircleShape> h2;
    std::vector<sf::CircleShape> out;
    sf::RectangleShape shape;
    sf::Texture texture;
    sf::Image image;
};