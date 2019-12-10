/*******************************************************************************
* Author: Daniel Green
* Date: 8/5/2018
* Description: WeakEnemy class implementaion file.
* No special ability.
*******************************************************************************/

#include "WeakEnemy.hpp"
#include "Character.hpp"

WeakEnemy::WeakEnemy(int arm, int str)
  : Character(arm, str)
{

}

WeakEnemy::~WeakEnemy()
{

}

std::string& WeakEnemy::getName()
{
  return name;
}

void WeakEnemy::setName(std::string name)
{
  this->name = name;
}


int WeakEnemy::attack()
{
  setDice(1, 10);
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

int WeakEnemy::defend(int atk)
{
  if(atk < 0)
  {
    std::cout << getName() << " has been turned to stone." << std::endl;
    setStrPts(0);
    return 0;
    // If atk < 0 then the attacker used Glare and the defender dies instantly
  }


  setDice(1, 10);
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
