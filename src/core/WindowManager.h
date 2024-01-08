#pragma once

#include "raylib.h"
#include "../utils/Globals.h"

class WindowManager
{
public:
    WindowManager();
    void ChangeWindowSize(int width, int height);
    void ChangeWindowScale(int scale);
    void Fullscreen(Camera2D &camera);

private:
    /* WindowManager::WindowManager(
    {
    }

    WindowManager::~WindowManager()
    {
    } */
};