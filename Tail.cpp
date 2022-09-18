#include "./../olcPixelGameEngine/olcPixelGameEngine.h"
#include <memory>
#include "game.h"

Tail(int xPos, int yPos){
    this->xPos = xPos;
    this->yPos = yPos;
    this->tailSprite = new olc::Sprite("./graphics/ball.png");
    this->tailDecal = new olc::Decal(this->tailSprite);
    this->hasNext = false;
  }

  Tail(){
    this->isDummy = true;
    this->hasNext = false;
  }

  void addTailPiece(int xPos, int yPos){
    this->nextPiece = std::make_shared<Tail>(xPos, yPos);
    std::cout << "Created tailPiece" << "\n";
  }
  void onUpdate(std::shared_ptr<Player> player){

  }
  void drawTail(olc::PixelGameEngine* engine){
    engine->FillCircle(this->xPos, this->yPos, 50*spriteScaleFactor);
    //    engine->DrawDecal({this->xPos,this->yPos} , myDecal, {this->spriteScaleFactor,this->spriteScaleFactor });
  }
