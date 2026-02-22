#include "raylib.h"
int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Вращающийся квадрат");   
    SetTargetFPS(60);
    
    float rotation = 0.0f;
    float size = 200.0f;
    
    while (!WindowShouldClose())
    {
        rotation += 50.0f * GetFrameTime();
        BeginDrawing();
            ClearBackground(RAYWHITE);
            Rectangle rect = Rectangle{screenWidth/2, screenHeight/2, size, size};
            Vector2 origin = {0, 0};
            DrawRectanglePro(rect, origin, rotation, RED);
        EndDrawing();
    }
    CloseWindow();
}