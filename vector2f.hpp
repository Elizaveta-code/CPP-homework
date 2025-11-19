#pragma once
#include <iostream>
#include <cmath>

struct Vector2f {
    float x;
    float y;
};

Vector2f operator+(const Vector2f& a, const Vector2f& b) {
    return {a.x + b.x, a.y + b.y};
}

Vector2f operator-(const Vector2f& a, const Vector2f& b) {
    return {a.x - b.x, a.y - b.y};
}

Vector2f operator*(const Vector2f& a, float b) {
    return {a.x * b, a.y * b};
}

Vector2f operator*(float b, const Vector2f& a) {
    return a * b;
}

float operator*(const Vector2f& a, const Vector2f& b) {
    return a.x * b.x + a.y * b.y;
}

Vector2f operator+(const Vector2f& a) {
    return a;
}

Vector2f operator-(const Vector2f& a) {
    return {-a.x, -a.y};
}

bool operator==(const Vector2f& a, const Vector2f& b) {
    return a.x == b.x && a.y == b.y;
}

bool operator!=(const Vector2f& a, const Vector2f& b) {
    return !(a == b);
}

Vector2f& operator+=(Vector2f& a, const Vector2f& b) {
    a.x += b.x;
    a.y += b.y;
    return a;
}

Vector2f& operator-=(Vector2f& a, const Vector2f& b) {
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

Vector2f& operator*=(Vector2f& a, float b) {
    a.x *= b;
    a.y *= b;
    return a;
}

Vector2f& operator/=(Vector2f& a, float b) {
    a.x /= b;
    a.y /= b;
    return a;
}

std::istream& operator>>(std::istream& in, Vector2f& a) {
    in >> a.x >> a.y;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Vector2f& a) {
    out << '(' << a.x << ", " << a.y << ')';
    return out;
}