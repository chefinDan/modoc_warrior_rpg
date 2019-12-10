#include "Map.hpp"

Map::Map()
{
    std::srand(time(NULL));
    rawCurrentLoc = 0;
    rawSpacePtr = 0;
    rawStartLoc = 0;

    playerPtr = new ModocWarrior(1, 20);
    playerPtr->setName("Modoc Warrior");

    satchelPtr = new Inventory(15);
    end = false;

    buildMap();
}

Map::~Map()
{

  Space* temp = rawStartLoc;
  Space* garbage = temp;
  temp = temp->left;
  delete garbage;

  garbage = temp;
  temp = temp->up;
  delete garbage;

  garbage = temp;
  temp = temp->right;
  delete garbage;

  garbage = temp;
  temp = temp->up;
  delete garbage;

  garbage = temp;
  temp = temp->right;
  delete garbage;

  garbage = temp;
  temp = temp->down;
  delete garbage;

  garbage = temp;
  temp = temp->down;
  delete garbage;

  garbage = temp;
  temp = temp->down;
  delete garbage;

  delete satchelPtr;
  delete playerPtr;

}


void Map::buildMap()
{
  int buildRoom;

  rawStartLoc = new SweatLodge();

  rawSpacePtr = rawStartLoc;

  addLeftSpace(rawSpacePtr, 1); //forest
  addUpSpace(rawSpacePtr, 2); //forest_2
  addRightSpace(rawSpacePtr, 3); //lake
  addUpSpace(rawSpacePtr, 4); //BlackCrater
  addRightSpace(rawSpacePtr, 5); //Skull Cave
  addDownSpace(rawSpacePtr, 6); //FrozenAbyss
  addDownSpace(rawSpacePtr, 7); //endGame


  rawCurrentLoc = rawStartLoc;
}

void Map::addLeftSpace(Space* room, int level)
{
  if(room->left == 0)
  {
    if(level == 1) { room->left = new Forest(false, 0, room, 0, 0);}
    else if(level == 2) { room->left = new Forest_2(false, 0, room, 0, 0);}
    else if(level == 3) { room->left = new MedicineLake(false, 0, room, 0, 0);}
    else if(level == 4) { room->left = new BlackCrater(false, 0, room, 0, 0);}
    else if(level == 5) { room->left = new SkullCave(false, 0, room, 0, 0);}
    else if(level == 6) { room->left = new FrozenAbyss(false, 0, room, 0, 0);}
    else { room->left = new EndGame(false, 0, 0, 0, 0);}

    rawSpacePtr = room->left;
    return;
  }
  std::cout << "\nA room already exists here.";
  return;
}

void Map::addRightSpace(Space* room, int level)
{
  if(room->right == 0)
  {
    if(level == 1) { room->right = new Forest(false, room, 0, 0, 0);}
    else if(level == 2) { room->right = new Forest_2(false, room, 0, 0, 0);}
    else if(level == 3) { room->right = new MedicineLake(false, room, 0, 0, 0);}
    else if(level == 4) { room->right = new BlackCrater(false, room, 0, 0, 0);}
    else if(level == 5) { room->right = new SkullCave(false, room, 0, 0, 0);}
    else if(level == 6) { room->right = new FrozenAbyss(false, room, 0, 0, 0);}
    else { room->right = new EndGame(false, 0, 0, 0, 0);}

    rawSpacePtr = room->right;
    return;
  }
  std::cout << "\nA room already exists here.";
  return;
}

void Map::addUpSpace(Space* room, int level)
{
  if(room->up == 0)
  {
    if(level == 1) { room->up = new Forest(false, 0, 0, 0, room);}
    else if(level == 2) { room->up = new Forest_2(false, 0, 0, 0, room);}
    else if(level == 3) { room->up = new MedicineLake(false, 0, 0, 0, room);}
    else if(level == 4) { room->up = new BlackCrater(false, 0, 0, 0, room);}
    else if(level == 5) { room->up = new SkullCave(false, 0, 0, 0, room);}
    else if(level == 6) { room->up = new FrozenAbyss(false, 0, 0, 0, room);}
    else { room->up = new EndGame(false, 0, 0, 0, 0);}

    rawSpacePtr = room->up;
    return;
  }
  std::cout << "\nA room already exists here.";
  return;
}

void Map::addDownSpace(Space* room, int level)
{
  if(room->down == 0)
  {
    if(level == 1) { room->down = new Forest(false, 0, 0, room, 0);}
    else if(level == 2) { room->down = new Forest_2(false, 0, 0, room, 0);}
    else if(level == 3) { room->down = new MedicineLake(false, 0, 0, room, 0);}
    else if(level == 4) { room->down = new BlackCrater(false, 0, 0, room, 0);}
    else if(level == 5) { room->down = new SkullCave(false, 0, 0, room, 0);}
    else if(level == 6) { room->down = new FrozenAbyss(false, 0, 0, room, 0);}
    else { room->down = new EndGame(false, 0, 0, room, 0);}


    rawSpacePtr = room->down;
    return;
  }
  std::cout << "\nA room already exists here.";
  return;
}


/****** move functions *************************/
void Map::startSpace()
{
    rawSpacePtr = rawCurrentLoc;
    rawSpacePtr->getItems(satchelPtr);
}

