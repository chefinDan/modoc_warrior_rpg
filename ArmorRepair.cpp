#include "Item.hpp"

ArmorRepair::ArmorRepair(std::string name, std::string description, int numOfUses, int levelReq)
{
  this->name = name;
  this->description = description;
  this->numOfUses = numOfUses;
  this->levelReq = levelReq;

}

ArmorRepair::~ArmorRepair()
{

}

void ArmorRepair::useItem()
{

}
