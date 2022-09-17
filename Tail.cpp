#include "../../olcPixelGameEngine/olcPixelGameEngine.h"
#include <memory>

class Tail {

private:
  int xPos;
  int yPos;
  olc::Sprite* tailSprite = nullptr;
  olc::Decal* tailDecal = nullptr;
  std::shared_ptr<Tail> nextPiece;
  std::shared_ptr<Tail> dummy;
  bool hasNext;
  bool isDummy = false;

public:
  Tail(int xPos, int yPos){
    this->xPos = xPos;
    this->yPos = yPos;
    this->tailSprite = new olc::Sprite("./graphics/ball.png");
    this->tailDecal = new olc::Decal(this->tailSprite);
    this->hasNext = false;
  }
public:
    Tail(){
      this->isDummy = true;
      this->hasNext = false;
    }

public:
  void addTailPiece(int xPos, int yPos){
  this->nextPiece = std::make_shared<Tail>(xPos, yPos);
  std::cout << "Created tailPiece" << "\n";
}



};
