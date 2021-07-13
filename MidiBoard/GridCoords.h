#pragma once

struct GridCoords
{
    GridCoords() {}
    GridCoords(const int row, const int col, int rowSpan = 1, int colSpan = 1)
    {
        Row = row;
        Col = col;
        RowSpan = rowSpan;
        ColSpan = colSpan;
    }
    
    int Row = 0;
    int Col = 0;
    int RowSpan = 0;
    int ColSpan = 0;
};
