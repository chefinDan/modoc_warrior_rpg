/*******************************************************************************
* Author: Daniel Green
* Date: 8/5/2018
* Description: Character class definition file. Defines a abstract class
* with purely virual functions. Program only uses classes derived from this base.
*******************************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "dice.hpp"


class Character
{
private:
  int atk; // Character stats
  int def;
  int arm;
  int str;
  int buffer; //used during attack and defend to hold dice rolls
  int nrOfDice; //used to control how many times Die::roll() is called

protected:
  Die* dice; //used extensively by all classes. DO NOT TOUCH
             //memory is managed by each Characters attack and defend functions

public:

  Character(int arm, int str);
  virtual ~Character();

  /************* accessors ***************/
  //getters
  const int& getAtk()const { return this->atk; }
  const int& getDef()const { return this->def; }
  const int& getArm()const { return this->arm; }
  const int& getStr()const { return this->str; }
  const int& getNrOfDice()const { return this->nrOfDice; }
  const int& getBuffer()const { return this->buffer; }
  Die* getDice() { return this->dice; }

  //setters
  void setAtkPts(int atk) {this->atk = atk;}
  void setdefPts(int def) {this->def = def;}
  void setArmPts(int arm) {this->arm = arm;}
  void setStrPts(int str) {this->str = str;}
  void setBuffer(int temp) {this->buffer += temp;}
  void setNrOfDice(int n) {this->nrOfDice = n;}
  void setDice(int n, int sides);

  /********* virtual functions *****************/
  virtual int attack() = 0;
  virtual int defend(int atk) = 0;
  virtual std::string &getName() {}
  virtual void setName(std::string){}
  virtual const int &getSteps() {}
  virtual void setSteps(int) {}
  virtual void decrimentSteps() {}
  virtual void eat(int) {}
};
#endif
