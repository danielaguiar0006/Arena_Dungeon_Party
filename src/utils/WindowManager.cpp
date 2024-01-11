#include "WindowManager.h"

// TODO: currently the code is under the bad assumption that the window size is always 16:9

void WindowManager::Update(Camera2D &camera)
{
    if (IsKeyPressed(KEY_F11))
    {
        if (IS_FULLSCREEN)
        {
            Unfullscreen();
        }
        else
        {
            Fullscreen();
        }
    }
    if (IsKeyPressed(KEY_UP))
    {
        CycleResolution();
    }
    if (IsKeyPressed(KEY_DOWN))
    {
        CycleResolutionBackwards();
    }

    if (RELATIVE_CAMERA_ZOOM == true)
        CAMERA_ZOOM_FACTOR = float(WINDOW_WIDTH) / 1280.0f; // 1280x720 is 1.0f camera zoom
    else
        CAMERA_ZOOM_FACTOR = 1.0f;

    if (camera.zoom != CAMERA_ZOOM_FACTOR)
    {
        camera.zoom = CAMERA_ZOOM_FACTOR;
    }

    /*     if (GetScreenWidth() != WINDOW_WIDTH || GetScreenHeight() != WINDOW_HEIGHT) // ! GetScreenWidth() and GetScreenHeight() max out at screen/s physical resoultion not game/viewport size
        {
            ChangeWindowSize(WindowResolution(WINDOW_WIDTH, WINDOW_HEIGHT));
        } */
}

void WindowManager::ChangeWindowSize(WindowResolution resolution)
{
    if (resolution.width == WINDOW_WIDTH && resolution.height == WINDOW_HEIGHT)
    {
        return;
    }

    WINDOW_WIDTH = resolution.width;
    WINDOW_HEIGHT = resolution.height;
    SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
}

void WindowManager::Fullscreen() // Note: Borderless
{
    if (IS_FULLSCREEN == true)
    {
        return;
    }

    IS_FULLSCREEN = true;
    int monitorWidth = GetMonitorWidth(GetCurrentMonitor());
    int monitorHeight = GetMonitorHeight(GetCurrentMonitor());

    ToggleBorderlessWindowed();
    ChangeWindowSize(WindowResolution(monitorWidth, monitorHeight));
}

void WindowManager::Unfullscreen()
{
    if (IS_FULLSCREEN == false)
    {
        return;
    }

    IS_FULLSCREEN = false;

    ToggleBorderlessWindowed();
    ChangeWindowSize(WindowResolution(1280, 720));
}

void WindowManager::CycleResolution()
{
    // Find the current resolution in the resolutions16x9 vector
    auto it = std::find(resolutions16x9.begin(), resolutions16x9.end(), WindowResolution(WINDOW_WIDTH, WINDOW_HEIGHT));

    // If the current resolution is found and it's not the last resolution in the vector, move to the next resolution
    if (it != resolutions16x9.end() && it + 1 != resolutions16x9.end())
    {
        ChangeWindowSize(*(it + 1));
    }
    // If the current resolution is the last resolution in the vector, move to the first resolution
    else
    {
        ChangeWindowSize(resolutions16x9[0]);
    }
}

void WindowManager::CycleResolutionBackwards()
{
    // Find the current resolution in the resolutions16x9 vector
    auto it = std::find(resolutions16x9.begin(), resolutions16x9.end(), WindowResolution(WINDOW_WIDTH, WINDOW_HEIGHT));

    // If the current resolution is found and it's not the first resolution in the vector, move to the previous resolution
    if (it != resolutions16x9.end() && it != resolutions16x9.begin())
    {
        ChangeWindowSize(*(it - 1));
    }
    // If the current resolution is the first resolution in the vector, move to the last resolution
    else
    {
        ChangeWindowSize(resolutions16x9.back());
    }
}