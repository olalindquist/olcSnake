#pragma once

#include "./../olcPixelGameEngine/olcPixelGameEngine.h"
#include <memory>
#include "TailList.h"
#include "TailPiece.h"

class Player;
class TailList;
class TailPiece;

class Tail {

private:
  std::shared_ptr<Player> player;
  std::shared_ptr<TailList> tailList;
  const int32_t spriteXSize = 50;
  const int32_t spriteYSize = 50;
  const float spriteScaleFactor = 0.05f;
  int32_t xPos;
  int32_t yPos;
  float xSpeed;
  float ySpeed;
  int32_t len;
  olc::Sprite* tailSprite = nullptr;
  olc::Decal* tailDecal = nullptr;
  std::shared_ptr<Tail> nextPiece;
  std::shared_ptr<Tail> dummy;
  bool hasNext;
  bool isDummy = false;

  void compensate(std::shared_ptr<TailListNode> node, float priorPieceX, float PriorPieceY,float xPos,float yPos, float xSpeed, float ySpeed);


public:
  //  Tail(int xPos, int yPos);

  Tail(float xSpeed, float ySpeed);
  void addTailPiece(int xPos, int yPos);
  void onUpdate(std::shared_ptr<Player> player);
  void drawTail(olc::PixelGameEngine* engine, float x, float y, float  xPos, float yPos);
};
