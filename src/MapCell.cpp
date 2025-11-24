#include "MapCell.h"

MapCell::MapCell()
{
        id=0;
}

bool MapCell::IsBlocked()const
{
        if (id == '1')
        {
                return true;
        }
        else
        {
                return false;
        }
}
