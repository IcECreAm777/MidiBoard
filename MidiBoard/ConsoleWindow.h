#pragma once

#include "CustomImGuiWindow.h"

class ConsoleWindow final : public CustomImGuiWindow
{
public:
    ConsoleWindow(const std::string name, const GridCoords coords)
        : CustomImGuiWindow(name, coords)
    {
    }

    void Draw_Internal() override;
};
