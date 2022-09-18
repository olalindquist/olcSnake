#include "game.h"

Apple::Apple(int32_t x, int32_t y){
  this->length =x;
  this->height = y;
  this->xPos = rand()% this->length;
  this->yPos = rand() % this->height;
}

int32_t Apple::getX(){
  return this->xPos;
}
int32_t Apple::getY(){
  return this->yPos;
}

void Apple::refresh(){
  this->xPos = rand()% this->length;
  this->yPos = rand() % this->height;
}
