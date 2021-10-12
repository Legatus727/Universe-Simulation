/**
 * Universe.cpp - Implementation of the Universe class
 * 
 * Author: Tim Robbins
 * Date: 10/11/21
 * Class: COMP.2040 - 202
 * Instructor: Dr. Rykalova
 */
#include <iostream>
#include "Universe.h"
#include <math.h>


void Universe::addPlanet(float xPos, float yPos, float xVel, float yVel, float mass, std::string imageFile) {

    CelestialBody* planet(new CelestialBody(xPos, yPos, xVel, yVel, mass, imageFile));

    planets.push_back(planet);
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

CelestialBody Universe::operator[](int index) {
    if (index < 0 || index >(int)planets.size()) {
        std::cout << "Invalid index" << std::endl;
        exit(1);
    } 

    return *(planets[index]);
}


void Universe::step(double seconds) {
    for (int i = 0; i < static_cast<int>(planets.size()); i++) {

        long double xVel = planets[i]->getXVel() + (seconds * planets[i]->getTempXAccel());
        planets[i]->setXVel(xVel);
        long double yVel = planets[i]->getYVel() + (seconds * planets[i]->getTempYAccel());
        planets[i]->setYVel(yVel);

        planets[i]->setXPos(planets[i]->getXPos() + (seconds * xVel));
        planets[i]->setYPos(planets[i]->getYPos() + (seconds * yVel));
        planets[i]->setModifiedPosition();
    }
}

void Universe::calculateStep(int planetIndex) {
    long double sumOfForceX{ 0 };
    long double sumOfForceY{ 0 };
    float gravity = 6.67e-11;

     for (int i = 0; i < getNumPlanets(); i++) {
         if (i != planetIndex) {
            long double differenceX = planets[i]->getXPos() - planets[planetIndex]->getXPos();
            long double differenceY = planets[i]->getYPos() - planets[planetIndex]->getYPos();
            long double r = sqrt(pow(differenceX, 2) + pow(differenceY, 2));
            long double force = gravity * (planets[i]->getMass() * (planets[planetIndex]->getMass() / pow(r, 2)));
            long double forceX = force * (differenceX / r);
            long double forceY = force * (differenceY / r);

            sumOfForceX += forceX;
            sumOfForceY += forceY;
         }
     }

     long double accelerationX = sumOfForceX / planets[planetIndex]->getMass();
     long double accelerationY = sumOfForceY / planets[planetIndex]->getMass();

     planets[planetIndex]->setTempXAccel(accelerationX);
     planets[planetIndex]->setTempYAccel(accelerationY);
}

void Universe::displayStats() {
    std::cout << static_cast<int>(planets.size()) << std::endl;

    for (int i = 0; i < static_cast<int>(planets.size()); i++) {
        
        if ( i == 0) {
            std::cout << planets[i]->getUniverseSize() << std::endl;
        }

        std::printf("%12g  %12g  %12g  %12g  %12g  ", planets[i]->getXPos(), planets[i]->getYPos(), 
            planets[i]->getXVel(), planets[i]->getYVel(), planets[i]->getMass());
        std::cout << planets[i]->getImageFile() << std::endl;
    }
    std::cout << std::endl;
}
