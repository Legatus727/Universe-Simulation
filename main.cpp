#include <iostream>
#include <fstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "CelestialBody.h"
#include "Universe.h"

int main(int argc, char* argv[]) {

    Universe universe;
    float time = std::stof(argv[1]);
	float timeChange = std::stof(argv[2]);
    float elapsedTime = timeChange;

    std::cout << "Accepted time and time change : " << time << " | " << timeChange << std::endl;
    
    std::cin >> universe;

    
    sf::Image background;
    if (!background.loadFromFile("starfield.jpg")) {
        std::cout << "Failed to load background image" << std::endl;
        exit(1);
    }
    sf::Texture texture;
    texture.loadFromImage(background);
    sf::Sprite sprite;
    sprite.setTexture(texture);


    sf::RenderWindow window(sf::VideoMode(512, 512), "Space.. The Final Frontier");
    
    while (window.isOpen()) {
        sf::Event event;

        if (elapsedTime >= time) {
            universe.writeStats("planets-output.txt");
            window.close();
        } 

        for (int i = 0; i < universe.getNumPlanets(); i++) {
            universe.calculateStep(i);
        }

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(sprite);
        for (int i = 0; i < universe.getNumPlanets(); i++) {
            window.draw(universe[i]);
        }
        window.display();
        universe.step(timeChange);
        elapsedTime += timeChange;
    }


    return 0;
}
