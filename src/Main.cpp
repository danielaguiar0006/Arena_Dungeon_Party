/*******************************************************************************************
 *
 *
 *
 ********************************************************************************************/

#include "raylib.h"
#include "entities/dynamic/Player.h"
#include "utils/TextureManager.h"
#include "utils/WindowManager.h"
#include "utils/Globals.h"
#include "utils/Grid.h"
#include "utils/Logger.h"

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
void Update(Camera2D &camera, Player &player1, Grid &grid);
void DrawFrame(Camera2D &camera, Player &player1, Grid &grid);

//----------------------------------------------------------------------------------
// Main Entry Point
//----------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    //-- Load Level / commons --
    // * Cannot be done because GetTexture() return a shared ptr Texture2D
    // TextureManager::GetInstance().GetTexture("assets/textures/player.png");
    // TextureManager::GetInstance().GetTexture("assets/textures/wall.png");

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "raylib [core] example - basic window");
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    // SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE); //! Doesn't seem to work

    Camera2D camera = {0};
    camera.target = {0.0f, 0.0f};
    camera.offset = {0.0f, 0.0f};
    camera.rotation = 0.0f;
    camera.zoom = CAMERA_ZOOM_FACTOR;

    Player player1("assets/textures/player.png");
    Player player2("assets/textures/playet.png");
    Grid grid;
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        Update(camera, player1, grid);
        DrawFrame(camera, player1, grid);
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    TextureManager::GetInstance().UnloadAllTextures();
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
void Update(Camera2D &camera, Player &player1, Grid &grid) // TODO UPDATE TO TAKE ENTITY LIST AS PARAMETER
{
    WindowManager::GetInstance().Update(camera);
    grid.Update();
    float deltaTime = GetFrameTime() * TIMESCALE;

    player1.Update(deltaTime);
}

void DrawFrame(Camera2D &camera, Player &player1, Grid &grid)
{
    BeginDrawing();
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