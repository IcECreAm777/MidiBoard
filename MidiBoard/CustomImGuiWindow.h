#pragma once
#include <string>

#include "GridCoords.h"
#include "External/imgui/imgui.h"

// Base class for a ImGuiWindow
class CustomImGuiWindow
{
public:
    /**
     * Constructor for the CustomImGuiWindow
     * @param name The name of the window (will be displayed in the UI)
     * @param coords The grid coordinates of this window
     */
    CustomImGuiWindow(std::string name, GridCoords coords);
    virtual ~CustomImGuiWindow() = default;

    /**
     * Draws the actual content of the window
     */
    void Draw();

    /**
     * Sets the size and the drawing position for this window
     * @param horizontalPos The horizontal position of the top left corner
     * @param horizontalSize The width of this window
     * @param verticalPos The vertical position of the top left corner
     * @param verticalSize The height of this window
     */
    void SetDimensions(int horizontalPos, int horizontalSize, int verticalPos, int verticalSize);

    GridCoords GetGridCoords();

protected:
    virtual void Draw_Internal();

private:
    const ImGuiWindowFlags flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse;
    GridCoords coords;
    std::string name;

    int posX = 0;
    int posY = 0;
    int width = 0;
    int height = 0;
};
