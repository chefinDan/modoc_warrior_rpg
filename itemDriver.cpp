#include "Item.hpp"
#include <iostream>

int main()
{
  Item abstractItem("Abstract Item", "This is a test item, it has no special abilities", 10, 3);

  std::cout << abstractItem.getName() << std::endl;

  std::cout << abstractItem.getDescription() << std::endl;

  std::cout << "This requires level " << abstractItem.getLevelReq() << std::endl;

  HealthRestore healthItem("Black Currants", "These tart berries are fairly astringent but contain valuable nutrients ", 3, 1);

  std::cout << healthItem.getName() << std::endl;

  std::cout << healthItem.getDescription() << std::endl;

  std::cout << "This requires level " << healthItem.getLevelReq() << std::endl;
}
