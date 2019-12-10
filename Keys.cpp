#include "Item.hpp"

Keys::Keys(std::string name, std::string description, int numOfUses, int levelReq)
{
  this->name = name;
  this->description = description;
  this->numOfUses = numOfUses;
  this->levelReq = levelReq;

}

Keys::~Keys()
{

}

void Keys::useItem()
{

}
