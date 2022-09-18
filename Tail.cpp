#include "./../olcPixelGameEngine/olcPixelGameEngine.h"
#include <memory>
#include "Tail.h"


Tail::Tail()
{
  this->isDummy = true;
  this->hasNext = false;
  this->len = 0;
}

Tail::Tail(int xPos, int yPos){
  this->xPos = xPos;
  this->yPos = yPos;
  this->tailSprite = new olc::Sprite("./graphics/ball.png");
  this->tailDecal = new olc::Decal(this->tailSprite);
  this->len = 0;
  std::cout <<"TailCreate " <<std::to_string(len)<< "\n";
  this->hasNext = false;
}

void Tail::addTailPiece(int xPos, int yPos){
  this->nextPiece = std::make_shared<Tail>(xPos, yPos);
  this->len = this->len +1;
  std::cout << "Created tailPiece" << std::to_string(this->len)<<"\n";
}
void Tail::onUpdate(std::shared_ptr<Player> player){
}
void Tail::drawTail(olc::PixelGameEngine* engine, float x, float y){
  this->xPos = x;
  this->yPos = y;

  if (this->len > 0 ){
    engine->FillCircle(x,y,10, olc::WHITE);
  }
}
