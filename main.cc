#define OLC_PGE_APPLICATION
#include "./../olcPixelGameEngine/olcPixelGameEngine.h"
#include "game.h"

class Example : public olc::PixelGameEngine
{
private:
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
    apple = std::make_shared<Apple>(ScreenWidth(), ScreenHeight());
    return true;
  }

  void keyCheck(std::shared_ptr<Player> p, float time){
    if (GetKey(olc::UP).bHeld){
      p-> moveUp(time);
    }
    if (GetKey(olc::DOWN).bHeld){
      p-> moveDown(time);
    }
    if (GetKey(olc::LEFT).bHeld){
      p->moveLeft(time);
    }
    if (GetKey(olc::RIGHT).bHeld){
      p->moveRight(time);
    }
    if (GetKey(olc::SPACE).bPressed){
      p->stopPlayer();
    }
  }

  bool OnUserUpdate(float fElapsedTime) override{
    SetPixelMode(olc::Pixel::MASK);
    keyCheck(player, fElapsedTime);
    player->onUpdate(ScreenWidth(), ScreenHeight(),apple);
    Clear(olc::DARK_BLUE);
    player->drawPlayer(this);
    Draw(apple->getX(), apple->getY(), olc::Pixel(rand() % 255, rand() % 255, rand()% 255)) ;
    DrawStringDecal({10,10}, std::to_string(apple->getX()),olc::GREEN, {0.1f, 0.1f} );
    DrawStringDecal({10,20}, std::to_string(apple->getY()),olc::GREEN, {0.1f, 0.1f} );
    DrawStringDecal({10,30}, std::to_string(player->getXPosition()),olc::GREEN, {0.1f, 0.1f} );
    DrawStringDecal({10,40}, std::to_string(player->getYPosition()),olc::GREEN, {0.1f, 0.1f} );
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
