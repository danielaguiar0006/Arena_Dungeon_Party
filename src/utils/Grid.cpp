#include "Grid.h"

// TODO: fix grid not being drawn correctly on higher window resolutions

Grid::Grid()
{
    gridTexture = LoadTexture("assets/textures/grid.png");

    // Perform multiplication first and division last to avoid precision loss
    gridWidth = static_cast<int>((GetScreenWidth() / CAMERA_ZOOM_FACTOR) / (TILE_WIDTH * TILE_SCALE_FACTOR));
    gridHeight = static_cast<int>((GetScreenHeight() / CAMERA_ZOOM_FACTOR) / (TILE_WIDTH * TILE_SCALE_FACTOR));
}

Grid::~Grid()
{
    UnloadTexture(gridTexture);
}

void Grid::Draw()
{
    UpdateGridCount(); // TODO: put it update loop instead of draw loop
    for (int x = 0; x < gridWidth; x++)
    {
        for (int y = 0; y < gridHeight; y++)
        {
            // DrawTexture(gridTexture, x * TILE_WIDTH * TILE_SCALE_FACTOR, y * TILE_WIDTH * TILE_SCALE_FACTOR, WHITE);  // Wrong but interesting effect
            Vector2 gridPosition = Vector2{static_cast<float>(x * TILE_WIDTH * TILE_SCALE_FACTOR), static_cast<float>(y * TILE_WIDTH * TILE_SCALE_FACTOR)};
            DrawTextureEx(gridTexture, gridPosition, 0.0f, static_cast<float>(TILE_SCALE_FACTOR), WHITE);
        }
    }
}

Vector2 Grid::GetGridCount()
{
    return Vector2{static_cast<float>(gridWidth), static_cast<float>(gridHeight)};
}

void Grid::UpdateGridCount()
{
    // Perform multiplication first and division last to avoid precision loss
    gridWidth = static_cast<int>((GetScreenWidth() / CAMERA_ZOOM_FACTOR) / (TILE_WIDTH * TILE_SCALE_FACTOR));
    gridHeight = static_cast<int>((GetScreenHeight() / CAMERA_ZOOM_FACTOR) / (TILE_WIDTH * TILE_SCALE_FACTOR));
}