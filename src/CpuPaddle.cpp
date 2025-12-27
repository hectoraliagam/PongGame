#include "CpuPaddle.hpp"

void CpuPaddle::Update(float ballY)
{
  float center = position.y + size.y / 2;

  if (center > ballY)
    position.y -= speed;
  if (center < ballY)
    position.y += speed;

  LimitMovement();
}