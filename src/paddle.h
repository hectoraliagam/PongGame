#pragma once
#include <raylib.h>

class Paddle
{
public:
  virtual ~Paddle() = default;
  virtual void Update() = 0;
  void Draw() const
  {
    DrawRectangle(x, y, width, height, WHITE);
  }

protected:
  float x{};
  float y{};
  float width{};
  float height{};
  float speed{};
  void LimitMovement()
  {
    if (y <= 0)
      y = 0;
    if (y + height >= GetScreenHeight())
      y = GetScreenHeight() - height;
  }
};