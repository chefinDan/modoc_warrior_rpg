#include "ModocWarrior.hpp"
#include "Inventory.hpp"
#include <iostream>

int main()
{
  bool repeat = true;
  char again;
  int i = 0;
  std::srand(time(NULL));

  ModocWarrior warrior1(5, 100);
  ModocWarrior warrior2(5, 10);

  Inventory satchel(10);
  Item *itm = new HealthRestore("Black Currants", "These tart berries are fairly astringent but contain valuable nutrients ", 3, 1);
  Item *itm1 = new ArmorRepair("Tule Grass", "A bundle of thick grass used to weave clothing and mats", 1, 1);

  satchel.add(itm);
  satchel.add(itm1);

  satchel.print();

  int item_number;
  char ans;
  std::cout << "Remove an item?(y/n): ";
  std::cin >> ans;
  if(ans=='y')
  {
    std::cout << "Select an item to remove" << std::endl;
    satchel.print();
    std::cout << ": ";
    std::cin >> item_number;
    Item *temp = satchel.removeItem(item_number);
    std::cout << "Removed " << temp->getName() << std::endl;
  }

  satchel.print();



  // while(repeat == true)
  //
  // {
  //
  // std::cout << std::endl;
  // std::cout << "Round: " << i++ << std::endl;
  // warrior2.defend(warrior1.attack());
  // warrior1.defend(warrior2.attack());
  // if(warrior1.getStr() <1)
  // {
  //   std::cout << "warrior2 killed warrior1";
  //   repeat = false;
  // }
  // else if(warrior2.getStr() <1)
  // {
  //   std::cout << "warrior1 killed warrior2";
  //   repeat = false;
  // }
  // else
  // {
  //   std::cout << "Press enter to fight again:";
  //   std::cin.get(again);
  // }
  // }



  return 0;
}
