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
    windowXSize = 800;
    windowYSize = 800;

    this->setModifiedPosition();
}

void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

void CelestialBody::setModifiedPosition() {

    int modifiedXPos;
    int modifiedYPos;
    long long int xPosTemp = static_cast<long long int>(xPos);
    long long int yPosTemp = static_cast<long long int>(yPos);

    if (xPosTemp == 0) {
        modifiedXPos = 0;
    }
    else {
        modifiedXPos = xPosTemp % (windowXSize / 2);
        if (modifiedXPos < 1) { modifiedXPos *= -1; }
    }
    if (yPosTemp == 0) {
        modifiedYPos = 0;
    }
    else {
        modifiedYPos = yPosTemp % (windowYSize / 2);
        if (modifiedYPos < 1) { modifiedYPos *= -1; }
    }

    modifiedXPos += windowXSize / 2;
    modifiedYPos += windowYSize / 2;

    sprite.setPosition(modifiedXPos, modifiedYPos);

    xPos = static_cast<float>(modifiedXPos);
    yPos = static_cast<float>(modifiedYPos);
}
