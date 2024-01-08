/*******************************************************************************************
 *
 *
 *
 ********************************************************************************************/

#include "raylib.h"
#include "raymath.h"
#include "utils/Globals.h"
#include "entities/Player.h"
#include "utils/Grid.h"
// #include "core/Entity.h"

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
int screenWidth = SCREEN_WIDTH;
int screenHeight = SCREEN_HEIGHT;

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
void Update(Player &player1);
void DrawFrame(Camera2D camera, Player &player1, Grid &grid);

//----------------------------------------------------------------------------------
// Main Entry Point
//----------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    Camera2D camera = {0};
    camera.target = {0.0f, 0.0f};
    camera.offset = {0.0f, 0.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    Player player1;
    Grid grid;
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        Update(player1);
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
void Update(Player &player1)
{
    float deltaTime = GetFrameTime() * TIMESCALE;
    player1.Update(deltaTime);
}

void DrawFrame(Camera2D camera, Player &player1, Grid &grid)
{
    BeginDrawing();
    /*     ClearBackground(RAYWHITE); */
    ClearBackground(BACKGROUND_COLOR);

    BeginMode2D(camera);
    grid.Draw();
    player1.Draw();
    EndMode2D();

    /*     DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY); */

    EndDrawing();
}