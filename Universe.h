#ifndef UNIVERSE_H
#define UNIVERSE_H
#include <vector>
#include <list>
#include "CelestialBody.h"

class Universe {
public:
    Universe() : planets(0, nullptr) {};
    void addPlanet(float xPos, float yPos, float xVel, float yVel, float mass, std::string imageFile);
private:
    std::vector<CelestialBody*> planets;
};

#endif /* UNIVERSE_H */