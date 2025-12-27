#include "Paddle.hpp"

Paddle::Paddle(float x, float y, float w, float h, float s)
    : position{x, y}, size{w, h}, speed(s)
{
}

void Paddle::Update()
{
  if (IsKeyDown(KEY_UP))
    position.y -= speed;
  if (IsKeyDown(KEY_DOWN))
    position.y += speed;

  LimitMovement();
}

void Paddle::Draw() const
{
  DrawRectangleRounded(
      {position.x, position.y, size.x, size.y},
      0.8f, 0, WHITE);
}

void Paddle::LimitMovement()
{
  if (position.y < 0)
    position.y = 0;

  if (position.y + size.y > GetScreenHeight())
    position.y = GetScreenHeight() - size.y;
}

Rectangle Paddle::GetRect() const
{
  return {position.x, position.y, size.x, size.y};
}