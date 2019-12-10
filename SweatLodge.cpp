#include "Space.hpp"

SweatLodge::SweatLodge()
{
  setCleared(false);
  this->up = 0;
  this->down = 0;
  this->left = 0;
  this->right = 0;

  sweatLodgeitems = new Inventory(5);

  enemyPtr = new WeakEnemy(0, 5);
  enemyPtr->setName("Practice Dummy");

  enemyItems = new Inventory(1);
  enemyItems->add(new ArmorRepair("Straw", "", 1, 1));


  getEvent();
}

SweatLodge::~SweatLodge()
{

}

Character* SweatLodge::getEnemy()
{
  return this->enemyPtr;
}

void SweatLodge::wrongWay()
{
  std::cout << "\nIt would be best to not go off trail.";
}

void SweatLodge::repeatLoc()
{
  std::cout << "You return to the Sweatlodge.";
}

void SweatLodge::getEvent()
{
  std::cout << std::string(50, '\n');
  std::cout << "\nYou begin in the sweat Lodge at the center of your village.\nThe purification ritual"
  << " has been completeed and you are ready to journey into the spirit lands.";
  sweatLodgeitems->add(new HealthRestore("Black Currants", "These tart berries are fairly astringent but contain valuable nutrients ", 3, 1));
  sweatLodgeitems->add(new HealthRestore("Oregon Grape", "Sour berries that are better when cooked ", 3, 1));
  sweatLodgeitems->add(new HealthRestore("Dried Fish", "", 5, 1));
  //sweatLodgeitems->add(new HealthRestore("Well Water", "Clean, cool, and absolutely necessary for survival", 5, 1));
  sweatLodgeitems->add(new WeaponAmmo("Obsidian Arrow Heads", "", 10, 3));
  std::cout << "\n\nTo help you on your journey the following items have been added to your pack." << std::endl;
  std::cout << "a:turn left, w:go up, d:turn right, s:go down";
  sweatLodgeitems->print();
}

void SweatLodge::getSurroundings()
{
  std::cout << std::string(50, '\n');
  std::cout << "\n You are inside the sweatlodge, the smell of incense and burning sage fills the air.";
}

void SweatLodge::getTransition()
{
  std::cout << std::string(100, '\n');
}

void SweatLodge::getItems(Inventory *satchelPtr)
{
  while(!sweatLodgeitems->isEmpty())
  {
    satchelPtr->add(sweatLodgeitems->removeItem(0));
  }
  delete sweatLodgeitems;
}

void SweatLodge::getEnemyItems(Inventory* satchelPtr)
{
  if(enemyItems != NULL)
  {
    while(!enemyItems->isEmpty())
    {
      Item *tempItem = enemyItems->removeItem(0);
      std::cout << "\nYou picked up some " << tempItem->getName();
      satchelPtr->add(tempItem);
    }
    delete enemyItems;
    enemyItems = NULL;
  }
}
