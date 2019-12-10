/*******************************************************************************
* Author: Daniel Green
* Date: 8/5/2018
* Description: Character class implementaion.
*******************************************************************************/
#include "Character.hpp"

//constructor
Character::Character(int arm, int str)
{
  this->atk = 0;
  this->def = 0;
  this->arm = arm;
  this->str = str;
}


Character::~Character()
{

}

void Character::setDice(int n, int sides)
{
  this->buffer = 0;
  this->nrOfDice = n;
  this->dice = new Die(sides);

}
