#pragma once

#include "Globals.h"
#include "TextureManager.h"

class Grid
{
public:
    Grid();
    ~Grid();
    void Draw();
    void Update();
    Vector2 GetGridCount(); // ? Should this be a Vector2

private:
    Texture2D gridTexture;
    int gridWidth;
    int gridHeight;
};