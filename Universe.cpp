#include <iostream>
#include "Universe.h"

  
void Universe::addPlanet(float xPos, float yPos, float xVel, float yVel, float mass, std::string imageFile) {

    std::unique_ptr<CelestialBody> planet(new CelestialBody(xPos, yPos, xVel, yVel, mass, imageFile));

    planets.push_back(planet.get());
}

std::istream& operator>>(std::istream& in, Universe& universe) {
    int numPlanets;
    float universeSize;
    float xPos;
    float yPos;
    float xVel;
    float yVel;
    float mass;
    std::string imageFile;

    in >> numPlanets;
    in >> universeSize;

    for (int i = 0; i < numPlanets; i++) {
        in >> xPos;
        in >> yPos;
        in >> xVel;
        in >> yVel;
        in >> mass;
        in >> imageFile;

        universe.addPlanet(xPos, yPos, xVel, yVel, mass, imageFile);
        universe.planets[i]->setUniverseSize(universeSize);
    }

    return in;
}

CelestialBody* Universe::getPlanet(int index) {
   
    if (index < 0 || index > this->planets.size()) {
        std::cout << "Invalid index" << std::endl;
        return nullptr;
    }
    
    return this->planets[index];
}