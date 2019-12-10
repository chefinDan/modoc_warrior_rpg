#include "Space.hpp"

Forest::Forest(bool cleared, Space* left, Space* right, Space* up, Space* down)
{
  this->up = up;
  this->down = down;
  this->left = left;
  this->right = right;

  
  setCleared(cleared);

  forestItems = new Inventory(1);
  forestItems->add(new ArmorRepair("kindling", "", 1, 3));

  enemyPtr = new WeakEnemy(0, 10);
  enemyPtr->setName("Rabid CoyWolf");

  enemyItems = new Inventory(1);
  enemyItems->add(new ArmorRepair("CoyWolf Pelt", "", 1, 1));

  this->spaceCount = 0;

}
Forest::Forest()
{
  setCleared(false);
  this->up = 0;
  this->down = 0;
  this->left = 0;
  this->right = 0;

}

Forest::~Forest()
{

}


Character* Forest::getEnemy()
{
  return this->enemyPtr;
}


void Forest::getEvent()
{
  std::cout << "\nYou are in a sparse forest, piles of black rocks dot the landscape.";
}


void Forest::getSurroundings()
{
  std::cout << std::string(50, '\n');
  std::cout << "\nTo your left is what appears to be a trail, possibly used by wild game.\n"
             << "Behind you is a large patch of Sage Brush, it's rustling and making strange noises.\n"
             << "To your right you can see the your camp, a fire has been made.\n"
             << "Up ahead is nothing but miles of rough forest land.\n";
}

void Forest::wrongWay()
{
  std::cout << "\nIt would be best to not go off trail.";
}

void Forest::repeatLoc()
{
  std::cout << "\nYou return to the edge of the forest.";
}

void Forest::getTransition()
{
  std::cout << std::string(100, '\n');
  this->spaceCount += 1;
  if(spaceCount == 1)
    std::cout << "You walk toward the rising sun, deep into woods.";
  else if(spaceCount > 1)
    std::cout << "You continue onward.";
}

void Forest::getItems(Inventory *satchelPtr)
{
  if(forestItems != NULL)
  {

    while(!forestItems->isEmpty())
    {
      Item *tempItem = forestItems->removeItem(0);
      std::cout << "\n\nLying on the forest floor you found: " << tempItem->getName();
      satchelPtr->add(tempItem);
    }
    delete forestItems;
    forestItems = NULL;
  }
}

void Forest::getEnemyItems(Inventory* satchelPtr)
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
