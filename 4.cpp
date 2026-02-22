#include "raylib.h"

int main()
{
    const int screenWidth = 1200;
    const int screenHeight = 900;
    InitWindow(screenWidth, screenHeight, "Движение по кругу");

    int textureWidth = 300;
    int textureHeight = 300;
    RenderTexture2D rect = LoadRenderTexture(textureWidth, textureHeight);
    Vector2 circlePos = {280.0f, 280.0f};
    int radius = 10;
    float rotation = 0.0f;
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        rotation += 50 * GetFrameTime();
        BeginTextureMode(rect);
            ClearBackground(RAYWHITE);
            DrawCircleV(circlePos, radius, RED);
        EndTextureMode();

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexturePro(rect.texture,
                (Rectangle){0, 0, (float)rect.texture.width, (float)-rect.texture.height},
                (Rectangle){screenWidth/2.0f, screenHeight/2.0f, (float)rect.texture.width, (float)rect.texture.height},
                (Vector2){0, 0}, 
                rotation, WHITE);
                //DrawCircleLines(screenWidth/2.0f, screenHeight/2.0f, 280*1.42, GRAY);
        EndDrawing();
    }
    CloseWindow();
}