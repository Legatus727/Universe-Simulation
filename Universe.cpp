#include <iostream>
#include "Universe.h"

  
void Universe::addPlanet(float xPos, float yPos, float xVel, float yVel, float mass, std::string imageFile) {

    std::unique_ptr<CelestialBody> planet(new CelestialBody(xPos, yPos, xVel, yVel, mass, imageFile));

    planets.push_back(planet.get());
}