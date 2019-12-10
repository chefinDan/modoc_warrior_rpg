#ifndef MAP_HPP
#define MAP_HPP

#include <ctime>
#include <cstdlib>
#include <vector>
#include "utilities.hpp"
#include "Space.hpp"
#include "Character.hpp"
#include "ModocWarrior.hpp"
#include "Inventory.hpp"

class Map
{
public:
  Map();
  virtual ~Map();

  void startSpace();

  void moveLeft();
  void moveRight();
  void moveUp();
  void moveDown();

  void openInventory();
  void checkEnv();
  void stats();

  void fightEnemy();
  bool endGame() {return this->end;}

protected:
  Space *rawCurrentLoc;
  Space *rawSpacePtr;
  Space *rawStartLoc;


  void addLeftSpace(Space*, int);
  void addRightSpace(Space*, int);
  void addUpSpace(Space*, int);
  void addDownSpace(Space*, int);

private:
  void buildMap();

  Character *playerPtr;
  Character *enemyPtr;
  Inventory *satchelPtr;

  bool end;



};
#endif
