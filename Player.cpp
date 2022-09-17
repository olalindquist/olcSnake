#include "../../olcPixelGameEngine/olcPixelGameEngine.h"
#include <memory>
#include "Tail.cpp"


class Player{

private:


  const int32_t spriteXSize = 50;
  const int32_t spriteYSize = 50;
  const float spriteScaleFactor = 0.05f;
  olc::Decal* myDecal = nullptr;
  olc::Sprite* playerSprite = nullptr;


  float const speed = 0.02f;
  float xSpeed;
  float ySpeed;
  float xPos;
  float yPos;
  float scale;
  std::shared_ptr<Tail> tail = nullptr;

public:
  Player(float xPosition, float yPosition, float scale){
    playerSprite  = new olc::Sprite("./graphics/ball.png");
    myDecal = new olc::Decal(playerSprite);
    this->xPos=xPosition;
    this->yPos=yPosition;
    this->xSpeed = 0;
    this->ySpeed = 0;
    this->tail = std::make_shared<Tail>();
    this->scale = scale;
  }

public:
   void drawPlayer(olc::PixelGameEngine* engine){
     //  engine->FillCircle(this->xPos, this->yPos, 2);
 engine->DrawDecal({this->xPos,this->yPos} , myDecal, {this->spriteScaleFactor,this->spriteScaleFactor });
  }

private:
  void checkCollision(int maxX, int maxY, std::shared_ptr<Apple> apple) {
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



    if (std::trunc (this -> yPos) == apple-> getY()-2 &&

        std::trunc (this -> xPos) == apple-> getX() )
      {
        std::cout << "Found! " << std::to_string(this->xPos)<<"  "<< std::to_string(this->yPos)  << "\n";
      apple->refresh();

      }
  }

private:
  void move(){
    this->xPos += this-> xSpeed;
    this->yPos += this-> ySpeed;
  }

public:
  void onUpdate( int32_t screenSizeX, int32_t screenSizeY, std::shared_ptr<Apple> apple ){
    this->checkCollision(screenSizeX, screenSizeY,apple);
    this->move();
  }

public:
  float  getXPosition(){
    return this->xPos;
}
public:
float getYPosition(){
  return this->yPos;
}

public:
  void moveUp(float time){
    this->xSpeed = 0;
    this->ySpeed = -1*speed;
  }
  void moveDown(float time){
    this->xSpeed = 0;
    this->ySpeed = speed;
  }
  void moveLeft(float time){
    this->xSpeed = -1*speed;
    this->ySpeed = 0;
  }
  void  moveRight(float ime){
    this->xSpeed = speed;
    this->ySpeed = 0;
  }
};
