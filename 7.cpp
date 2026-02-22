#include "raylib.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Двигающийся кружок");
    Vector2 pos = {screenWidth/2, screenHeight/2};
    const float radius = 30.0f;
    const float speed = 5.0f;
    Color color = WHITE;
    bool spacePressed = false;
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_RIGHT)) pos.x += speed;
        if (IsKeyDown(KEY_LEFT)) pos.x -= speed;
        if (IsKeyDown(KEY_DOWN)) pos.y += speed;
        if (IsKeyDown(KEY_UP)) pos.y -= speed;        
        if (IsKeyPressed(KEY_SPACE)) {color = (Color){(unsigned char)(GetRandomValue(0, 255)), (unsigned char)(GetRandomValue(0, 255)), (unsigned char)(GetRandomValue(0, 255)), 255};}

        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircleV(pos, radius, color);
        EndDrawing();
    }
    CloseWindow();
}