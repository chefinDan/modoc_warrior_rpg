#include "Inventory.hpp"

Inventory::Inventory(int cap)
{
    this->maxCap = cap;
}

Inventory::~Inventory()
{

}

int Inventory::getSize()
{
  return itemVector.size();
}

bool Inventory::isEmpty()
{
  return itemVector.size() == 0;
}

std::vector<Item *> &Inventory::getItemVector()
{
  return itemVector;
}

void Inventory::add(Item *itm)
{
  if(itemVector.size() + 1 > maxCap)
  {
    std::cout << "\nCannot add " << itm->getName() << ", your inventory is full." << std::endl;
  }
    itemVector.push_back(itm);
}


Item* Inventory::removeItem(int i)
{
  if(itemVector.empty())
  {
    std::cout << "Your satchel is empty" << std::endl;
    return 0;
  }

  Item* itm = itemVector.at(i);
  itemVector.erase(itemVector.begin() + i);
  return itm;
}

void Inventory::print()
{
    if(itemVector.empty())
    {
      std::cout << std::string(50, '\n');
      std::cout << "Your bag is empty" << std::endl;
      return;
    }
    else
    {
      std::cout << "\n\n   ****** Inventory ******    \n\n";
      for(int i = 0; i < itemVector.size(); ++i)
        std::cout << "  " << i << ". " <<  (itemVector.at(i))->getName() << " x" << (itemVector.at(i))->getNumOfUses() << std::endl;
    }
}

Item* Inventory::getItem(int i)
{
  return itemVector.at(i);
}
