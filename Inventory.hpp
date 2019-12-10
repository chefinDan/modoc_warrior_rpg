#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "Item.hpp"
#include <vector>
#include <algorithm>

class Inventory
{
public:
  Inventory(int);
  ~Inventory();

  int getSize();
  bool isEmpty();
  std::vector<Item *>& getItemVector();

  void add(Item *);
  Item* getItem(int);
  Item* removeItem(int);
  void print();



private:
  int maxCap;
  std::vector<Item *> itemVector;
};
#endif
