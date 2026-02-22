#include "raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Столкновение с прямоугольником");
    SetTargetFPS(60);
    
    Rectangle rect = {screenWidth/2.0f - 100, screenHeight/2.0f - 50, 200, 100};
    
    Color color;
    while (!WindowShouldClose()) {
        Vector2 mousePos = GetMousePosition();

        if (CheckCollisionPointRec(mousePos, rect)) {
            color = RED;
        } else {
            color = GREEN;
        }
        
        BeginDrawing();
            ClearBackground(WHITE);
            DrawRectangleRec(rect, color);
        EndDrawing();
    }
    CloseWindow();
}