#pragma once

#include "raylib.h"
#include "../utils/Globals.h"
#include <vector>

class WindowManager
{
public:
    struct WindowResolution
    {
        int width;
        int height;
        float zoomFactor;

        WindowResolution(int w, int h, float zoom)
            : width(w), height(h), zoomFactor(zoom)
        {
        }
    };

    std::vector<WindowResolution> resolutions = { // TODO: not being used
        WindowResolution(640, 360, 0.5f),
        WindowResolution(854, 480, 0.67f),
        WindowResolution(1024, 576, 0.8f),
        WindowResolution(1152, 648, 0.9f),
        WindowResolution(1280, 720, 1.0f), // 720p
        WindowResolution(1366, 768, 1.07f),
        WindowResolution(1600, 900, 1.25f),
        WindowResolution(1920, 1080, 1.5f),  // 1080p
        WindowResolution(2560, 1440, 2.0f),  // 1440p
        WindowResolution(3840, 2160, 3.0f),  // 4K
        WindowResolution(7680, 4320, 6.0f)}; // 8K

    WindowManager();
    void Update(Camera2D &camera);
    void ChangeWindowSize(int width, int height);
    void ChangeWindowScale(int scale);
    void Fullscreen(Camera2D &camera);
    void Unfullscreen(Camera2D &camera);

private:
    /* WindowManager::WindowManager(
    {
    }

    WindowManager::~WindowManager()
    {
    } */
};