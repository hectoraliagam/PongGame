#include "Game.hpp"
#include "Colors.hpp"

Game::Game()
    : ball(ScreenWidth / 2, ScreenHeight / 2, 20, 7, 7),
      player(ScreenWidth - 35, ScreenHeight / 2 - 60, 25, 120, 6),
      cpu(10, ScreenHeight / 2 - 60, 25, 120, 6)
{
  InitWindow(ScreenWidth, ScreenHeight, "Pong - Raylib");
  SetTargetFPS(60);
}

void Game::Run()
{
  while (!WindowShouldClose())
  {
    Update();
    Draw();
  }

  CloseWindow();
}

void Game::Update()
{
  ball.Update();
  player.Update();
  cpu.Update(ball.GetPosition().y);

  CheckCollisions();
}

void Game::CheckCollisions()
{
  if (CheckCollisionCircleRec(
          ball.GetPosition(), ball.GetRadius(), player.GetRect()))
  {
    ball.ReverseX();
  }

  if (CheckCollisionCircleRec(
          ball.GetPosition(), ball.GetRadius(), cpu.GetRect()))
  {
    ball.ReverseX();
  }

  if (ball.GetPosition().x < 0)
  {
    playerScore++;
    ball.Reset();
  }

  if (ball.GetPosition().x > ScreenWidth)
  {
    cpuScore++;
    ball.Reset();
  }
}

void Game::Draw()
{
  BeginDrawing();
  ClearBackground(Colors::DarkBlue);

  DrawRectangle(ScreenWidth / 2, 0, ScreenWidth / 2, ScreenHeight, Colors::Neutral);
  DrawCircle(ScreenWidth / 2, ScreenHeight / 2, 150, Colors::LightBlue);
  DrawLine(ScreenWidth / 2, 0, ScreenWidth / 2, ScreenHeight, WHITE);

  ball.Draw();
  player.Draw();
  cpu.Draw();

  DrawText(TextFormat("%i", cpuScore), ScreenWidth / 4 - 20, 20, 80, WHITE);
  DrawText(TextFormat("%i", playerScore), 3 * ScreenWidth / 4 - 20, 20, 80, WHITE);

  EndDrawing();
}