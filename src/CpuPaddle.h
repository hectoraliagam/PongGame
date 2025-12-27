#pragma once
#include "paddle.h"
#include "config.h"

class CpuPaddle : public Paddle
{
public:
  CpuPaddle()
  {
    x = Config::paddleLeftPosX;
    y = Config::paddlePosY;
    width = Config::paddleWidth;
    height = Config::paddleHeight;
    speed = Config::paddleSpeed;
  }

  void Update(float ballY)
  {
    float center = y + height / 2;
    if (center <= ballY)
      y += speed;
    if (center > ballY)
      y -= speed;
    LimitMovement();
  }

  void Update() override {}
};