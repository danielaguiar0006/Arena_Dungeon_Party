#include "Grid.h"

Grid::Grid()
{
    gridTexture = LoadTexture("assets/textures/grid.png");

    // Probable jank with int and float conversions
    gridWidth = (WINDOW_WIDTH / (TILE_WIDTH * TILE_SCALE_FACTOR)) / CAMERA_ZOOM_FACTOR;
    gridHeight = (WINDOW_HEIGHT / (TILE_WIDTH * TILE_SCALE_FACTOR)) / CAMERA_ZOOM_FACTOR;
}

Grid::~Grid()
{
    UnloadTexture(gridTexture);
}

void Grid::Draw()
{
    UpdateGridCount();
    for (int x = 0; x < gridWidth; x++)
    {
        for (int y = 0; y < gridHeight; y++)
        {
            // DrawTexture(gridTexture, x * TILE_WIDTH * TILE_SCALE_FACTOR, y * TILE_WIDTH * TILE_SCALE_FACTOR, WHITE);  // Wrong but interesting effect
            Vector2 gridPosition = Vector2{static_cast<float>(x * TILE_WIDTH * TILE_SCALE_FACTOR), static_cast<float>(y * TILE_WIDTH * TILE_SCALE_FACTOR)};
            DrawTextureEx(gridTexture, gridPosition, 0.0f, TILE_SCALE_FACTOR, WHITE);
        }
    }
}

Vector2 Grid::GetGridCount()
{
    return Vector2{static_cast<float>(gridWidth), static_cast<float>(gridHeight)};
}

void Grid::UpdateGridCount()
{
    // Probable jank with int and float conversions
    gridWidth = (WINDOW_WIDTH / (TILE_WIDTH * TILE_SCALE_FACTOR)) / CAMERA_ZOOM_FACTOR;
    gridHeight = (WINDOW_HEIGHT / (TILE_WIDTH * TILE_SCALE_FACTOR)) / CAMERA_ZOOM_FACTOR;
}