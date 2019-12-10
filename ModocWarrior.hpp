/*******************************************************************************
* Author: Daniel Green
* Date: 8/5/2018
* Description: Modoc Warrior class definition.
*******************************************************************************/
#ifndef MODOCWARRIOR_HPP
#define MODOCWARRIOR_HPP

#include "Character.hpp"

class ModocWarrior : public Character
{
private:
  std::string name;
  int steps;
public:
  ModocWarrior(int arm, int str);
  virtual ~ModocWarrior();

  const int &getSteps() { return this->steps; }
  inline void setSteps(int steps) { this->steps = steps; }
  inline void decrimentSteps() {--this->steps;}
  virtual void eat(int);

  int attack();
  int defend(int atk);

  virtual std::string &getName();
  virtual void setName(std::string);


};
#endif
