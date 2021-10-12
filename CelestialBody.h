#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class CelestialBody : public sf::Drawable {
public:
    CelestialBody(float xPos, float yPos, float xVel, float yVel, float mass, std::string imageFile);
    void setUniverseSize(float size) { universeSize = size; }
    void setWindowXSize(float size) { windowXSize = size; }
    void setWindowYSize(float size) { windowXSize = size; }
    void setModifiedPosition();
    float getXPos() { return xPos; }
    float getYPos() { return yPos; }
    float getXVel() { return xVel; }
    float getYVel() { return yVel; }
    float getMass() { return mass; }
    float getUniverseSize() { return universeSize; }
    float getTempXAccel() { return tempXAccel; }
    float getTempYAccel() { return tempYAccel; }
    std::string getImageFile() { return imageFile; }
    void setXPos(float xPos) { this->xPos = xPos; }
    void setYPos(float yPos) { this->yPos = yPos; }
    void setXVel(float xVel) { this->xVel = xVel; }
    void setYVel(float yVel) { this->yVel = yVel; }
    void setTempXAccel(float xPos) { this->tempXAccel = xPos; }
    void setTempYAccel(float yPos) { this->tempYAccel = yPos; }



private:
    float xPos;
    float yPos;
    float xVel;
    float yVel;
    float mass;
    std::string imageFile;
    sf::Sprite sprite;
    sf::Texture texture;
    float universeSize;
    int windowXSize;
    int windowYSize;
    float tempXAccel;
    float tempYAccel;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif /* CELESTIALBODY_H */
