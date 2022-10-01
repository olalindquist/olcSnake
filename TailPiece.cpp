#include "TailPiece.h"


TailPiece::TailPiece(float xPos, float yPos, std::shared_ptr<TailPiece> priorPiece){
    this->tailSprite = std::make_shared<olc::Sprite>("./graphics/ball2.png");
  this->tailDecal = std::make_shared<olc::Decal>(this->tailSprite.get());
  this->priorPiece = priorPiece;
  this->xPos = xPos;
  this->yPos = yPos;
  this->speed.x = 0;
  this->speed.y = 0;
  this->speed.max = 0.05f;
}

bool TailPiece::hasReachedCheckpoint(){

  return this->reachedCheckpoint;

}


void TailPiece::move(){
  this->xPos += this->speed.x;
  this->yPos += this->speed.y;
}


void TailPiece::update(){

  if (this->xPos -  this->checkpointX < 0.2f &&
      this->xPos - this->checkpointX > -0.2f &&
      this->yPos -  this->checkpointY < 0.2f &&
      this->yPos -  this->checkpointY > -0.2f  )
    {
      this->reachedCheckpoint = true;
    } else {
    aimForCheckpoint();
  }

  this->move();

}

void TailPiece::aimForCheckpoint(){
  //xDirectin
  if (this->xPos -this-> checkpointX > 0 ){
    this->speed.x = -0.01f;
  }
  if (this->xPos - this-> checkpointX <= 0 ){
    this->speed.x = 0.01f;
  }
  if (this->yPos -this-> checkpointY > 0 ){
    this->speed.y = -0.01f;
  }
  if (this->yPos - this-> checkpointY <= 0 ){
    this->speed.y = 0.01f;
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

void TailPiece::setCheckpoint(float nextXPos, float nextYPos, float xspeed, float yspeed){

  this->checkpointX = nextXPos;
  this->checkpointY = nextYPos;
  //  this->speed.x = (nextXPos-this->xPos)/(nextYPos-this->yPos);
  // this->speed.y = (nextYPos-this->yPos)/(nextXPos-this->xPos);


}

void TailPiece::setSpeed(float xSpeed, float ySpeed){
  this->speed.x = xSpeed;
  this->speed.y = ySpeed;
}

std::shared_ptr<TailPiece> TailPiece::getPriorPiece(){
  return this->priorPiece;
}
