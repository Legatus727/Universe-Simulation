#include <iostream>
#include "CelestialBody.h"

CelestialBody::CelestialBody(float xPos, float yPos, float xVel, float yVel, float mass, std::string imageFile) {

    int modifiedXPos = ((int)xPos) % windowXSize;
    int modifiedYPos = ((int)yPos) % windowYSize;
    sf::Image image;
    if (!image.loadFromFile(imageFile)) {
        std::cout << "Failed to load image." << std::endl;
        exit(1);
    }

    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite(texture);
    
    this->xPos = xPos;
    this->yPos = yPos;
    this->xVel = xVel;
    this->yVel = yVel;
    this->mass = mass;
    this->sprite = sprite;
    this->texture = texture;

    sprite.setPosition((windowXSize / 2) + modifiedXPos, (windowYSize / 2) + modifiedYPos);

    // set sprite position
}

void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}