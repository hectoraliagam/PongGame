#include <raylib.h>
#include "config.h"
#include "ball.h"
#include "PlayerPaddle.h"
#include "CpuPaddle.h"

Ball ball;
PlayerPaddle player;
CpuPaddle cpu;

int main()
{
  InitWindow(Config::screenWidth, Config::screenHeight, "Pong Game");
  SetTargetFPS(Config::FPS);

  while (WindowShouldClose() == false)
  {
    // ===== Updating =====
    ball.Update();
    player.Update();
    cpu.Update(ball.GetCenterY());

    // ===== Drawing =====
    BeginDrawing();
    ClearBackground(Config::darkBlue);

    DrawLine(Config::lineStartPosX, Config::lineStartPosY, Config::lineEndPosX, Config::lineEndPosY, WHITE);
    ball.Draw();
    player.Draw();
    cpu.Draw();

    EndDrawing();
  }

  CloseWindow();
}