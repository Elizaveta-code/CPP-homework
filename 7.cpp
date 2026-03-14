#include "raylib.h"
#include <vector>

class DropList
{
private:
    Rectangle mainRect;
    std::vector<Rectangle> itemRects;
    std::vector<const char*> items;
    bool isOpen;
    int selected;
    
public:
    DropList(float x, float y, float w, std::vector<const char*> list)
        : items(list), isOpen(false), selected(-1)
    {
        mainRect = {x - w/2, y - 15, w, 30};
        
        for (int i = 0; i < (int)list.size(); i++)
        {
            itemRects.push_back({x - w/2, y - 15 + 30 + i*30, w, 30});
        }
    }
    
    void update()
    {
        Vector2 mouse = GetMousePosition();
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (CheckCollisionPointRec(mouse, mainRect))
            {
                isOpen = !isOpen;
            }
            else if (isOpen)
            {
                for (int i = 0; i < (int)itemRects.size(); i++)
                {
                    if (CheckCollisionPointRec(mouse, itemRects[i]))
                    {
                        selected = i;
                        isOpen = false;
                        break;
                    }
                }
                if (!CheckCollisionPointRec(mouse, mainRect)) isOpen = false;
            }
        }
    }
    
    void draw()
    {
        DrawRectangleRec(mainRect, isOpen ? LIGHTGRAY : GRAY);
        DrawRectangleLinesEx(mainRect, 2, BLACK);
        
        const char* text = (selected >= 0) ? items[selected] : "Square";
        DrawText(text, mainRect.x + 5, mainRect.y + 5, 20, BLACK);
        
        DrawText(isOpen ? "^" : "v", mainRect.x + mainRect.width - 20, mainRect.y + 5, 20, BLACK);
        
        if (isOpen)
        {
            for (int i = 0; i < (int)itemRects.size(); i++)
            {
                Vector2 mouse = GetMousePosition();
                Color col = CheckCollisionPointRec(mouse, itemRects[i]) ? LIGHTGRAY : WHITE;
                
                DrawRectangleRec(itemRects[i], col);
                DrawRectangleLinesEx(itemRects[i], 1, BLACK);
                DrawText(items[i], itemRects[i].x + 5, itemRects[i].y + 5, 20, BLACK);
            }
        }
    }
    
    int getSelected() { return selected; }
    const char* getSelectedText() { return (selected >= 0) ? items[selected] : ""; }
};

int main()
{
    InitWindow(800, 600, "Dropdown");
    SetTargetFPS(60);
    
    std::vector<const char*> items = {"Circle", "Square", "Triangle"};
    DropList list(400, 100, 200, items);
    
    while (!WindowShouldClose())
    {
        list.update();
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        list.draw();
        
        const char* sel = list.getSelectedText();
        
        if (sel == items[0])
        {
            DrawCircleV({400, 300}, 40, BLUE);
        }
        else if (sel == items[1])
        {
            DrawRectangle(360, 260, 80, 80, GREEN);
        }
        else if (sel == items[2])
        {
            Vector2 v1 = {400, 260};
            Vector2 v2 = {360, 340};
            Vector2 v3 = {440, 340};
            DrawTriangle(v1, v2, v3, RED);
        }
        EndDrawing();
    }
    CloseWindow();
}