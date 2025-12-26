#pragma once

namespace Config
{
  constexpr int screenWidth = 800;
  constexpr int screenHeight = 600;

  constexpr int FPS = 60;

  constexpr Color darkBlue = {0, 0, 20, 255};

  constexpr int lineStartPosX = screenWidth / 2;
  constexpr int lineStartPosY = 0;
  constexpr int lineEndPosX = screenWidth / 2;
  constexpr int lineEndPosY = screenHeight;

  constexpr int ballRadius = 20;

  constexpr int ballCenterX = screenWidth / 2;
  constexpr int ballCenterY = screenHeight / 2;

  constexpr int paddleWidth = 25;
  constexpr int paddleHeight = 120;

  constexpr int paddlePosY = screenHeight / 2 - paddleHeight / 2;
  constexpr int paddleLeftPosX = 10;
  constexpr int paddleRightPosX = screenWidth - paddleWidth - paddleLeftPosX;
}