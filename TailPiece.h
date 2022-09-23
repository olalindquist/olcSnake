#pragma once
#include <memory>
#include "./../olcPixelGameEngine/olcPixelGameEngine.h"

class TailPiece{
 private:
  float xPos;
  float yPos;
  float xSpeed;
  float ySpeed;
  void draw(olc::PixelGameEngine* engine);

 public:
  TailPiece(float xPos, float yPos);


};
