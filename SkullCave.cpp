#include "Space.hpp"

SkullCave::SkullCave(bool cleared, Space* left, Space* right, Space* up, Space* down)
{
  this->up = up;
  this->down = down;
  this->left = left;
  this->right = right;
  setCleared(cleared);

  skullCaveItems = new Inventory(1);
  skullCaveItems->add(new ArmorRepair("Diamond speckled Rock", "", 1, 3));

  enemyPtr = new WeakEnemy(0, 30);
  enemyPtr->setName("Colony of Vampire Bats");

  enemyItems = new Inventory(1);
  enemyItems->add(new ArmorRepair("Worthless bat shit", "", 1, 1));

  this->spaceCount = 0;
}

SkullCave::~SkullCave()
{

}

Character* SkullCave::getEnemy()
{
  return this->enemyPtr;
}

void SkullCave::getEvent()
{

}

void SkullCave::getSurroundings()
{
  std::cout << std::string(50, '\n');
  std::cout << "\nTo your left is the glowing entrance to Skull Cave.\n"
             << "Behind you is cold depths of Skull Cave.\n"
             << "To your right is the smooth limstone cave wall.\n"
             << "Up ahead is the remains of an ancient cave-in.\n";
}

void SkullCave::wrongWay()
{
  std::cout << "\nIt appears the only way forward is deeper into the cave.";
}

void SkullCave::repeatLoc()
{
  std::cout << "\nYou return to the gaping mouth of BlackCrater.";
}

void SkullCave::getTransition()
{
  std::cout << std::string(100, '\n');
  this->spaceCount += 1;
  if(spaceCount == 1)
    std::cout << "You make your way to the mouth of the cavern and enter.\n"
    << "As you enter Skull Cave you notice the temperature drop. A chilling screech echoes from within\n"
    << "the dark recesses of the cave.";
  else if(spaceCount > 1)
    std::cout << "You continue onward by the faint glow of daylight";
}

void SkullCave::getItems(Inventory *satchelPtr)
{
  if(skullCaveItems != NULL)
  {

    while(!skullCaveItems->isEmpty())
    {
      Item *tempItem = skullCaveItems->removeItem(0);
      std::cout << "\n\nOn the cave wall you find a: " << tempItem->getName();
      satchelPtr->add(tempItem);
    }
    delete skullCaveItems;
    skullCaveItems = NULL;
  }
}

void SkullCave::getEnemyItems(Inventory* satchelPtr)
{
  if(enemyItems != NULL)
  {
    while(!enemyItems->isEmpty())
    {
      Item *tempItem = enemyItems->removeItem(0);
      std::cout << "\nYou picked up a " << tempItem->getName();
      satchelPtr->add(tempItem);
    }
    delete enemyItems;
    enemyItems = NULL;
  }
}
