#include "ball.h"
#include "raylib.h"
#include "config.h"

Ball::Ball()
    : x(Config::ballCenterX),
      y(Config::ballCenterY),
      radius(Config::ballRadius),
      speedX(Config::ballSpeedX),
      speedY(Config::ballSpeedY)
{
}

void Ball::Update()
{
  x += speedX;
  y += speedY;
}

void Ball::Draw() const
{
  DrawCircle(x, y, radius, WHITE);
}