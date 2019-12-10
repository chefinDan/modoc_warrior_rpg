#include "Space.hpp"

BlackCrater::BlackCrater(bool cleared, Space* left, Space* right, Space* up, Space* down)
{
  this->up = up;
  this->down = down;
  this->left = left;
  this->right = right;
  setCleared(cleared);


  blackCraterItems = new Inventory(1);
  blackCraterItems->add(new ArmorRepair("Ashes", "", 1, 3));

  enemyPtr = new WeakEnemy(2, 30);
  enemyPtr->setName("Wild Black Bear");

  enemyItems = new Inventory(1);
  enemyItems->add(new ArmorRepair("Bear Fat", "", 5, 1));

  this->spaceCount = 0;
}

BlackCrater::~BlackCrater()
{

}

Character* BlackCrater::getEnemy()
{
  return this->enemyPtr;
}

void BlackCrater::getEvent()
{
}

void BlackCrater::getSurroundings()
{
  std::cout << std::string(50, '\n');
  std::cout << "\nYou wander the barren caldera of an ancient volcano.";
  std::cout << "\n\nTo your left is the steep wall of the Black Crater.\n"
             << "Looking behind, you can see the glimmering surface of Medicine Lake.\n"
             << "Across the crater to the right is a large cavern.\n"
             << "Up ahead is the northen wall of the caldera.\n";
}

void BlackCrater::wrongWay()
{
  std::cout << "\nIt appears the only way forward is into the cavern.";
}

void BlackCrater::repeatLoc()
{
  std::cout << "You return to the smoldering caldera of Black Crater.";
}

void BlackCrater::getTransition()
{
  std::cout << std::string(100, '\n');
  this->spaceCount += 1;
  if(spaceCount == 1)
    std::cout << "You slowly make your way of the steep slopes of Black Crater,"
    << " the loose cinder cone surface slips under your feet.";
  else if(spaceCount > 1)
    std::cout << "You continue onward.";
}

void BlackCrater::getItems(Inventory *satchelPtr)
{
  if(blackCraterItems != NULL)
  {

    while(!blackCraterItems->isEmpty())
    {
      Item *tempItem = blackCraterItems->removeItem(0);
      std::cout << "\n\nSpread across the black ground you found: " << tempItem->getName();
      satchelPtr->add(tempItem);
    }
    delete blackCraterItems;
    blackCraterItems = NULL;
  }
}

void BlackCrater::getEnemyItems(Inventory* satchelPtr)
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
