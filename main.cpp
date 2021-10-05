#include <iostream>
#include <fstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "CelestialBody.h"
#include "Universe.h"

int main(int argc, char* argv[]) {

    int numOfPlanets;
    float universeSize;
    float xPos;
    float yPos;
    float xVel;
    float yVel;
    float mass;
    std::string imageFile;
    Universe universe;
    std::cin >> numOfPlanets;
    std::cin >> universeSize;

    std::cin >> xPos;
    std::cin >> yPos;
    std::cin >> xVel;
    std::cin >> yVel;
    std::cin >> mass;
    std::cin >> imageFile;


    // Use universe to read values

    CelestialBody body(xPos, yPos, xVel, yVel, mass, imageFile);
    body.setUniverseSize(universeSize);
    body.setWindowXSize(800);
    body.setWindowYSize(800);

    sf::RenderWindow window(sf::VideoMode(800, 800), "Space.. The Final Frontier");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
                if (event.type == sf::Event::Closed)
                        window.close();
        }
        window.clear(sf::Color::Black);
        window.draw(body);
        window.display();
    }
    

    return 0;
}