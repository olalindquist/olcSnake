#pragma once
#include <memory>
#include "./../olcPixelGameEngine/olcPixelGameEngine.h"

class TailPiece{
private:

  float xPos;
  float yPos;
  float xSpeed;
  float ySpeed;
  float checkpointX;
  float checkpointY;
  bool  reachedCheckpoint;

  std::shared_ptr<olc::Sprite> tailSprite;
  std::shared_ptr<olc::Decal> tailDecal;
  std::shared_ptr<TailPiece> priorPiece;

public:

  TailPiece(float xPos, float yPos, std::shared_ptr<TailPiece> priorPiece);
  void setSpeed(float xSpeed, float ySpeed);
  float getXPos();
  float getYPos();
  void move();
  void draw(olc::PixelGameEngine* engine);
  float getCheckpointX();
  float getCheckpointY();
  void setCheckpoint(float nextXPos, float nextYPos);
  bool hasReachedCheckpoint();
  std::shared_ptr<TailPiece> getPriorPiece();
};
