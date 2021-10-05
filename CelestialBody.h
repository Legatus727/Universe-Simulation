#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class CelestialBody : public sf::Drawable{
public:
    CelestialBody(float xPos, float yPos, float xVel, float yVel, float mass, std::string imageFile);
    void setUniverseSize(float size) { universeSize = size; }
    void setWindowXSize(float size) { windowXSize = size; }
    void setWindowYSize(float size) { windowXSize = size; }

    
        
private:
    float xPos;
    float yPos;
    float xVel;
    float yVel;
    float mass;
    sf::Sprite sprite;
    sf::Texture texture;
    float universeSize; 
    int windowXSize;
    int windowYSize;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif /* CELESTIALBODY_H */