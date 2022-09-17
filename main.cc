#define OLC_PGE_APPLICATION
#include "./../../olcPixelGameEngine/olcPixelGameEngine.h"
#include <memory>
//#include "../olcPixelGameEngine/olcPixelGameEngine.h"
#include <memory>

#include "Apple.cpp"
#include "Player.cpp"

class Example : public olc::PixelGameEngine
{
private:
  /*
  const int32_t spriteXSize = 50;
  const int32_t spriteYSize = 50;

  olc::Decal* myDecal = nullptr;
  olc::Sprite* playerSprite = nullptr;

  */
  const float spriteScaleFactor = 0.05f;
  std::shared_ptr<Player> player = nullptr;
  std::shared_ptr<Apple> apple = nullptr;

public:
  Example()
  {
    sAppName = "Example";
  }
public:
  bool OnUserCreate() override
  {

    player = std::make_shared<Player>(10,10, this->spriteScaleFactor);
        /*
   playerSprite  = new olc::Sprite("./graphics/ball.png");
 myDecal = new olc::Decal(playerSprite);
    */
   apple = std::make_shared<Apple>(ScreenWidth(), ScreenHeight());
   //playerSprite = std::make_shared<olc::Sprite> ("./graphics/ball.png");
   //this->myDecal = std::make_shared <olc::Decal>(*&playerSprite);
   //   myDecal = new olc::Decal(playerSprite);
   // Called once at the start, so create things here
    return true;
  }

  void keyCheck(std::shared_ptr<Player> p, float time){
    if (GetKey(olc::UP).bPressed){
      p->moveUp(time);
    }
    if (GetKey(olc::DOWN).bPressed){
      p->moveDown(time);
    }
    if (GetKey(olc::LEFT).bPressed){
      p->moveLeft(time);
    }
    if (GetKey(olc::RIGHT).bPressed){
      p->moveRight(time);
    }
  }

  bool OnUserUpdate(float fElapsedTime) override{
    SetPixelMode(olc::Pixel::MASK);
    keyCheck(player, fElapsedTime);
    player->onUpdate(ScreenWidth(), ScreenHeight(),apple);
    Clear(olc::DARK_BLUE);

    //     DrawDecal({player->getXPosition(),player->getYPosition()}, myDecal, {this->spriteScaleFactor,this->spriteScaleFactor });
    player->drawPlayer(this);
    Draw(apple->getX(), apple->getY(), olc::Pixel(rand() % 255, rand() % 255, rand()% 255)) ;



    DrawString(10,10, std::to_string(apple->getX()) );
    DrawString(10,20, std::to_string (apple->getY()) );
    DrawString(10,30, std::to_string(player->getXPosition() ) );
    DrawString(10,40, std::to_string (player->getYPosition()));
      return true;
  }
};

int main()
{
  int32_t screenSizeX = 64;
  int32_t screenSizeY = 64;
  int pixelSize =20;
  Example demo;
  if (demo.Construct(screenSizeX,screenSizeY, pixelSize,pixelSize))
    demo.Start();
  return 0;
}
