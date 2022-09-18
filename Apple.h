#pragma once
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
