#include "Item.hpp"

WeaponAmmo::WeaponAmmo(std::string name, std::string description, int numOfUses, int levelReq)
{
  this->name = name;
  this->description = description;
  this->numOfUses = numOfUses;
  this->levelReq = levelReq;

}

WeaponAmmo::~WeaponAmmo()
{

}

void WeaponAmmo::useItem()
{

}
