#include "Space.hpp"

MedicineLake::MedicineLake(bool cleared, Space* left, Space* right, Space* up, Space* down)
{
  this->up = up;
  this->down = down;
  this->left = left;
  this->right = right;
  setCleared(cleared);


  medicineLakeItems = new Inventory(1);
  medicineLakeItems->add(new WeaponAmmo("Fishing Lure", "", 1, 3));

  enemyPtr = new WeakEnemy(0, 12);
  enemyPtr->setName("Huge Lake Trout");

  enemyItems = new Inventory(1);
  enemyItems->add(new Keys("A strange green orb", "", 1, 1));

  this->spaceCount = 0;


}

MedicineLake::~MedicineLake()
{

}

Character* MedicineLake::getEnemy()
{
  return this->enemyPtr;
}

void MedicineLake::getEvent()
{
  std::cout << "\nYou stand on the edge of a irridecent "
  << "lake surrounded by jagged lava formations.";
}

void MedicineLake::getSurroundings()
{
  std::cout << std::string(50, '\n');
  std::cout << "\n To your left is the forest that you just came from.\n"
            << " Behind you is miles and miles of windswept earth, covered with strange alien lava formations .\n"
            << " To your right is Medicine Lake, an oasis of cool water. Fish are jumping.\n"
            << " Up ahead the land grows steeper, the trail is heading toward a overlook.\n";

}

void MedicineLake::wrongWay()
{
  std::cout << "\nIt would be best to not go off trail.";
}

void MedicineLake::repeatLoc()
{
  std::cout << "You return to banks of Medicine Lake.";
}

void MedicineLake::getTransition()
{
  std::cout << std::string(100, '\n');
  this->spaceCount += 1;
  if(spaceCount == 1)
    std::cout << "You come to the edge of the woods, the cool breeze tells you that water is nearby.";
  else if(spaceCount > 1)
    std::cout << "You continue onward.";
}

void MedicineLake::getItems(Inventory *satchelPtr)
{
  if(medicineLakeItems != NULL)
  {

    while(!medicineLakeItems->isEmpty())
    {
      Item *tempItem = medicineLakeItems->removeItem(0);
      std::cout << "\n\nPerched against a rock on the edge of Medicine Lake you find a: " << tempItem->getName();
      satchelPtr->add(tempItem);
    }
    delete medicineLakeItems;
    medicineLakeItems = NULL;
  }
}

void MedicineLake::getEnemyItems(Inventory* satchelPtr)
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
