#include "./../olcPixelGameEngine/olcPixelGameEngine.h"
#include <memory>
#include "Tail.h"


Tail::Tail(){
  this->isDummy = true;
  this->hasNext = false;
}

Tail::Tail(int xPos, int yPos){
  this->xPos = xPos;
  this->yPos = yPos;
  this->tailSprite = new olc::Sprite("./graphics/ball.png");
  this->tailDecal = new olc::Decal(this->tailSprite);
  this->hasNext = false;
}

void Tail::addTailPiece(int xPos, int yPos){
  this->nextPiece = std::make_shared<Tail>(xPos, yPos);
  std::cout << "Created tailPiece" << "\n";
}
void Tail::onUpdate(std::shared_ptr<Player> player){
}
void Tail::drawTail(olc::PixelGameEngine* engine){
  engine->FillCircle(this->xPos, this->yPos, 50*spriteScaleFactor);
}
