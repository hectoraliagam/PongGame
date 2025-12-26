#pragma once

class Ball
{
public:
  Ball();
  void Update();
  void Draw() const;

private:
  int x;
  int y;
  int radius;
  int speedX;
  int speedY;
};