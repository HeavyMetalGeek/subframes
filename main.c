#include <raylib.h>
#include <raymath.h>

#include "nob.h"

static const Color BACKGROUND_COLOR = {18, 18, 18, 255};
static const int WIN_W = 640;
static const int WIN_H = 480;
static const float TAU = 2.0f * PI;

int main() {
    InitWindow(WIN_W, WIN_H, "Subframes");
    // SetTargetFPS(30);
    float radius = 40.0f;

    Camera2D camera = {
        .zoom = 1,
        .offset = {WIN_W / 2.0f, WIN_H / 2.0f},
    };

    Vector2 position = {0.0f, 0.0f};
    Color ring_color = {255.0f, 255.0f, 0.0f, 255.0f};
    float w = WIN_W;
    float h = WIN_H;
    float dt = 0.0f;
    float time = 0.0f;
    float theta = 0.0f;
    Vector2 unit_position = {0.0f, 0.0f};

    while (!WindowShouldClose()) {
        w = GetScreenWidth();
        h = GetScreenHeight();
        camera.offset.x = w / 2.0f;
        camera.offset.y = h / 2.0f;
        dt = GetFrameTime();
        time = GetTime();

        theta = 0.75f * PI * sin(2.0f * time);
        unit_position.x = sin(theta);
        unit_position.y = cos(theta);
        position = Vector2Scale(unit_position, -200.0f);
        ring_color.r = Remap(unit_position.y, -0.71f, 1.0f, 255.0f, 0.0f);
        ring_color.g = Remap(unit_position.y, -0.71f, 1.0f, 0.0f, 255.0f);

        BeginDrawing();
        BeginMode2D(camera);
        {
            DrawRing(
                position,
                radius * 0.80f,
                radius,
                0.0f,
                360.0f,
                255,
                ring_color);
            ClearBackground(BACKGROUND_COLOR);
        }
        EndMode2D();
        EndDrawing();
    }
    return 0;
}
