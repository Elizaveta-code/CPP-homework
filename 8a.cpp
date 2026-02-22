#include "raylib.h"
#include <math.h>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    
    InitWindow(screenWidth, screenHeight, "Притяжение к мыши (постоянная скорость)");

    Vector2 circlePos = {screenWidth/2, screenHeight/2};
    const float radius = 30.0f;
    const float speed = 3.0f;
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            Vector2 mousePos = GetMousePosition();
            Vector2 direction = { 
                mousePos.x - circlePos.x,
                mousePos.y - circlePos.y
            };
            float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
            if (distance > 0)
            {
                direction.x /= distance;
                direction.y /= distance;
                
                circlePos.x += direction.x * speed;
                circlePos.y += direction.y * speed;
            }
        }
        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircleV(circlePos, radius, WHITE);
        Vector2 mousePos = GetMousePosition();
        EndDrawing();
    }
    CloseWindow();
}