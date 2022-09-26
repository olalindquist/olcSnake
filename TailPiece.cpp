#include "TailPiece.h"


TailPiece::TailPiece(float xPos, float yPos, std::shared_ptr<TailPiece> priorPiece){
    this->tailSprite = std::make_shared<olc::Sprite>("./graphics/ball.png");
  this->tailDecal = std::make_shared<olc::Decal>(this->tailSprite.get());
  this->priorPiece = priorPiece;
  this->xPos = xPos;
  this->yPos = yPos;
  this->xSpeed=0;
  this->ySpeed=0;
}

bool TailPiece::hasReachedCheckpoint(){

  return this->reachedCheckpoint;
}

void TailPiece::move(){

 if (this->xPos -  this->checkpointX < 0.1f && this->xPos - this->checkpointX > -0.1f ){
    this->reachedCheckpoint = true;
    this->setCheckpoint(this->checkpointX, this->checkpointY);
  }

 if (this->yPos -  this->checkpointY < 0.1f && this->yPos -  this->checkpointY > -0.1f ){

    this->reachedCheckpoint = true;
    this->setCheckpoint(this->checkpointX, this->checkpointY);
  }

  this->reachedCheckpoint = false;

  if (this->xPos - this->checkpointX < 3  ) {
    this->xPos += 0.02f;
  }

  if (this->xPos - this->checkpointX >= 3  ){

    this->xPos -= 0.02f;
  }

  if (this->yPos - this->checkpointY < 3  ) {
    this->yPos += 0.02f;
  }
  if (this->yPos - this->checkpointY >= 3  ){
    this->yPos -= 0.02f;
  }
}
void TailPiece::draw(olc::PixelGameEngine* engine){

  engine->DrawDecal({this->xPos ,this->yPos} , tailDecal.get(), {0.05f,0.05f });

}

float TailPiece::getXPos(){
  return this->yPos;
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
  this->xSpeed = xSpeed;
  this->ySpeed = ySpeed;
}

std::shared_ptr<TailPiece> TailPiece::getPriorPiece(){
  return this->priorPiece;
}
