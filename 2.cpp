#include "raylib.h"
int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Цикл");
    Vector2 coordinate = {0, (float)screenHeight/2.0f};
    const float speed = 300.0f;
    const float radius = 32.0f;
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        coordinate.x += GetFrameTime()*speed;
        if (coordinate.x > screenWidth) coordinate.x = 0;
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawCircleV(coordinate, radius, RED);
        EndDrawing();
    }
    CloseWindow();
}