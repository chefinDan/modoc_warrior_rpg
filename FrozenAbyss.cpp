#include "Space.hpp"

FrozenAbyss::FrozenAbyss(bool cleared, Space* left, Space* right, Space* up, Space* down)
{
  this->up = up;
  this->down = down;
  this->left = left;
  this->right = right;
  setCleared(cleared);


  frozenAbyssItems = new Inventory(1);
  frozenAbyssItems->add(new ArmorRepair("Pure crystal", "", 100, 3));

  enemyPtr = new WeakEnemy(0, 30);
  enemyPtr->setName("Ancient Demon");

  enemyItems = new Inventory(1);
  enemyItems->add(new ArmorRepair("Key to the Door of Spirits", "", 1, 1));

  this->spaceCount = 0;
}

FrozenAbyss::~FrozenAbyss()
{

}

Character* FrozenAbyss::getEnemy()
{
  return this->enemyPtr;
}

void FrozenAbyss::getEvent()
{
}

void FrozenAbyss::getSurroundings()
{
  std::cout << std::string(50, '\n');
  std::cout << "\nTo your left is darkness.\n"
            << "Up ahead is the cold depths of Skull Cave.\n"
            << "To your right is darkness.\n"
            << "Behind you is is a glowing red light.\n";
}

void FrozenAbyss::wrongWay()
{
  std::cout << "\nIt appears the only way forward is toward the red light.";
}

void FrozenAbyss::repeatLoc()
{
  // std::cout << "\nYou return to the gaping mouth of BlackCrater.";
}

void FrozenAbyss::getTransition()
{
  std::cout << std::string(100, '\n');
  this->spaceCount += 1;
  if(spaceCount == 1)
  {
    std::cout << "As you step over large boulders the light dims to blackness.\n";
    std::cout << "The air is chilling to the bone and you notice that the strange green orb begins to glow.";
  }
  else if(spaceCount > 1)
    std::cout << "\nYou continue onward by the glow of the green orb";
}

void FrozenAbyss::getItems(Inventory *satchelPtr)
{
  if(frozenAbyssItems != NULL)
  {

    while(!frozenAbyssItems->isEmpty())
    {
      Item *tempItem = frozenAbyssItems->removeItem(0);
      std::cout << "\n\nYou trip over a rock, you pick it up and find that its a: " << tempItem->getName();
      satchelPtr->add(tempItem);
    }
    delete frozenAbyssItems;
    frozenAbyssItems = NULL;
  }
}

void FrozenAbyss::getEnemyItems(Inventory* satchelPtr)
{
  while(!satchelPtr->isEmpty())
  {
    satchelPtr->removeItem(0);
  }

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
