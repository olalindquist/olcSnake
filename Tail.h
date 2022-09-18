#pragma once
//#include "Player.h"

class Player;

class Tail {

private:
  const int32_t spriteXSize = 50;
  const int32_t spriteYSize = 50;
  const float spriteScaleFactor = 0.05f;
  int xPos;
  int yPos;
  olc::Sprite* tailSprite = nullptr;
  olc::Decal* tailDecal = nullptr;
  std::shared_ptr<Tail> nextPiece;
  std::shared_ptr<Tail> dummy;
  bool hasNext;
  bool isDummy = false;
public:
  Tail(int xPos, int yPos);
  Tail();
  void addTailPiece(int xPos, int yPos);
  void onUpdate(std::shared_ptr<Player> player);
  void drawTail(olc::PixelGameEngine* engine);
};
