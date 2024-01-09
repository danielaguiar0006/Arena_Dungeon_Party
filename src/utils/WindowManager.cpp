#include "WindowManager.h"
#include <iostream>

// TODO: currently the code is under the bad assumption that the window size is always 16:9

void WindowManager::Update(Camera2D &camera)
{
    if (IsKeyPressed(KEY_F11))
    {
        if (FULLSCREEN)
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
        CAMERA_ZOOM_FACTOR = float(currentResolution.width) / 1280.0f; // 1280x720 is 1.0f camera zoom
    else
        CAMERA_ZOOM_FACTOR = 1.0f;

    if (camera.zoom != CAMERA_ZOOM_FACTOR)
    {
        camera.zoom = CAMERA_ZOOM_FACTOR;
    }

    if (GetScreenWidth() != currentResolution.width || GetScreenHeight() != currentResolution.height)
    {
        SetWindowSize(currentResolution.width, currentResolution.height);
    }
}

void WindowManager::ChangeWindowSize(WindowResolution resolution)
{
    if (FULLSCREEN == true)
    {
        FULLSCREEN = false;
        ToggleBorderlessWindowed();
    }
    currentResolution = resolution;
    SetWindowSize(currentResolution.width, currentResolution.height);
}

void WindowManager::Fullscreen() // Note: Borderless
{
    if (FULLSCREEN == true)
    {
        return;
    }

    FULLSCREEN = true;
    currentResolution.width = GetMonitorWidth(GetCurrentMonitor());
    currentResolution.height = GetMonitorHeight(GetCurrentMonitor());
    SetWindowSize(currentResolution.width, currentResolution.height);

    ToggleBorderlessWindowed();
}

void WindowManager::Unfullscreen()
{
    if (FULLSCREEN == false)
    {
        return;
    }

    FULLSCREEN = false;
    SetWindowSize(currentResolution.width, currentResolution.height);

    ToggleBorderlessWindowed();
}

void WindowManager::CycleResolution()
{
    // Find the current resolution in the resolutions16x9 vector
    auto it = std::find(resolutions16x9.begin(), resolutions16x9.end(), currentResolution);

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
    auto it = std::find(resolutions16x9.begin(), resolutions16x9.end(), currentResolution);

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