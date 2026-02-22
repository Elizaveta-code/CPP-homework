#include "raylib.h"
#include <stdlib.h>

struct Circle {
    Vector2 position;
    Color color;
};

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Создание кругов");
    
    Circle* circles = NULL;
    int circleCount = 0;
    const float radius = 20.0f;
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            circleCount++;
            circles = (Circle*)realloc(circles, circleCount * sizeof(Circle));
            Vector2 mousePos = GetMousePosition();
            circles[circleCount - 1].position = mousePos;
            circles[circleCount - 1].color = WHITE;
        }
        if (IsKeyPressed(KEY_SPACE))
        {
            for (int i = 0; i < circleCount; i++)
            {
                circles[i].color = (Color){(unsigned char)(GetRandomValue(0, 255)), (unsigned char)(GetRandomValue(0, 255)), (unsigned char)(GetRandomValue(0, 255)), 255};
            }
        }
        BeginDrawing();
        ClearBackground(BLACK);
        for (int i = 0; i < circleCount; i++)
        {
            DrawCircleV(circles[i].position, radius, circles[i].color);
        }
        EndDrawing();
    }
    free(circles);
    CloseWindow();
}