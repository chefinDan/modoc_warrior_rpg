CC = g++
objects = Map.o mapDriver.o
objects += Space.o SweatLodge.o Forest.o Forest_2.o MedicineLake.o BlackCrater.o SkullCave.o FrozenAbyss.o endGame.o
objects += Character.o ModocWarrior.o WeakEnemy.o
objects += Inventory.o Item.o
objects += HealthRestore.o ArmorRepair.o WeaponAmmo.o Keys.o
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -g
main = main

default: $(main)

$(main): $(objects)
	$(CC) $(CXXFLAGS) $(objects) -o $(main)

mapDriver.o: mapDriver.cpp Map.hpp
	$(CC) -c mapDriver.cpp

Map.o: Map.cpp Map.hpp
	$(CC) -c Map.cpp

# Map files and related spaces

Space.o: Space.cpp Space.hpp
	$(CC) -c Space.cpp

SweatLodge.o: SweatLodge.cpp Space.hpp
	$(CC) -c SweatLodge.cpp

Forest.o: Forest.cpp Space.hpp
	$(CC) -c Forest.cpp

Forest_2.o: Forest_2.cpp Space.hpp
	$(CC) -c Forest_2.cpp

MedicineLake.o: MedicineLake.cpp Space.hpp
	$(CC) -c MedicineLake.cpp

BlackCrater.o: BlackCrater.cpp Space.hpp
	$(CC) -c BlackCrater.cpp

SkullCave.o: SkullCave.cpp Space.hpp
	$(CC) -c SkullCave.cpp

FrozenAbyss.o: FrozenAbyss.cpp Space.hpp
	$(CC) -c FrozenAbyss.cpp

EndGame.o: EndGame.cpp Space.hpp
	$(CC) -c EndGame.cpp

# Character files #
Character.o: Character.cpp Character.hpp
	$(CC) -c Character.cpp

ModocWarrior.o: ModocWarrior.cpp ModocWarrior.hpp Character.hpp
	$(CC) -c ModocWarrior.cpp

WeakEnemy.o: WeakEnemy.cpp WeakEnemy.hpp Character.hpp
	$(CC) -c WeakEnemy.cpp

# Inventory files including items

Inventory.o: Inventory.cpp Inventory.hpp
	$(CC) -c Inventory.cpp

Item.o: Item.cpp Item.hpp
	$(CC) -c Item.cpp

HealthRestore.o: HealthRestore.cpp Item.hpp
	$(CC) -c HealthRestore.cpp

ArmorRepair.o: ArmorRepair.cpp Item.hpp
	$(CC) -c ArmorRepair.cpp

WeaponAmmo.o:WeaponAmmo.cpp Item.hpp
	$(CC) -c WeaponAmmo.cpp

Keys.o: Keys.cpp Item.hpp
	$(CC) -c Keys.cpp



.PHONY: clean

clean:
	rm *.o *~ $(main)
