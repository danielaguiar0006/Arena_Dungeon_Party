#include "WindowManager.h"

WindowManager::WindowManager()
{
    /*     InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "raylib [core] example - basic window");
        SetTargetFPS(60); */
    /*     windowWidth = WINDOW_WIDTH;
        windowHeight = WINDOW_HEIGHT; */
}

void WindowManager::ChangeWindowSize(int width, int height)
{
    WINDOW_WIDTH = width;
    WINDOW_HEIGHT = height;
}

void WindowManager::Fullscreen(Camera2D &camera) // Note: Borderless
{
    CAMERA_ZOOM_FACTOR = 1.5f;
    WINDOW_HEIGHT = GetMonitorHeight(GetCurrentMonitor());
    WINDOW_WIDTH = GetMonitorWidth(GetCurrentMonitor());
    SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    ToggleBorderlessWindowed();
}