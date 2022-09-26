#pragma once
//#include "Apple.h"
#include "Tail.h"

class Apple;
class Tail;

class Player{
 private:
  const int32_t spriteXSize = 50;
  const int32_t spriteYSize = 50;
  const float spriteScaleFactor = 0.05f;
  olc::Decal* myDecal = nullptr;
  olc::Sprite* playerSprite = nullptr;
  std::shared_ptr<Tail> tail = nullptr;
  float const speed = 0.02f;
  float xSpeed;
  float ySpeed;
  float xPos;
  float yPos;
  float scale;

  void checkCollision(int maxX, int maxY, std::shared_ptr<Apple> apple);
  void addTailPiece();
  bool collidingWithPixel (float objectX, float objectY);
  void stopPlayer();
  void move();

public:
  Player(float xPosition, float yPosition, float scale);
  void drawPlayer(olc::PixelGameEngine* engine);
  void onUpdate( int32_t screenSizeX, int32_t screenSizeY, std::shared_ptr<Apple> apple );
  float getXPosition();
  float getYPosition();
  void moveUp(float time);
  void moveDown(float time);
  void moveLeft(float time);
  void moveRight(float time);
};
