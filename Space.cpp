#include "Space.hpp"

Space::Space(bool cleared, Space* left, Space* right, Space* up, Space* down)
{
  this->up = up;
  this->down = down;
  this->left = left;
  this->right = right;
  this->cleared = cleared;
}

Space::Space()
{
  this->cleared = false;
  this->up = 0;
  this->down = 0;
  this->left = 0;
  this->right = 0;
}

Space::~Space()
{

}

void Space::getEvent()
{
  if(getCleared() == true)
  {
    std::cout << "\nYou have already been here.";
  }
  else
  {
    std::cout << "\nThis is a new space.";
  }
}

void Space::getSurroundings()
{
  
}

void Space::setCleared(bool cleared)
{
  this->cleared = cleared;
}

bool Space::getCleared() const
{
  return cleared;
}

Space* Space::getRoomDir()
{
  if(left != 0) { return left; }
  if(right != 0) { return right; }
  if(up != 0) { return up; }
  if(down != 0) { return down; }
  else {return 0;}
}
