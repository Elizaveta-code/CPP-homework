#include "raylib.h"
#include <vector>
#include <cmath>

const int WIDTH = 1200;
const int HEIGHT = 900;
const float DT = 0.5f;
const float MIN_DISTANCE = 20.0f;

const float MIN_MASS = 0.5f;
const float MAX_MASS = 5.0f;
const float MIN_CHARGE = -5.0f;
const float MAX_CHARGE = 5.0f;

struct Ball {
    Vector2 position;
    Vector2 speed;
    float mass;
    float charge;
    float radius;
    Color color;
    
    Ball(float x, float y, float m, float q) {
        position = {x, y};
        speed = {0, 0};
        mass = m;
        charge = q;
        radius = 5.0f + m * 2.0f;

        if (charge > 0) {
            color = RED;
        } else {
            color = BLUE;
        }
    }
};

std::vector<Ball> balls;

void createRandomBall() {
    float x = (float)GetRandomValue(50, WIDTH - 50);
    float y = (float)GetRandomValue(50, HEIGHT - 50);
    float mass = MIN_MASS + (float)GetRandomValue(0, 100) / 100.0f * (MAX_MASS - MIN_MASS);
    float charge = MIN_CHARGE + (float)GetRandomValue(0, 100) / 100.0f * (MAX_CHARGE - MIN_CHARGE);
    balls.emplace_back(x, y, mass, charge);
}

void createBallAtMouse(int button) {
    Vector2 mousePos = GetMousePosition();
    float mass, charge;    
    if (button == MOUSE_BUTTON_LEFT) {
        mass = 0.5f;
        charge = -3.0f;
    } else if (button == MOUSE_BUTTON_RIGHT) {
        mass = 8.0f;
        charge = 3.0f;
    } else {
        return;
    }
    balls.emplace_back(mousePos.x, mousePos.y, mass, charge);
}

Vector2 calcForce(const Ball& b1, const Ball& b2) {
    Vector2 force = {0, 0};
    Vector2 delta = {
        b2.position.x - b1.position.x,
        b2.position.y - b1.position.y
    };
    float distance = sqrt(delta.x * delta.x + delta.y * delta.y);
    if (distance < MIN_DISTANCE) {
        return force;
    }
    float forceA = (b1.charge * b2.charge) / distance;
    Vector2 direction = {
        delta.x / distance,
        delta.y / distance
    };
    force.x = forceA * direction.x;
    force.y = forceA * direction.y;
    return force;
}

void update() {
    if (balls.empty()) return;
    std::vector<Vector2> a(balls.size(), {0, 0});    
    for (size_t i = 0; i < balls.size(); i++) {
        for (size_t j = i + 1; j < balls.size(); j++) {
            Vector2 force = calcForce(balls[i], balls[j]);
            a[i].x += force.x / balls[i].mass;
            a[i].y += force.y / balls[i].mass;
            
            a[j].x -= force.x / balls[j].mass;
            a[j].y -= force.y / balls[j].mass;
        }
    }
    for (size_t i = 0; i < balls.size(); i++) {
        balls[i].speed.x += a[i].x * DT;
        balls[i].speed.y += a[i].y * DT;
        
        balls[i].position.x += balls[i].speed.x * DT;
        balls[i].position.y += balls[i].speed.y * DT;

        float radius = balls[i].radius;
        if (balls[i].position.x < radius) {
            balls[i].position.x = radius;
            balls[i].speed.x *= -1;
        }
        if (balls[i].position.x > WIDTH - radius) {
            balls[i].position.x = WIDTH - radius;
            balls[i].speed.x *= -1;
        }
        if (balls[i].position.y < radius) {
            balls[i].position.y = radius;
            balls[i].speed.y *= -1;
        }
        if (balls[i].position.y > HEIGHT - radius) {
            balls[i].position.y = HEIGHT - radius;
            balls[i].speed.y *= -1;
        }
    }
}

void draw() {
    BeginDrawing();
    ClearBackground(BLACK);
    DrawRectangleLines(0, 0, WIDTH, HEIGHT, WHITE);    
    for (const auto& ball : balls) {
        DrawCircleV(ball.position, ball.radius, ball.color);
    }
    EndDrawing();
}

int main() {
    InitWindow(WIDTH, HEIGHT, "Задача n тел");
    SetTargetFPS(60);
    
    int n = 5;
    for (int i = 0; i < n; i++) {
        createRandomBall();
    }    
    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            createBallAtMouse(MOUSE_BUTTON_LEFT);
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            createBallAtMouse(MOUSE_BUTTON_RIGHT);
        }
        update();
        draw();
    }
    CloseWindow();
}