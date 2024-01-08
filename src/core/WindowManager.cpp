#include "WindowManager.h"
#include <iostream>

// TODO: currently the code is under the bad assumption that the window size is always 16:9

WindowManager::WindowManager()
{
    /*     InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "raylib [core] example - basic window");
        SetTargetFPS(60); */
    /*     windowWidth = WINDOW_WIDTH;
        windowHeight = WINDOW_HEIGHT; */
}

void WindowManager::Update(Camera2D &camera)
{
    if (RELATIVE_CAMERA_ZOOM == true)
        CAMERA_ZOOM_FACTOR = float(WINDOW_WIDTH) / 1280.0f; // 1280x720 is 1.0f camera zoom
    else
        CAMERA_ZOOM_FACTOR = 1.0f;

    if (camera.zoom != CAMERA_ZOOM_FACTOR)
    {
        camera.zoom = CAMERA_ZOOM_FACTOR;
    }

    if (GetScreenHeight() != WINDOW_HEIGHT || GetScreenWidth() != WINDOW_WIDTH)
    {
        std::cout << "Window size changed" << std::endl;
        SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    }

    if (IsKeyPressed(KEY_UP))
    {
        ChangeWindowSize(640, 360);
    }
}

void WindowManager::ChangeWindowSize(int width, int height)
{
    FULLSCREEN = false;
    WINDOW_WIDTH = width;
    WINDOW_HEIGHT = height;
}

void WindowManager::Fullscreen(Camera2D &camera) // Note: Borderless
{
    if (FULLSCREEN == true)
    {
        return;
    }

    FULLSCREEN = true;
    CAMERA_ZOOM_FACTOR = 1.5f;
    WINDOW_HEIGHT = GetMonitorHeight(GetCurrentMonitor());
    WINDOW_WIDTH = GetMonitorWidth(GetCurrentMonitor());
    SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    ToggleBorderlessWindowed();
}

void WindowManager::Unfullscreen(Camera2D &camera)
{
    if (FULLSCREEN == false)
    {
        return;
    }

    FULLSCREEN = false;
    WINDOW_WIDTH = 1280;
    WINDOW_HEIGHT = 720;
    SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    ToggleBorderlessWindowed();
}