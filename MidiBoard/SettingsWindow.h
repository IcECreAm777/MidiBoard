#pragma once
#include "CustomImGuiWindow.h"

class SettingsWindow : public CustomImGuiWindow
{
public:
    SettingsWindow(const std::string& name, const GridCoords coords)
        : CustomImGuiWindow(name, coords)
    {
    }
};
