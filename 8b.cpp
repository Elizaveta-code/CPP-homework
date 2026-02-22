#include "raylib.h"
#include <math.h>

int main()
{
    const int screenWidth = 1800;
    const int screenHeight = 900;
    
    InitWindow(screenWidth, screenHeight, "Притяжение к мыши (постоянное ускорение)");
    Vector2 circlePos = {screenWidth/2, screenHeight/2};
    Vector2 speed = {0, 0};
    const float radius = 30.0f;
    const float a = 0.1f;
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
                
                speed.x += direction.x * a;
                speed.y += direction.y * a;
            }
        }
        circlePos.x += speed.x;
        circlePos.y += speed.y;
        
        if (circlePos.x <= radius) {
            circlePos.x = radius;
            speed.x = -speed.x;
        }
        if (circlePos.x >= screenWidth - radius) {
            circlePos.x = screenWidth - radius;
            speed.x = -speed.x;
        }
        if (circlePos.y <= radius) {
            circlePos.y = radius;
            speed.y = -speed.y;
        }
        if (circlePos.y >= screenHeight - radius) {
            circlePos.y = screenHeight - radius;
            speed.y = -speed.y;
        }
        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircleV(circlePos, radius, WHITE);
        Vector2 mousePos = GetMousePosition();
        EndDrawing();
    }
    CloseWindow();
}