#include <iostream>
#include "CelestialBody.h"

CelestialBody::CelestialBody(float xPos, float yPos, float xVel, float yVel, float mass, std::string imageFile) {

    sf::Image image;
    if (!image.loadFromFile(imageFile)) {
        std::cout << "Failed to load image." << std::endl;
        exit(1);
    }

    texture.loadFromImage(image);
    sprite.setTexture(texture);

    this->xPos = xPos;
    this->yPos = yPos;
    this->xVel = xVel;
    this->yVel = yVel;
    this->mass = mass;
    this->imageFile = imageFile;
    this->sprite = sprite;
    this->texture = texture;
    windowXSize = 512;
    windowYSize = 512;

    this->setModifiedPosition();
}

void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

void CelestialBody::setModifiedPosition() {

    if (imageFile == "sun.gif") {
        sprite.setPosition(windowXSize / 2, windowYSize / 2);
    } else {
        float modXPos{ xPos };
        float modYPos{ yPos };

        if (modXPos != 0) {
            modXPos /= 1e+9;
            modXPos += windowXSize / 2;
        } else {
            modXPos = windowXSize / 2;
        }

        if (modYPos != 0) {
            modYPos /= -1e+9;
            modYPos += windowYSize / 2;
        } else {
            modYPos = windowYSize / 2;
        }
        sprite.setPosition(modXPos, modYPos);
    }
    
}
