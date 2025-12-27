#pragma once
#include "Paddle.hpp"

class CpuPaddle : public Paddle
{
public:
  using Paddle::Paddle;
  void Update(float ballY);
};