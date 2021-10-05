#include <iostream>
#include "CelestialBody.h"

CelestialBody::CelestialBody(float xPos, float yPos, float xVel, float yVel, float mass, std::string imageFile) {

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

    this->setModifiedPosition();
}

void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

void CelestialBody::setModifiedPosition() {
    int modifiedXPos = ((int)xPos) % (windowXSize / 2);
    int modifiedYPos = ((int)yPos) % (windowYSize / 2);

    sprite.setPosition((windowXSize / 2) + modifiedXPos, (windowYSize / 2) + modifiedYPos);

    xPos = (float)modifiedXPos;
    yPos = (float)modifiedYPos;
}