#include "GridManager.h"

#include "ConsoleWindow.h"
#include "SettingsWindow.h"
#include <math.h>

GridManager::GridManager()
{
    // construct needed imgui windows
    const auto console = new ConsoleWindow("Console", GridCoords(1,0, 1, 2));
    const auto settings = new SettingsWindow("Settings", GridCoords(0, 1));

    // adds them to the collection 
    windows = {console, settings};
    
    // each entry in these array represent a row/ column and their portion of the screen (will be clamped if necessary)
    float rows [] = {2, 1};
    float cols [] = {1, 1};

    // getting whole portion of the claimed width
    float wholePortion = 0.f;
    for(float f : rows)
    {
        wholePortion += f;
    }

    // clamp it between 0 and 1 when the whole claimed screen size is bigger than 1
    float modifier = wholePortion > 1.f ? wholePortion : 1.f;
    for (float f : rows)
    {
        rowPortions.push_back(f / modifier);
    }

    // getting whole portion of the claimed width
    wholePortion = 0.f;
    for(float f : cols)
    {
        wholePortion += f;
    }

    // clamp it between 0 and 1 when the whole claimed screen size is bigger than 1
    modifier = wholePortion > 1.f ? wholePortion : 1.f;
    for (float f : cols)
    {
        colPortions.push_back(f / modifier);
    }
}

void GridManager::RecalculateWindowsSize(const int width, const int height)
{
    // vector for saving the actual sizes of the rows and columns
    std::vector<int> rowSizes (rowPortions.size());
    std::vector<int> colSizes (colPortions.size());

    // calculate actual height of a row
    for (int i = 0; i < rowPortions.size(); i++)
    {
        rowSizes[i] = floor(height * rowPortions[i]);
    }

    // calculate actual width of a col
    for(int i = 0; i < colPortions.size(); i++)
    {
        colSizes[i] = floor(width * colPortions[i]);
    }

    // calculate position and sizes for every window based on the grid position
    for (auto w : windows)
    {
        // get coordinates and set it to the last available coordinate, if the coordinates of the window are too high
        const GridCoords coords = w->GetGridCoords();
        const int row = coords.Row < rowSizes.size() ? coords.Row : rowSizes.size()-1;
        const int col = coords.Col < colSizes.size() ? coords.Col : colSizes.size()-1;

        // get the vertical position 
        int rowPos = 0;
        for(int i = 0; i < row; i++)
        {
            rowPos += rowSizes[i];
        }

        // gets the vertical size
        int rowSize = 0;
        for (int i = row; i < row + coords.RowSpan && i < rowSizes.size(); i++)
        {
            rowSize += rowSizes[i];
        }

        // get the horizontal position 
        int colPos = 0;
        for(int i = 0; i < col; i++)
        {
            colPos += colSizes[i];
        }

        // gets the horizontal size
        int colSize = 0;
        for (int i = col; i < col + coords.ColSpan && i < colSizes.size(); i++)
        {
            colSize += colSizes[i];
        }

        w->SetDimensions(rowPos, rowSize, colPos, colSize);
    }
}

void GridManager::DrawWindows()
{
    for (auto w : windows)
    {
        w->Draw();
    }
}
