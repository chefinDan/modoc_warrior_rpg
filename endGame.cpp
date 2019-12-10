#include "Space.hpp"

EndGame::EndGame(bool cleared, Space* left, Space* right, Space* up, Space* down)
{
  this->up = up;
  this->down = down;
  this->left = left;
  this->right = right;
  setCleared(cleared);

  endGameItems = NULL;

  enemyPtr = NULL;

  enemyItems = NULL;

  this->spaceCount = 0;
}

EndGame::~EndGame()
{

}

Character* EndGame::getEnemy()
{
  return this->enemyPtr;
}

void EndGame::getEvent()
{

}

void EndGame::getSurroundings()
{

}

void EndGame::wrongWay()
{

}

void EndGame::repeatLoc()
{

}

void EndGame::getTransition()
{

}

void EndGame::getItems(Inventory *satchelPtr)
{

}

void EndGame::getEnemyItems(Inventory* satchelPtr)
{

}
