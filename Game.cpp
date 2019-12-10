#include "Game.hpp"

void Game::Game()
{

}

void Game::removeItem()
{
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
}
