#include "game.h"

Player::Player(float xPosition, float yPosition, float scale){
  playerSprite  = new olc::Sprite("./graphics/head.png");
  myDecal = new olc::Decal(playerSprite);
  this->xPos=xPosition;
  this->yPos=yPosition;
  this->speed.max =8.0f;
  this->tail = std::make_shared<Tail>(0,0);
  this->scale = scale;
}

void Player::stopPlayer(){
  this->speed.x = 0;
  this->speed.y = 0;
}
void Player::drawPlayer(olc::PixelGameEngine* engine, float time){
  engine->DrawDecal({this->xPos,this->yPos} , myDecal, {this->spriteScaleFactor,this->spriteScaleFactor});
  this->tail->drawTail(engine, this->speed.x, this->speed.y, this->xPos, this->yPos, time );
}

bool Player::collidingWithPixel (float objectX, float objectY){
  if (
      objectX > this->xPos  &&
      objectX < this->xPos +25*this->spriteScaleFactor &&
      objectY > this->yPos &&
      objectY < this->yPos+25*this->spriteScaleFactor )
    {
      return true;
    }
  return false;
}

void Player::checkCollision(int maxX, int maxY, std::shared_ptr<Apple> apple) {
  if (this->xPos <= 0) {
    this-> xPos += 2  ;
  }
  if (this-> xPos >= maxX) {
    this-> xPos = maxX -2 ;
  }
  if (this->yPos <= 0){
    this-> yPos = 2 ;
  }
  if  (this-> yPos >= maxY){
    this->yPos = maxY-2;
  }
  if (collidingWithPixel(apple->getX(), apple->Apple::getY() )){
    apple->Apple::refresh();
    this->tail->addTailPiece(this->xPos, this->yPos);
    std::cout <<"Eating apple!"  << "\n";
  }
}

void Player::addTailPiece(){
  this->tail->addTailPiece(this->xPos, this->yPos);
}

void Player::move(float time){
  this->xPos += this-> speed.x*time;
  this->yPos += this-> speed.y*time;
}

void Player::onUpdate( int32_t screenSizeX, int32_t screenSizeY, std::shared_ptr<Apple> apple, float time ){
  this->checkCollision(screenSizeX, screenSizeY,apple);
  this->move(time);
}

float Player::getXPosition(){
  return this->xPos;
}

float Player::getYPosition(){
  return this->yPos;
}

void Player::moveUp(float time){
  if (this->speed.y >= -(this->speed.max)){
    this->speed.y = -speed.max;
    this->speed.x=0;
  }
}

void Player::moveDown(float time){
  if (this->speed.y <= this -> speed.max){
    this->speed.y = speed.max;
    this->speed.x=0;
  }
}

void Player::moveLeft(float time){
  if (this->speed.x >= - (this -> speed.max)){
    this->speed.x =  -speed.max ;
    this->speed.y=0;
  }
}

void  Player::moveRight(float time){
  if (this->speed.x <= this -> speed.max){
    this->speed.x = speed.max;
    this->speed.y=0;
  }
}
