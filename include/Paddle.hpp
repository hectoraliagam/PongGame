#pragma once
#include <raylib.h>

class Paddle
{
public:
  Paddle(float x, float y, float w, float h, float speed);

  virtual void Update();
  void Draw() const;

  Rectangle GetRect() const;

protected:
  void LimitMovement();

  Vector2 position;
  Vector2 size;
  float speed;
};