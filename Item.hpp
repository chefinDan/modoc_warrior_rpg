#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <iostream>

class Item
{
public:
  Item(std::string name = "NULL", std::string description = "NULL", int numOfUses = 0, int levelReq = 0);
  ~Item();

  const std::string& getName();
  void setName(std::string);
  const std::string& getDescription();
  void setDescription(std::string);
  const int& getLevelReq();
  void setLevelReq(int);
  const int& getNumOfUses();
  void setNumOfUses(int);

  virtual void useItem();


protected:
  std::string name;
  std::string description;
  int levelReq;
  int numOfUses;
};

class HealthRestore : public Item
{
public:
  HealthRestore(std::string name = "NULL", std::string description = "NULL", int numOfUses = 0, int levelReq = 0);
  ~HealthRestore();

  virtual void useItem();
};

class ArmorRepair : public Item
{
public:
  ArmorRepair(std::string name = "NULL", std::string description = "NULL", int numOfUses = 0, int levelReq = 0);
  ~ArmorRepair();

  virtual void useItem();
};

class WeaponAmmo : public Item
{
public:
  WeaponAmmo(std::string name = "NULL", std::string description = "NULL", int numOfUses = 0, int levelReq = 0);
  ~WeaponAmmo();

  virtual void useItem();
};

class Keys : public Item
{
public:
  Keys(std::string name = "NULL", std::string description = "NULL", int numOfUses = 0, int levelReq = 0);
  ~Keys();

  virtual void useItem();
};
#endif
