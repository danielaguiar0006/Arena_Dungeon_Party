#pragma once

#include "Globals.h"

class Grid
{
public:
    Grid();
    void Draw();
    Vector2 GetGridCount();

private:
    Texture2D gridTexture;
    int gridWidth = SCREEN_WIDTH / TILE_WIDTH;
    int gridHeight = SCREEN_HEIGHT / TILE_WIDTH;
    /*     int grid[GRID_WIDTH][GRID_HEIGHT]; */
};