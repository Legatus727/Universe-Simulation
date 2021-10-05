CC = g++
CFLAGS = -std=c++11 -g -Wall -Werror -pedantic
OBJECTS = CelestialBody.o Universe.o main.o
EXEC = NBody
SFML = -lsfml-graphics -lsfml-window -lsfml-system

all: $(EXEC)

NBody: CelestialBody.o Universe.o main.o
	$(CC) $(CFLAGS) -o $(EXEC) CelestialBody.o Universe.o main.o $(SFML)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o $(SFML)

CelestialBody.o: CelestialBody.cpp CelestialBody.h
	$(CC) $(CFLAGS) -c CelestialBody.cpp -o CelestialBody.o $(SFML)

Universe.o: Universe.cpp Universe.h
	$(CC) $(CFLAGS) -c Universe.cpp -o Universe.o

clean:
	rm $(OBJECTS) $(EXEC)