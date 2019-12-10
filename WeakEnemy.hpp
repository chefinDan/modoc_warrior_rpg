/*******************************************************************************
* Author: Daniel Green
* Date: 8/5/2018
* Description: Weak Enemy class definition.
*******************************************************************************/
#ifndef WEAKENEMY_HPP
#define WEAKENEMY_HPP

#include "Character.hpp"

class WeakEnemy : public Character
{
private:
  std::string name;
public:
  WeakEnemy(int arm, int str);
  virtual ~WeakEnemy();

  int attack();
  int defend(int atk);

  virtual std::string &getName();
  virtual void setName(std::string);

};
#endif
