/*******************************************************************************
* Author: Daniel Green
* Date: 8/5/2018
* Description: ModocWarrior class implementaion file.
* No special ability.
*******************************************************************************/

#include "ModocWarrior.hpp"
#include "Character.hpp"

ModocWarrior::ModocWarrior(int arm, int str)
  : Character(arm, str)
{
  this->steps = 30;
}

ModocWarrior::~ModocWarrior()
{

}

std::string& ModocWarrior::getName()
{
  return name;
}

void ModocWarrior::setName(std::string name)
{
  this->name = name;
}

void ModocWarrior::eat(int health)
{
  setStrPts(getStr() + health);
  if(getStr() > 20)
  {
    setStrPts(20);
  }
}


int ModocWarrior::attack()
{
  setDice(2, 6);
  std::cout << "**********************************" << std::endl;
  std::cout << getName() << " attacks!" << std::endl;

  // roll the dice
  for (size_t i = 0; i < this->getNrOfDice(); i++)
  {
    dice->roll();
    setBuffer(dice->getResult());
    std::cout << "D" << dice->getN() << ": " << dice->getResult() << std::endl;
  }
  delete dice;

  std::cout << "Total attack: " << getBuffer() << std::endl;
  std::cout << std::endl;
  return getBuffer();

}

int ModocWarrior::defend(int atk)
{
  if(atk < 0)
  {
    std::cout << getName() << " has been turned to stone." << std::endl;
    setStrPts(0);
    return 0;
    // If atk < 0 then the attacker used Glare and the defender dies instantly
  }


  setDice(2, 6);
  std::cout << getName() << " counters! " << std::endl;

  // Roll the dice
  for (size_t i = 0; i < this->getNrOfDice(); i++)
  {
    dice->roll();
    setBuffer(dice->getResult());
    std::cout << "D" << dice->getN() << ": " << dice->getResult() << std::endl;
  }
  delete dice;

  std::cout << "Total defense: " << getBuffer() << std::endl;


  std::cout << "Total damage done to " << getName() << " = ";
  if(atk-getBuffer()-getArm() <= 0)
  {
    if(atk-getBuffer() >0)
    {
      std::cout << "0" << std::endl;
      std::cout << getName() <<  "'s armor absorbed the attack." << std::endl;
      return 0;
    }
    else
    {
      std::cout << "0" << std::endl;
      return 0;
    }
  }
  else
  {
    std::cout << atk << " - " << getBuffer() << " - " << getArm() << " = ";
    std::cout << atk-getBuffer()-getArm() << std::endl;
    setStrPts(getStr() - (atk-getBuffer()-getArm()));
    std::cout << getName() << " now has str: " << getStr() << std::endl;
    return atk-getBuffer()-getArm();
  }
}
