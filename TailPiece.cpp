#include "TailPiece.h"


TailPiece::TailPiece(float xPos, float yPos, std::shared_ptr<TailPiece> priorPiece){
    this->tailSprite = std::make_shared<olc::Sprite>("./graphics/ball2.png");
  this->tailDecal = std::make_shared<olc::Decal>(this->tailSprite.get());
  this->priorPiece = priorPiece;
  this->xPos = xPos;
  this->yPos = yPos;
  this->speed.x = 0;
  this->speed.y = 0;
  this->speed.max = 8.0f;
}

bool TailPiece::hasReachedCheckpoint(){

  return this->reachedCheckpoint;

}


void TailPiece::move(float time){
  this->xPos += this->speed.x*time;
  this->yPos += this->speed.y*time;
}


void TailPiece::update(){

  if (this->xPos -  this->checkpointX < 0.2f &&
      this->xPos - this->checkpointX > -0.2f &&
      this->yPos -  this->checkpointY < 0.2f &&
      this->yPos -  this->checkpointY > -0.2f  )
    {
      this->reachedCheckpoint = true;
    } else {
    this->reachedCheckpoint = false;
    aimForCheckpoint();
  }



}

void TailPiece::aimForCheckpoint(){

  if (this->xPos -this-> checkpointX > 0 ){
    this->speed.x = -this->speed.max;
  }
  if (this->xPos - this-> checkpointX <= 0 ){
    this->speed.x = this->speed.max;
  }
  if (this->yPos -this-> checkpointY > 0 ){
    this->speed.y = -this->speed.max;
  }
  if (this->yPos - this->checkpointY <= 0 ){
    this->speed.y = this->speed.max;
  }

}

void TailPiece::draw(olc::PixelGameEngine* engine){

  engine->DrawDecal({this->xPos ,this->yPos} , tailDecal.get(), {0.05f,0.05f });

}

float TailPiece::getXPos(){
  return this->xPos;
}

float TailPiece::getYPos(){
  return this->yPos;
}

float TailPiece::getCheckpointX(){
  return this->checkpointX;
}

float TailPiece::getCheckpointY(){
  return this->checkpointY;
}

void TailPiece::setCheckpoint(float nextXPos, float nextYPos){
  this->checkpointX = nextXPos;
  this->checkpointY = nextYPos;
}

void TailPiece::setSpeed(float xSpeed, float ySpeed){
  this->speed.x = xSpeed;
  this->speed.y = ySpeed;
}

std::shared_ptr<TailPiece> TailPiece::getPriorPiece(){
  return this->priorPiece;
}
