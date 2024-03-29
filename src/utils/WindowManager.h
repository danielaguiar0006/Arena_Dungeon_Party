#pragma once

#include "raylib.h"
#include "Globals.h"
#include <vector>

// *Singleton class*
class WindowManager
{
public:
    struct WindowResolution
    {
        int width;
        int height;

        WindowResolution(int w, int h)
            : width(w), height(h)
        {
        }
        bool operator==(const WindowResolution &other) const
        {
            return width == other.width && height == other.height;
        }
    };

    std::vector<WindowResolution> resolutions16x9 = {
        WindowResolution(640, 360),   // 0.5f
        WindowResolution(854, 480),   // 0.67f
        WindowResolution(1024, 576),  // 0.8f
        WindowResolution(1152, 648),  // 0.9f
        WindowResolution(1280, 720),  // 1.0f (720p)
        WindowResolution(1366, 768),  // 1.07f
        WindowResolution(1600, 900),  // 1.25f
        WindowResolution(1920, 1080), // 1.5f (1080p)
        WindowResolution(2560, 1440), // 2.0f (1440p)
        WindowResolution(3840, 2160), // 3.0f (4K)
        WindowResolution(7680, 4320)  // 6.0f (8K)
    };

    static WindowManager &GetInstance()
    {
        static WindowManager instance; // Guaranteed to be destroyed.
                                       // Instantiated on first use.
        return instance;
    }
    WindowManager(WindowManager const &) = delete;  // Don't Implement
    void operator=(WindowManager const &) = delete; // Don't implement

    void Update(Camera2D &camera);
    void ChangeWindowSize(WindowResolution resolution);
    void Fullscreen();
    void Unfullscreen();
    void CycleResolution();
    void CycleResolutionBackwards();

private:
    WindowManager() = default;
};
