#include "raylib.h"
#include <string>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    
    InitWindow(screenWidth, screenHeight, "Координаты мыши");
    SetTargetFPS(60);
    std::string text;
    
    while (!WindowShouldClose()) {
        Vector2 mousePos = GetMousePosition();
        text = "Mouse Position: X = " + std::to_string((int)mousePos.x) + ", Y = " + std::to_string((int)mousePos.y);
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText(text.c_str(), 0, 0, 30, BLACK);
        EndDrawing();
    }
    CloseWindow();
}