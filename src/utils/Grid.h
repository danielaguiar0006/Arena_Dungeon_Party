#pragma once

#include "Globals.h"
#include "TextureManager.h"

class Grid
{
public:
    Grid();
    ~Grid();
    void Draw();
    Vector2 GetGridCount();

private:
    Texture2D gridTexture;
    int gridWidth;
    int gridHeight;

    void UpdateGridCount();
    /*     int grid[GRID_WIDTH][GRID_HEIGHT]; */
};