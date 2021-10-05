#include <iostream>
#include <fstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "CelestialBody.h"
#include "Universe.h"

int main(int argc, char* argv[]) {
    
    Universe universe;
    std::cin >> universe;

    sf::RenderWindow window(sf::VideoMode(800, 800), "Space.. The Final Frontier");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
                if (event.type == sf::Event::Closed)
                        window.close();
        }
        window.clear(sf::Color::Black);
        for (int i = 0; i < universe.getNumPlanets(); i++) {
            window.draw(*(universe.getPlanet(i)));
        }
        window.display();
    }
    

    return 0;
}