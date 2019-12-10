#include "Map.hpp"
//Author: Daniel green
//This is my game, I made it too complicated. oh well. 



int main()
{
  bool play = false;
  int choice;

  std::cout << std::string(100, '\n');
  std::cout << " **** Welcome to the first ever Modoc Indian Warrior RPG game ****\n\n"
            << "The goal of this game is to travel to the spirit lands. Where that is?\n You will have to explore to find out.";
            std::cout << "When you start the game you will have an inventory of items, and stats.\n";
            std::cout << "Explore the land with w,a,s,d and eat food to replenish health.";
            std::cout << "\n\n1. Play Game\n2. Exit:";
            choice = getValidInt(1,2);

if(choice == 1) {play = true;}
if(choice == 2) {return 0;}

  char ans;
  std::cout << "\nUse w, a, s, d controls to move.\n";
  std::cin.clear();
  std::cin.ignore(100, '\n');

Map game;
while(play == true)
{
  game.startSpace();
  while(game.endGame() == false)
  {
    std::cin.get(ans);
    std::cin.clear();
    std::cin.ignore(100, '\n');

    switch (ans)
    {
      case 119:
      {
        game.moveUp();
        break;
      }
      case 97:
      {
        game.moveLeft();
        break;
      }
      case 115:
      {
        game.moveDown();
        break;
      }
      case 100:
      {
        game.moveRight();
        break;
      }
      case 105:
      {
        game.openInventory();
        break;
      }
      case 101:
      {
        game.checkEnv();
        break;
      }
      case 122:
      {
        game.stats();
        break;
      }
      default:
        std::cout << "\nEnter only lower case w,a,s,d,i,e,z ";
    }
    std::cout << "\n\n---------------------------------------------------------";
    std::cout << "\nUse w, a, s, d controls to move.\n";
    std::cout << "Open Inventory: i    Check Environment: e    Stats: z" << std::endl;
  }
}

  return 0;
}
