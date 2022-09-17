#include "../../olcPixelGameEngine/olcPixelGameEngine.h"
#include <memory>


class Apple{

private:
  int32_t xPos;
  int32_t yPos;
  int32_t length;
  int32_t height;


public:
  Apple(int32_t x, int32_t y){
    this->length =x;
    this->height = y;
    this->xPos = rand()% this->length;
    this->yPos = rand() % this->height;
  }

public:
  int32_t getX(){
    return this->xPos;
  }
  int32_t getY(){
    return this->yPos;
  }
public:
  void refresh(){
    this->xPos = rand()% this->length;
    this->yPos = rand() % this->height;
  }
};
