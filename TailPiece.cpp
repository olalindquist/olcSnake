#include "TailPiece.h"

TailPiece::TailPiece(float xPos, float yPos){
  this->tailSprite = std::make_shared<olc::Sprite>("./graphics/ball.png");
  this->tailDecal = std::make_shared<olc::Decal>(this->tailSprite.get());
  this->xPos =xPos;
  this->yPos = yPos;
}

void TailPiece::move(float newXPos, float newYPos){
  this->xPos = newXPos;
  this->yPos = newYPos;
}

void TailPiece::draw(olc::PixelGameEngine* engine){
  engine->DrawDecal({this->xPos,this->yPos} , tailDecal.get(), {0.05f,0.05f });

  }

float TailPiece::getXPos(){
  return this->xPos;
}

float TailPiece::getYPos(){
  return this->yPos;
}
