#ifndef UNIVERSE_H
#define UNIVERSE_H
#include <vector>
#include <list>
#include <iostream>
#include "CelestialBody.h"

class Universe {
public:
    Universe() {};
    CelestialBody operator[](int index);
    friend std::istream& operator>>(std::istream& in, Universe& universe);
    void addPlanet(float xPos, float yPos, float xVel, float yVel, float mass, std::string imageFile);
    void step(double seconds);
    void writeStats(std::string fileName);
    void calculateStep(int planetIndex);
    int getNumPlanets() { return planets.size(); }

private:
    std::vector<CelestialBody*> planets;
};

#endif /* UNIVERSE_H */
