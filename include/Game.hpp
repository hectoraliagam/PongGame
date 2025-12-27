#pragma once
#include "Ball.hpp"
#include "Paddle.hpp"
#include "CpuPaddle.hpp"

class Game
{
public:
  Game();
  void Run();

private:
  void Update();
  void Draw();
  void CheckCollisions();

private:
  Ball ball;
  Paddle player;
  CpuPaddle cpu;

  int playerScore = 0;
  int cpuScore = 0;

  static constexpr int ScreenWidth = 1280/3*2;
  static constexpr int ScreenHeight = 800/3*2;
};