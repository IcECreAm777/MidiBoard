#include "CustomImGuiWindow.h"

CustomImGuiWindow::CustomImGuiWindow(const std::string name, const GridCoords coords)
{
    this->name = name;
    this->coords = coords;
}

void CustomImGuiWindow::Draw()
{
    // set window size and position
    ImGui::SetNextWindowPos(ImVec2(posX, posY));
    ImGui::SetNextWindowSize(ImVec2(width, height));

    // return, when the window couldn't be created
    if(!ImGui::Begin(name.c_str(), nullptr, flags))
    {
        ImGui::End();
        return;
    }

    // Draw the elements of the child classes (or the hint to override this method)
    Draw_Internal();
    ImGui::End();
}

void CustomImGuiWindow::SetDimensions(const int horizontalPos, const int horizontalSize,
                                      const int verticalPos, const int verticalSize)
{
    posY = horizontalPos;
    height = horizontalSize;
    posX = verticalPos;
    width = verticalSize;
}

GridCoords CustomImGuiWindow::GetGridCoords()
{
    return coords;
}

void CustomImGuiWindow::Draw_Internal()
{
    ImGui::Text("No Draw Internal Method is overwritten. Please Overwrite it to display UI stuff");
}
