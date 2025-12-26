#include <raylib.h>

int main()
{
    const Color darkBlue = {0, 0, 20, 255};

    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Pong Game");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkBlue);
        EndDrawing();
    }

    CloseWindow();
}