#include "Grid.h"

Grid::Grid()
{
    gridTexture = LoadTexture("assets/textures/grid.png");
}

void Grid::Draw()
{
    for (int x = 0; x < gridWidth; x++)
    {
        for (int y = 0; y < gridHeight; y++)
        {
            // DrawTexture(gridTexture, x * TILE_WIDTH * SCALE_FACTOR, y * TILE_WIDTH * SCALE_FACTOR, WHITE);  // Wrong but interesting effect
            Vector2 gridPosition = Vector2{static_cast<float>(x * TILE_WIDTH * SCALE_FACTOR), static_cast<float>(y * TILE_WIDTH * SCALE_FACTOR)};
            DrawTextureEx(gridTexture, gridPosition, 0.0f, SCALE_FACTOR, WHITE);
        }
    }
}

Vector2 Grid::GetGridCount()
{
    return Vector2{static_cast<float>(gridWidth), static_cast<float>(gridHeight)};
}