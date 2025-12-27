#pragma once
#include <raylib.h>

class Ball
{
public:
  Ball(float x, float y, int radius, int speedX, int speedY);

  void Update();
  void Draw() const;
  void Reset();

  Vector2 GetPosition() const;
  int GetRadius() const;

  void ReverseX();

private:
  Vector2 position;
  Vector2 speed;
  int radius;
};