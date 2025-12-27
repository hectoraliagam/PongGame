#pragma once
#include "paddle.h"
#include "config.h"

class PlayerPaddle : public Paddle
{
public:
  PlayerPaddle()
  {
    x = Config::paddleRightPosX;
    y = Config::paddlePosY;
    width = Config::paddleWidth;
    height = Config::paddleHeight;
    speed = Config::paddleSpeed;
  }

  void Update() override
  {
    if (IsKeyDown(KEY_UP))
      y -= speed;
    if (IsKeyDown(KEY_DOWN))
      y += speed;
    LimitMovement();
  }
};