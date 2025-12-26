#include <raylib.h>
#include "config.h"

int main()
{
    InitWindow(Config::screenWidth, Config::screenHeight, "Pong Game");
    SetTargetFPS(Config::FPS);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(Config::darkBlue);

        DrawLine(Config::lineStartPosX, Config::lineStartPosY, Config::lineEndPosX, Config::lineEndPosY, WHITE);
        DrawCircle(Config::ballCenterX, Config::ballCenterY, Config::ballRadius, WHITE);
        DrawRectangle(Config::paddleLeftPosX, Config::paddlePosY, Config::paddleWidth, Config::paddleHeight, WHITE);
        DrawRectangle(Config::paddleRightPosX, Config::paddlePosY, Config::paddleWidth, Config::paddleHeight, WHITE);

        EndDrawing();
    }

    CloseWindow();
}