#include "raylib.h"
#include <vector>

class Toggle
{
private:
    Rectangle mRect{};
    bool mState{false};
    float mKnobPosition{0.0f};
    
public:
    Toggle(Vector2 position, float width, float height)
    {
        mRect.x = position.x - width/2;
        mRect.y = position.y - height/2;
        mRect.width = width;
        mRect.height = height;
    }
    
    void handleEvent()
    {
        Vector2 mouse = GetMousePosition();
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && 
            CheckCollisionPointRec(mouse, mRect))
        {
            mState = !mState;
        }        
        float target;
        if (mState == true){
            target = 1.0f;
        }
        else{
            target = 0.0f;
        }
        mKnobPosition += (target - mKnobPosition) * 0.3f;
    }
    void draw()
    {
        Color trackColor;
        if (mState == true){
            trackColor = GREEN;
        }
        else{
            trackColor = GRAY;
        }
        DrawRectangleRounded(mRect, 1.0f, 100, trackColor);
        float r = mRect.height * 0.9f / 2;
        float x = mRect.x + r + 4 + (mRect.width - 2*r - 8) * mKnobPosition;
        float y = mRect.y + mRect.height/2;
        DrawCircleV({x, y}, r, WHITE);
    }
    bool getState() const {return mState;}
};

int main()
{
    InitWindow(800, 800, "Toggles");
    SetTargetFPS(60);
    
    std::vector<Toggle> toggles;
    
    for (int i = 0; i < 10; i++)
    {
        toggles.emplace_back(
            Vector2{400.0f, 100.0f + static_cast<float>(i) * 65.0f}, 
            90.0f, 
            50.0f
        );
    }    
    while (!WindowShouldClose())
    {
        for (auto& t : toggles) t.handleEvent();
        
        BeginDrawing();
        ClearBackground(BLACK);
        for (auto& t : toggles) t.draw();
        EndDrawing();
    }
    CloseWindow();
}