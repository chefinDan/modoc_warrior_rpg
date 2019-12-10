#include "Item.hpp"

Item::Item(
    std::string name,
    std::string description, 
    int numOfUses, 
    int levelReq
  )
  : 
  name(name), 
  description(description), 
  numOfUses(numOfUses), 
  levelReq(levelReq)
{

}

Item::~Item()
{

}

const std::string& Item::getName()
{
  return this->name;
}

void Item::setName(std::string name)
{
  this->name = name;
}

const std::string& Item::getDescription()
{
  return this->description;
}

void Item::setDescription(std::string descript)
{
  this->description = descript;
}

const int& Item::getLevelReq()
{
  return this->levelReq;
}

void Item::setLevelReq(int levelReq)
{
  this->levelReq = levelReq;
}

const int& Item::getNumOfUses()
{
  return this->numOfUses;
}

void Item::setNumOfUses(int numOfUses)
{
  this->numOfUses = numOfUses;
}

void Item::useItem()
{

}
