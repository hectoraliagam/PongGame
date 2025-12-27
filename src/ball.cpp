#include "Ball.hpp"
#include "Colors.hpp"

Ball::Ball(float x, float y, int r, int speedX, int speedY)
    : position{x, y}, speed{(float)speedX, (float)speedY}, radius(r)
{
}

void Ball::Update()
{
  position.x += speed.x;
  position.y += speed.y;

  if (position.y + radius >= GetScreenHeight() || position.y - radius <= 0)
    speed.y *= -1;
}

void Ball::Draw() const
{
  DrawCircleV(position, radius, Colors::Gray);
}

void Ball::Reset()
{
  position = {
      GetScreenWidth() / 2.0f,
      GetScreenHeight() / 2.0f};

  speed.x *= (GetRandomValue(0, 1) ? 1 : -1);
  speed.y *= (GetRandomValue(0, 1) ? 1 : -1);
}

void Ball::ReverseX()
{
  speed.x *= -1;
}

Vector2 Ball::GetPosition() const
{
  return position;
}

int Ball::GetRadius() const
{
  return radius;
}