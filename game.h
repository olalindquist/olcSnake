#pragma once
#include "./../olcPixelGameEngine/olcPixelGameEngine.h"
#include <memory>


class Apple{
 private:
  int32_t xPos;
  int32_t yPos;
  int32_t length;
  int32_t height;
 public:
  Apple(int32_t x, int32_t y);
  int32_t getX();
  int32_t getY();
  void refresh();
    };

//********************************************************

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
  void checkCollision(int maxX, int maxY, std::shared_ptr<Apple> apple);
  bool collidingWithPixel (float objectX, float objectY);
  void stopPlayer();
  void move();

    public:
  Player(float xPosition, float yPosition, float scale);
  void drawPlayer(olc::PixelGameEngine* engine);
  void onUpdate( int32_t screenSizeX, int32_t screenSizeY, std::shared_ptr<Apple> apple );
  float  getXPosition();
  float getYPosition();
  void moveUp(float time);
  void moveDown(float time);
  void moveLeft(float time);
  void moveRight(float time);
};

//*************************************************************


class Tail{
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
