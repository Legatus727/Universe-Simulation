#ifndef UNIVERSE_H
#define UNIVERSE_H
#include <vector>
#include <list>
#include <iostream>
#include "CelestialBody.h"

class Universe {
public:
    Universe() : planets(0, nullptr) {};
    void addPlanet(float xPos, float yPos, float xVel, float yVel, float mass, std::string imageFile);
    CelestialBody& operator[](int index);
    int getNumPlanets() { return planets.size(); }
    friend std::istream& operator>>(std::istream& in, Universe& universe);

private:
    std::vector<CelestialBody*> planets;
};

#endif /* UNIVERSE_H */