void Map::moveLeft()
{
  rawSpacePtr = rawCurrentLoc;
  playerPtr->decrimentSteps();

  if(rawSpacePtr->left != 0)
  {

    rawSpacePtr = rawSpacePtr->left;
    rawSpacePtr->getTransition();

    if(rawSpacePtr->getCleared() == true)
    {
      rawCurrentLoc = rawSpacePtr;
      rawSpacePtr->repeatLoc();
      return;
    }
    rawSpacePtr->getEvent();
    rawSpacePtr->getItems(satchelPtr);

    rawCurrentLoc->setCleared(true);
    rawSpacePtr->setCleared(true);
    rawCurrentLoc = rawSpacePtr;

    return;
  }
  else
  {
      fightEnemy();
      rawSpacePtr->setCleared(true);
      rawSpacePtr->getEnemyItems(satchelPtr);
      return;
  }
}


void Map::moveRight()
{
  rawSpacePtr = rawCurrentLoc;
  playerPtr->decrimentSteps();

  if(rawSpacePtr->right != 0)
  {

    rawSpacePtr = rawSpacePtr->right;
    rawSpacePtr->getTransition();

    if(rawSpacePtr->getCleared() == true)
    {
      rawCurrentLoc = rawSpacePtr;
      rawSpacePtr->repeatLoc();
      return;
    }
    rawSpacePtr->getEvent();
    rawSpacePtr->getItems(satchelPtr);

    rawCurrentLoc->setCleared(true);
    rawSpacePtr->setCleared(true);
    rawCurrentLoc = rawSpacePtr;
    return;
  }
  else
  {
      fightEnemy();
      rawSpacePtr->setCleared(true);
      rawSpacePtr->getEnemyItems(satchelPtr);
      return;
  }
}

void Map::moveUp()
{
  rawSpacePtr = rawCurrentLoc;
  playerPtr->decrimentSteps();

  if(rawSpacePtr->up != 0)
  {

    rawSpacePtr = rawSpacePtr->up;
    rawSpacePtr->getTransition();

    if(rawSpacePtr->getCleared() == true)
    {
      rawCurrentLoc = rawSpacePtr;
      rawSpacePtr->repeatLoc();
      return;
    }
    rawSpacePtr->getEvent();
    rawSpacePtr->getItems(satchelPtr);

    rawCurrentLoc->setCleared(true);
    rawSpacePtr->setCleared(true);
    rawCurrentLoc = rawSpacePtr;

    return;
  }
  else
  {
      fightEnemy();
      rawSpacePtr->setCleared(true);
      rawSpacePtr->getEnemyItems(satchelPtr);
      return;
  }
}


void Map::moveDown()
{
  rawSpacePtr = rawCurrentLoc;
  playerPtr->decrimentSteps();

  if(rawSpacePtr->down != 0)
  {

      if((rawSpacePtr->down)->getIsEnd() == true)
      {
        if(satchelPtr->getSize() == 1)
        {
          std::cout << "\nYou have won the game.!";
          this->end = true;
          return;
        }
        else
        {
          std::cout << "\nCannot enter the spirit realm without the key.";
          return;
        }
      }

    rawSpacePtr = rawSpacePtr->down;
    rawSpacePtr->getTransition();

    if(rawSpacePtr->getCleared() == true)
    {
      rawCurrentLoc = rawSpacePtr;
      rawSpacePtr->repeatLoc();
      return;
    }
    rawSpacePtr->getEvent();
    rawSpacePtr->getItems(satchelPtr);

    rawCurrentLoc->setCleared(true);
    rawSpacePtr->setCleared(true);
    rawCurrentLoc = rawSpacePtr;

    return;
  }
  else
  {
      fightEnemy();
      rawSpacePtr->setCleared(true);
      rawSpacePtr->getEnemyItems(satchelPtr);
      return;
  }
}


void Map::openInventory()
{
  satchelPtr->print();
}

void Map::checkEnv()
{
  rawSpacePtr = rawCurrentLoc;
  rawSpacePtr->getSurroundings();
}

void Map::stats()
{
  char ans;
  std::cout << std::string(50, '\n');
  std::cout << "Health: " << playerPtr->getStr() << "\n";
  std::cout << "Armor: " << playerPtr->getArm() << "\n";
  std::cout << "Steps Remaining: " << playerPtr->getSteps() << std::endl;

  std::cout << "Eat food to restore Health?(y/n): ";
  std::cin.get(ans);
  if(ans == 'y' || ans == 'Y')
  {
    int itm;
    //std::cout << std::string(50, '\n');
    satchelPtr->print();
    std::cout << "Select a food item to eat: ";
    itm = getValidInt(0, satchelPtr->getSize() - 1);

    Item* temp = satchelPtr->removeItem(itm);
    playerPtr->eat(temp->getNumOfUses());

    std::cout << "Health is now: " << playerPtr->getStr();
  }
  std::cin.clear();
  std::cin.ignore(100, '\n');
}

void Map::fightEnemy()
{
  rawSpacePtr = rawCurrentLoc;

  if((rawSpacePtr->getEnemy())->getStr() < 1)
  {
    std::cout << "\nBlood splatter marks the ground. There is nothing more this way. ";
    return;
  }

  std::cout << std::string(50, '\n');
  std::cout << "\nA " << (rawSpacePtr->getEnemy())->getName() << " appears suddenly!!";

  char again;
  std::cout << "\n\nPress enter to fight: ";
  std::cin.get(again);
  while((rawSpacePtr->getEnemy())->getStr() > 0)
  {
    (rawSpacePtr->getEnemy())->defend(playerPtr->attack());
    if((rawSpacePtr->getEnemy())->getStr() < 1)
    {
      std::cout << "\n\nThe " << rawSpacePtr->getEnemy()->getName() << " falls to ground dead.";
      return;
    }
    playerPtr->defend((rawSpacePtr->getEnemy())->attack());
    std::cout << "Press enter to attack again: ";
    std::cin.get(again);
    std::cout << std::string(30, '\n');
  }
}
