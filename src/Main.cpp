/*******************************************************************************************
 *
 *
 *
 ********************************************************************************************/

#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "utils/Globals.h"
#include "entities/Player.h"
#include "utils/Grid.h"
#include "utils/WindowManager.h" // ? should maybe be in utils/ instead ?

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
void Update(WindowManager &windowManager, Camera2D &camera, Player &player1);
void DrawFrame(Camera2D &camera, Player &player1, Grid &grid);

//----------------------------------------------------------------------------------
// Main Entry Point
//----------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(INIT_WINDOW_WIDTH, INIT_WINDOW_HEIGHT, "raylib [core] example - basic window");
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    // SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE); // Doesn't seem to work

    Camera2D camera = {0};
    camera.target = {0.0f, 0.0f};
    camera.offset = {0.0f, 0.0f};
    camera.rotation = 0.0f;
    camera.zoom = CAMERA_ZOOM_FACTOR;

    WindowManager windowManager;
    Player player1;
    Grid grid;
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        Update(windowManager, camera, player1);
        DrawFrame(camera, player1, grid);
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
void Update(WindowManager &windowManager, Camera2D &camera, Player &player1)
{
    windowManager.Update(camera);
    // camera.zoom = CAMERA_ZOOM_FACTOR;
    float deltaTime = GetFrameTime() * TIMESCALE;

    player1.Update(deltaTime);
}

void DrawFrame(Camera2D &camera, Player &player1, Grid &grid)
{
    BeginDrawing();
    /*     ClearBackground(RAYWHITE); */
    ClearBackground(BACKGROUND_COLOR);

    BeginMode2D(camera);
    camera.target = player1.GetPixelPosition();
    camera.offset = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    grid.Draw();
    player1.Draw();
    EndMode2D();

    /*     DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY); */

    EndDrawing();
}