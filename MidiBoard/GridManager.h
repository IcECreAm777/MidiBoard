#pragma once
#include <vector>
#include <vector>

#include "CustomImGuiWindow.h"

class GridManager
{
public:
    GridManager();

    /**
     * Recalculates the size of the imgui windows based on the width and size of the main window
     * @param width the width of the glfw window
     * @param height the height of the glfw window
     */
    void RecalculateWindowsSize(int width, int height);

    /**
     * Draws the im gui windows based on the calculated properties
     */
    void DrawWindows();

private:
    std::vector<CustomImGuiWindow*> windows;
    std::vector<float> rowPortions;
    std::vector<float> colPortions;
};
