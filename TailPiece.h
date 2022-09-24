#pragma once
#include <memory>
#include "./../olcPixelGameEngine/olcPixelGameEngine.h"

class TailPiece{
private:
  float xPos;
  float yPos;
  float xSpeed;
  float ySpeed;
  std::shared_ptr<olc::Sprite> tailSprite;
  std::shared_ptr<olc::Decal> tailDecal;

public:

  TailPiece(float xPos, float yPos);
  float getXPos();
  float getYPos();
  void move(float newXPos, float newYPos);
  void draw(olc::PixelGameEngine* engine);

};
