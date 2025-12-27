#include "raylib.h"
#include "config.h"
#include "ball.h"

Ball::Ball()
    : x(Config::ballCenterX),
      y(Config::ballCenterY),
      radius(Config::ballRadius),
      speedX(Config::ballSpeedX),
      speedY(Config::ballSpeedY)
{
}

float Ball::GetCenterY() const
{
  return y + radius;
}

void Ball::Update()
{
  x += speedX;
  y += speedY;

  if (x + radius >= GetScreenWidth() || x - radius <= 0)
  {
    speedX *= -1;
  }
  if (y + radius >= GetScreenHeight() || y - radius <= 0)
  {
    speedY *= -1;
  }
}

void Ball::Draw() const
{
  DrawCircle(x, y, radius, WHITE);
}