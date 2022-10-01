#pragma once
#include <memory>
#include "./../olcPixelGameEngine/olcPixelGameEngine.h"

class TailPiece{
private:

  float xPos;
  float yPos;

  struct {
    float max;
    float x;
    float y;
  } speed;

  float checkpointX;
  float checkpointY;
  bool  reachedCheckpoint;

  std::shared_ptr<olc::Sprite> tailSprite;
  std::shared_ptr<olc::Decal> tailDecal;
  std::shared_ptr<TailPiece> priorPiece;
  void aimForCheckpoint();

public:
  TailPiece(float xPos, float yPos, std::shared_ptr<TailPiece> priorPiece);
  void setSpeed(float xSpeed, float ySpeed);

  float getXPos();
  float getYPos();
  void move();
  void update();
  void draw(olc::PixelGameEngine* engine);

  float getCheckpointX();
  float getCheckpointY();
  void setCheckpoint(float nextXPos, float nextYPos, float xSpeed, float ySpeed); //TODO
  bool hasReachedCheckpoint();
  std::shared_ptr<TailPiece> getPriorPiece();
};
