#include "Space.hpp"

Forest_2::Forest_2(bool cleared, Space* left, Space* right, Space* up, Space* down)
{
  this->up = up;
  this->down = down;
  this->left = left;
  this->right = right;
  setCleared(cleared);

  forest_2Items = new Inventory(1);
  forest_2Items->add(new ArmorRepair("Eagle Feathers", "", 1, 3));

  enemyPtr = new WeakEnemy(0, 10);
  enemyPtr->setName("Mule Deer");

  enemyItems = new Inventory(1);
  enemyItems->add(new ArmorRepair("Deer Antlers", "", 1, 1));

  this->spaceCount = 0;

}
Forest_2::Forest_2()
{
  setCleared(false);
  this->up = 0;
  this->down = 0;
  this->left = 0;
  this->right = 0;

}

Forest_2::~Forest_2()
{

}


Character* Forest_2::getEnemy()
{
  return this->enemyPtr;
}


void Forest_2::getEvent()
{

}


void Forest_2::getSurroundings()
{
  std::cout << std::string(50, '\n');
  std::cout << "\nTo your left is an open meadow, possibly with a stream.\n"
             << "Behind you is the trail you have been following.\n"
             << "To your right you can see the faint shimmer of water.\n"
             << "Up ahead is nothing but miles of rough Forest land.\n";
}

void Forest_2::wrongWay()
{
  std::cout << "\nIt would be best to not go off trail, there could more Coy Wolves out there";
}

void Forest_2::repeatLoc()
{
  std::cout << "You return to the deep forest.";
}

void Forest_2::getTransition()
{
  std::cout << std::string(100, '\n');
  this->spaceCount += 1;
  if(spaceCount == 1)
    std::cout << "\nThe forest grows deeper. All you can hear is the sound of your footsteps.";
  else if(spaceCount > 1)
    std::cout << "You continue onward.";
}

void Forest_2::getItems(Inventory *satchelPtr)
{
  if(forest_2Items != NULL)
  {

    while(!forest_2Items->isEmpty())
    {
      Item *tempItem = forest_2Items->removeItem(0);
      std::cout << "\n\nLying on the Forest floor you found: " << tempItem->getName();
      satchelPtr->add(tempItem);
    }
    delete forest_2Items;
    forest_2Items = NULL;
  }
}

void Forest_2::getEnemyItems(Inventory* satchelPtr)
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
