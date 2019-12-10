#ifndef SPACE_HPP
#define SPACE_HPP

#include <memory>
#include <iostream>
#include <string>
#include <algorithm>
#include "ModocWarrior.hpp"
#include "WeakEnemy.hpp"
#include "Inventory.hpp"

class Space
{
public:
  Space(bool cleared, Space* left, Space* right, Space* up, Space* down);
  Space();

  virtual ~Space();

  Space* up;
  Space* down;
  Space* left;
  Space* right;

  bool getCleared() const;
  void setCleared(bool);

  Space* getRoomDir();

  virtual void getTransition() = 0;
  virtual void getEvent() = 0;
  virtual void getSurroundings() = 0;
  virtual void wrongWay() = 0;
  virtual void repeatLoc() = 0;
  virtual void getItems(Inventory*) = 0;
  virtual void getEnemyItems(Inventory*) = 0;
  virtual Character* getEnemy() = 0;
  virtual bool getIsEnd() = 0;

private:
  bool cleared;

};


class SweatLodge : public Space
{
public:
  SweatLodge();

  virtual ~SweatLodge();

  virtual void getTransition();
  virtual void getEvent();
  virtual void getSurroundings();
  virtual void wrongWay();
  virtual void repeatLoc();
  virtual void getItems(Inventory*);
  virtual void getEnemyItems(Inventory*);
  virtual Character* getEnemy();
  virtual bool getIsEnd() {return false; }

private:
  Inventory *sweatLodgeitems;
  Inventory *enemyItems;
  Character *enemyPtr;

};

class Forest : public Space
{
public:
  Forest(bool cleared, Space* left, Space* right, Space* up, Space* down);
  Forest();

  virtual ~Forest();

  virtual void getTransition();
  virtual void getEvent();
  virtual void getSurroundings();
  virtual void wrongWay();
  virtual void repeatLoc();
  virtual void getItems(Inventory*);
  virtual void getEnemyItems(Inventory*);
  virtual Character* getEnemy();
  virtual bool getIsEnd() {return false; }
private:

  Inventory *forestItems;
  Inventory *enemyItems;
  Character *enemyPtr;

  int spaceCount;

};
class Forest_2 : public Space
{
public:
  Forest_2(bool cleared, Space* left, Space* right, Space* up, Space* down);
  Forest_2();

  virtual ~Forest_2();

  virtual void getTransition();
  virtual void getEvent();
  virtual void getSurroundings();
  virtual void wrongWay();
  virtual void repeatLoc();
  virtual void getItems(Inventory*);
  virtual void getEnemyItems(Inventory*);
  virtual Character* getEnemy();
  virtual bool getIsEnd() {return false; }

private:
  Inventory *forest_2Items;
  Inventory *enemyItems;
  Character *enemyPtr;

  int spaceCount;

};

class MedicineLake : public Space
{
public:
  MedicineLake(bool cleared, Space* left, Space* right, Space* up, Space* down);
  MedicineLake();

  virtual ~MedicineLake();

  virtual void getTransition();
  virtual void getEvent();
  virtual void getSurroundings();
  virtual void wrongWay();
  virtual void repeatLoc();
  virtual void getItems(Inventory*);
  virtual void getEnemyItems(Inventory*);
  virtual Character* getEnemy();
  virtual bool getIsEnd() {return false; }

private:
  Inventory *medicineLakeItems;
  Inventory *enemyItems;
  Character *enemyPtr;

  int spaceCount;

  //virtual Space* getRoomDir();

};


class BlackCrater : public Space
{
public:
  BlackCrater(bool cleared, Space* left, Space* right, Space* up, Space* down);
  BlackCrater();

  virtual ~BlackCrater();

  virtual void getTransition();
  virtual void getEvent();
  virtual void getSurroundings();
  virtual void wrongWay();
  virtual void repeatLoc();
  virtual void getItems(Inventory*);
  virtual void getEnemyItems(Inventory*);
  virtual bool getIsEnd() {return false; }

  virtual Character* getEnemy();

private:
  Inventory *blackCraterItems;
  Inventory *enemyItems;
  Character *enemyPtr;

  int spaceCount;

};


class SkullCave : public Space
{
public:
  SkullCave(bool cleared, Space* left, Space* right, Space* up, Space* down);
  SkullCave();

  virtual ~SkullCave();

  virtual void getTransition();
  virtual void getEvent();
  virtual void getSurroundings();
  virtual void wrongWay();
  virtual void repeatLoc();
  virtual void getItems(Inventory*);
  virtual void getEnemyItems(Inventory*);
  virtual bool getIsEnd() {return false; }

  virtual Character* getEnemy();

private:
  Inventory *skullCaveItems;
  Inventory *enemyItems;
  Character *enemyPtr;

  int spaceCount;

  //virtual Space* getRoomDir();

};

class FrozenAbyss : public Space
{
public:
  FrozenAbyss(bool cleared, Space* left, Space* right, Space* up, Space* down);
  FrozenAbyss();

  virtual ~FrozenAbyss();

  virtual void getTransition();
  virtual void getEvent();
  virtual void getSurroundings();
  virtual void wrongWay();
  virtual void repeatLoc();
  virtual void getItems(Inventory*);
  virtual void getEnemyItems(Inventory*);
  virtual bool getIsEnd() {return false; }

  virtual Character* getEnemy();

private:
  Inventory *frozenAbyssItems;
  Inventory *enemyItems;
  Character *enemyPtr;

  int spaceCount;

  //virtual Space* getRoomDir();

};

class EndGame : public Space
{
public:
  EndGame(bool cleared, Space* left, Space* right, Space* up, Space* down);
  EndGame();

  virtual ~EndGame();

  virtual void getTransition();
  virtual void getEvent();
  virtual void getSurroundings();
  virtual void wrongWay();
  virtual void repeatLoc();
  virtual void getItems(Inventory*);
  virtual void getEnemyItems(Inventory*);
  inline virtual bool getIsEnd() { return true; }

  virtual Character* getEnemy();

private:
  Inventory *endGameItems;
  Inventory *enemyItems;
  Character *enemyPtr;

  int spaceCount;

  //virtual Space* getRoomDir();

};
#endif
