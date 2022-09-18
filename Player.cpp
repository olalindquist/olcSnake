#include "game.h"

Player::Player(float xPosition, float yPosition, float scale){
  playerSprite  = new olc::Sprite("./graphics/ball.png");
  myDecal = new olc::Decal(playerSprite);
  this->xPos=xPosition;
  this->yPos=yPosition;
  this->xSpeed = 0;
  this->ySpeed = 0;
  //  this->tail = std::make_shared<Tail>();
  this->scale = scale;
}

void Player::stopPlayer(){
  this->xSpeed = 0;
  this->ySpeed = 0;
}

void Player::drawPlayer(olc::PixelGameEngine* engine){
  engine->DrawDecal({this->xPos,this->yPos} , myDecal, {this->spriteScaleFactor,this->spriteScaleFactor });
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
    stopPlayer();
    //    addTailPiece();
    std::cout <<"Eating apple!"  << "\n";
  }

}


/*void Player::addTailPiece(){



} */

void Player::move(){
  this->xPos += this-> xSpeed;
  this->yPos += this-> ySpeed;
}

void Player::onUpdate( int32_t screenSizeX, int32_t screenSizeY, std::shared_ptr<Apple> apple ){
  this->checkCollision(screenSizeX, screenSizeY,apple);
  this->move();
}

float Player::getXPosition(){
  return this->xPos;
}

float Player::getYPosition(){
  return this->yPos;
}

void Player::moveUp(float time){
  this->xSpeed = 0;
  this->ySpeed = -1*speed;
}

void Player::moveDown(float time){
  this->xSpeed = 0;
  this->ySpeed = speed;
}

void Player::moveLeft(float time){
  this->xSpeed = -1*speed;
  this->ySpeed = 0;
}

void  Player::moveRight(float time){
  this->xSpeed = speed;
  this->ySpeed = 0;
}
